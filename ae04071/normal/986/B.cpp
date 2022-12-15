#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <iostream>
#include <ctype.h>

#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define ALL(x) x.begin(),x.end()

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,arr[1000001],vis[1000001];
int dfs(int cur) {
	if(vis[cur]) return 0;
	vis[cur]=1;
	return dfs(arr[cur])+1;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",arr+i);

	int sum=0;
	for(int i=1;i<=n;i++){
		if(!vis[arr[i]]) sum+=dfs(i)-1;
	}
	int a=3*n;
	a-=sum;
	if(a%2==0) puts("Petr");
	else puts("Um_nik");
	return 0;
}