#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <stack>
#include <cstring>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <ctype.h>

#define fi first
#define se second
#define sz(x) ((int)x.size())

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n,m;
char s[200100],t[200100];

int main() {
	scanf("%d%d%s%s",&n,&m,s,t);

	for(int i=0,j=0;i<n && j<m;i++,j++) {
		if(s[i]=='*') break;
		if(s[i]!=t[j]) {
			puts("NO");
			return 0;
		}
	}
	for(int i=n-1,j=m-1;i>=0 && j>=0;i--,j--) {
		if(s[i]=='*') break;
		if(s[i]!=t[j]) {
			puts("NO");
			return 0;
		}
	}

	int f=0;
	for(int i=0;i<n;i++) if(s[i]=='*') {
		f=1;
		break;
	}
	if((f==1 && n<=m+1) || (f==0 && n==m)) puts("YES");
	else puts("NO");

	return 0;
}