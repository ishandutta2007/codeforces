#include<bits/stdc++.h>
using namespace std;
#define ll __int128
ll a,b,c,d;
long long aa,bb,cc,dd;
ll calc(ll x){
	//cout<<x<<'\n';
	ll r=a*x,w=(d*x-c)/d;
//	cout<<w<<'\n';
	if(w<0)w=0;
	r-=w*b*c;
	w=x-w-1;
	r-=b*d*(1+w)*w/2;
	//cout<<r<<'\n';
	return r;
}
int main(){
	int T,i,j,k;
	ll l,r,m;
	cin>>T;
	while(T--){
		cin>>aa>>bb>>cc>>dd;
		a=aa,b=bb,c=cc,d=dd;
		if(b*c<a){puts("-1");continue;}
		l=1,r=1e7;
		while(l<=r){
			m=l+r>>1;
			if(calc(m)<calc(m+1))l=m+1;
			else r=m-1;
		}
		cout<<(long long)calc(l)<<'\n';
	//	return 0;
	}
	return 0;
}
/*
a*k
-b*(min(c+d*1,d*k)-d*1)
-b*(min(c+d*2,d*k)-d*2)
if(c+d*i<d*k)j=c
else j=d*k-d*i
*/