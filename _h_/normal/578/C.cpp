#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
typedef long double db;
const db inf = 1e20, eps = 1e-13;
const int mxn = 2e5+10, mxa = 1e4+3;

int main(){
	int n, S[mxn];
	scanf("%d",&n);
	S[0] = 0;
	rep(i,0,n){
		scanf("%d",&S[i+1]);
		S[i+1] += S[i];
	}
	db a = -mxa, b = mxa, ans = -1;
	while(b - a > eps){
		db m = (b+a)/2;
		db mx = -inf, mn = inf;
		int xi = -1, ni = -1;
		rep(i,0,n+1){
			db x = i*m - S[i];
			if(x > mx){
				mx = x;
				xi = i;
			}
			if(x < mn){
				mn = x;
				ni = i;
			}
		}
		if(xi < ni)
			swap(xi,ni);
		ans = S[xi] - S[ni] - (xi-ni)*m;
		if(ans > 0)
			a = m;
		else
			b = m;
	}
	printf("%.8lf\n",(double)abs(ans));
}