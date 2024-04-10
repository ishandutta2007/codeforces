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

int n,m,arr[70][70];
lli cache[70][70];
char str[3];

int get(char *str) {
	if(!strcmp(str,"=")) return 1;
	else if(!strcmp(str,"<")) return 2;
	else if(!strcmp(str,"<=")) return 3;
	else if(!strcmp(str,">")) return 4;
	else return 5;
}
int rev(int val) {
	if(val==0) return 0;
	else if(val==1) return 1;
	else if(val==2) return 4;
	else if(val==3) return 5;
	else if(val==4) return 2;
	else return 3;
}
bool gt(int a,int b) {
	return arr[a][b]==0 || arr[a][b]==2 || arr[a][b]==3;
}
bool eq(int a,int b) {
	return arr[a][b]==0 || arr[a][b]==1 || arr[a][b]==3 || arr[a][b]==5;
}

lli DP(int l,int r) {
	if(l>r) return 1;

	lli &ret=cache[l][r];
	if(ret!=-1) return ret;

	ret = 0;
	if(eq(l,l+1)) {
		int f=1;
		for(int i=l+2;i<=r;i++) if(!gt(l,i) || !gt(l+1,i)) {
			f=0;
			break;
		}
		if(f) ret += DP(l+2,r);
	}
	if(eq(l,r) && r-l+1!=2) {
		int f=1;
		for(int i=l+1;i<r;i++) if(!gt(l,i) || !gt(r,i)) {
			f=0;
			break;
		}
		if(f) ret += DP(l+1,r-1);
	}
	if(eq(r,r-1) && r-l+1!=2) {
		int f=1;
		for(int i=l;i<=r-2;i++) if(!gt(r-1,i) || !gt(r,i)) {
			f=0;
			break;
		}
		if(f) ret += DP(l,r-2);
	}
	return ret;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d %s %d",&a,str,&b);
		a--; b--;
		arr[a][b] = get(str);
		arr[b][a] = rev(arr[a][b]);
	}

	memset(cache,-1,sizeof(cache));
	printf("%lld\n",DP(0,2*n-1));

	return 0;
}