#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct vec {
	lli x,y;
	vec() {}
	vec(lli x,lli y):x(x),y(y){}
	vec operator-(const vec&rhs)const {
		return vec(x-rhs.x, y-rhs.y);
	}
	lli dot(const vec &rhs)const {
		return x*rhs.x + y*rhs.y;
	}
}arr[5000];
int n,chk[5000];
int ans[5000];

bool dfs(int t) {
	if(t == n) return true;
	for(int i=0;i<n;i++) if(!chk[i]) {
		if( (arr[ans[t-2]] - arr[ans[t-1]]).dot(arr[i] - arr[ans[t-1]]) > 0 ){
			ans[t] = i;
			chk[i] = 1;
			if(dfs(t+1)) return true;
			chk[i] = 0;
		}
	}
	return false;
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld%lld",&arr[i].x,&arr[i].y);

	ans[0] = 0;
	chk[0] = 1;
	for(int i=1;i<n;i++) {
		chk[i] = 1;
		ans[1] = i;
		if(dfs(2)) break;
		chk[i] = 0;
	}
	
	for(int i=0;i<n;i++) printf("%d ",ans[i] + 1);
	
	return 0;
}