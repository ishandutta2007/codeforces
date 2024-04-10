#include<bits/stdc++.h>
using namespace std;
int qp(int a,int b,int p){int r=1;for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;return r;}
int n,x,p,a[15],t;
void fac(int x){
	int i=2;
	for(t=0;i*i<=x;++i)if(x%i==0){
		a[++t]=i;
		do x/=i;while(x%i==0);
	}
	if(x>1)a[++t]=x;
}
bool chk(int x){
	for(int i=1;i<=t;++i)if(qp(x,n/a[i],p)==1)return 0;
	return 1;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>x,p=n+1,fac(p);
	if(t>1)cout<<-1,exit(0);
	fac(n);
	for(int i=x-1;i>1;--i)if(chk(i))cout<<i,exit(0);
	cout<<-1;
	return 0;
}