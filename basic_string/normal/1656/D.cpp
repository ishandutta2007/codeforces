#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int T,i,j,k;
	ll n;
	for(cin>>T;T--;){
		cin>>n;
		if(n%2==1){
			if(n==1)cout<<-1<<'\n';
			else cout<<2<<'\n';
			continue;
		}
		n*=2;
		ll m=n,o=1,p;
		while(m%2==0)m/=2,o*=2;
		p=n/o;
		if(o<p)cout<<o<<'\n';
		else if(p>1)cout<<p<<'\n';
		else cout<<-1<<'\n';
	}
}/*
n*2=(1+k+2x)*k x>=0
(1+k)*k/2+xk
4*(5+2x)=n*2*/