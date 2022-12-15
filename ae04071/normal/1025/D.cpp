#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;

typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,arr[700],t[700][700],cache[700][700][2];

int dfs(int l,int r,int c) {
	if(l>r) return 1;
	int &ret=cache[l][r][c];
	if(ret!=-1) return ret;

	ret = 0;
	int idx=(c==0 ? r+1 : l-1);
	int fl=l>=idx,fr=r<=idx;
	for(int i=l;i<idx;i++) if(t[i][idx]>1) {
		fl |= dfs(l,i-1,0) & dfs(i+1,idx-1,1);
	}
	for(int i=idx+1;i<=r;i++) if(t[idx][i]>1) {
		fr |= dfs(idx+1,i-1,0) & dfs(i+1,r,1);
	}
	return ret = fl & fr;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",arr+i);

	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
		t[i][j] = __gcd(arr[i],arr[j]);

	int f=0;
	memset(cache,-1,sizeof(cache));
	for(int i=0;i<n;i++) f |= dfs(0,i-1,0) & dfs(i+1,n-1,1);
	puts(f ? "Yes" : "No");
	
	return 0;
}