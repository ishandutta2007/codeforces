#include<bits/stdc++.h>
using namespace std;
long long v[105];
int vv[105];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&v[i]);
	long long F=0,S=0;
	for(int h=2;h<=m+m;++h){
		for(int i=1;i<=n;++i)vv[i]=v[i]%h;
		sort(vv+1,vv+n+1);
		int L=(vv[n-1]+2)/2,R=vv[n]/2;
		for(int i=n-2;i>=1;i-=2){
			int LL=L,RR=R;
			LL=max(LL,vv[i-1]+1);
			LL=max(LL,h-vv[i]);
			LL=max(LL,h-m);
			LL=max(LL,(h+2)/3);
			if(LL<=RR)F+=2*(RR-LL+1);
		}
		int LL=L,RR=R;
		LL=max(LL,vv[n-1]+1);
		LL=max(LL,h-m);
		LL=max(LL,(h+2)/3);
		if(LL<=RR)F+=2*(RR-LL+1);
		L=(vv[n]+2)/2,R=h/2;
		for(int i=n;i>=1;i-=2){
			int LL=L,RR=R;
			LL=max(LL,vv[i-1]+1);
			LL=max(LL,h-vv[i]);
			LL=max(LL,h-m);
			LL=max(LL,(h+2)/3);
			if(LL<=RR)F+=2*(RR-LL+1);
		}
		LL=1,RR=(h-1)/3;
		LL=max(LL,h-m);
		LL=max(LL,h-vv[n]);
		LL=max(LL,vv[n-1]+1);
		if(LL<=RR)F+=2*(RR-LL+1);
		if(h%2==0){
			int a=h/2;
			int A=0;
			for(int i=1;i<=n;++i){
				if(vv[i]>=a)++A;
			}
			if(A%2==1)--F;
		}
		L=(vv[n]+2)/2,R=h/2;
		for(int i=n-1;i>=1;i-=2){
			int LL=L,RR=R;
			LL=max(LL,vv[i-1]+1);
			LL=max(LL,h-vv[i]);
			LL=max(LL,h-m);
			if(LL<=RR)S+=2*(RR-LL+1);
		}
		L=vv[n]+1,R=h/2;
		L=max(L,h-m);
		if(L<=R)S+=2*(R-L+1);
		if(h%2==0){
			int a=h/2;
			int A=0;
			for(int i=1;i<=n;++i){
				if(vv[i]>=a)++A;
			}
			if(A%2==0)--S;
		}
	}
	long long xx=1ll*m*m-F-S;
	cout<<xx/2<<" "<<xx/2<<" ";
	cout<<F<<" "<<S<<endl;
	return 0;
}