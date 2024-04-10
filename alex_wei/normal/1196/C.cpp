#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
const ll M = 1e5;
ll q,n,x[100002],y[100002];
int main()
{
	q=read();
	for(int k=0;k<q;k++){
		n=read();
		ll u=M,d=-M,l=-M,r=M,t,pd=1;
		for(int i=0;i<n;i++){
			x[i]=read(),y[i]=read();
			t=read();
			if(!t){
				if(u<x[i])pd=0;
				d=max(d,x[i]);
			}
			t=read();
			if(!t){
				if(l>y[i])pd=0;
				r=min(r,y[i]);
			}
			t=read();
			if(!t){
				if(d>x[i])pd=0;
				u=min(u,x[i]);
			}
			t=read();
			if(!t){
				if(r<y[i])pd=0;
				l=max(l,y[i]);
			}
		} 
		if(pd&&u>=d&&l<=r)
			cout<<"1 "<<u<<" "<<r<<"\n";
		else cout<<"0\n";
	}
	return 0;
}