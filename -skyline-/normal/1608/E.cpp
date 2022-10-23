#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
#pragma GCC optimize("Ofast")
using namespace std;
int n,x[100005],y[100005],z[100005],ans;
int Y[100005],m;
int c1[100005],c2[100005],c3[100005];
pair<int,int> p[100005];
void sol3(){
	for(int i=0;i<=m+1;++i)c1[i]=c2[i]=c3[i]=0;
	c2[m+1]=c3[m+1]=orz;
	for(int i=1;i<=n;++i){
		if(z[i]==2)++c2[Y[i]];
		else if(z[i]==3)++c3[Y[i]];
		else ++c1[Y[i]];
	}
	for(int i=1;i<=m;++i)c1[i]+=c1[i-1],c2[i]+=c2[i-1],c3[i]+=c3[i-1];
	int l2=0,l3=0;
	for(int i=1;i<=m;++i){
		for(int j=c1[i-1];j<=c1[i];++j){
			while(c2[l2]-c2[i]<j)++l2;
			while(c3[l3]-c3[i]<j)++l3;
			if(n/3-c2[l3]>=j||n/3-c3[l2]>=j)ans=max(ans,j);
		}
	}
}
void sol2(){
	sol3();
	c2[0]=c3[0]=c2[m+1]=c3[m+1]=orz;
	for(int i=1;i<=m;++i)c2[i]=c3[i]=0;
	for(int i=1;i<=n;++i){
		if(z[i]==2)++c2[Y[i]];
		else if(z[i]==3)++c3[Y[i]];
	}
	int u2=m+1,U2=0,u3=m+1,U3=0;
	int d2=0,D2=0,d3=0,D3=0;
	int res=0;
	for(int i=1;i<=n;++i){
		int _=i;
		while(_<n&&p[_+1].first==p[_].first)++_;
		int cnt=0;
		for(int j=i;j<=_;++j){
			int x=p[j].second;
			if(z[x]==1)++cnt;
			else if(z[x]==2){
				if(Y[x]>=u2)--U2;
				if(Y[x]<=d2)--D2;
				--c2[Y[x]];
			}
			else{
				if(Y[x]>=u3)--U3;
				if(Y[x]<=d3)--D3;
				--c3[Y[x]];
			}
		}
		for(int j=0;j<=cnt;++j){
			if(j)++res;
			while(U2<res)--u2,U2+=c2[u2];
			while(D2<res)++d2,D2+=c2[d2];
			while(U3<res)--u3,U3+=c3[u3];
			while(D3<res)++d3,D3+=c3[d3];
			if(u2>d3||u3>d2)ans=max(ans,res);
			else{
				return;
			}
		}
		i=_;
	}
}
void sol(){
	m=0;
	for(int i=1;i<=n;++i)p[i]=mp(y[i],i);
	sort(p+1,p+n+1);
	p[0].first=-orz;
	for(int i=1;i<=n;++i){
		if(p[i].first!=p[i-1].first)++m;
		Y[p[i].second]=m;
	}
	for(int i=1;i<=n;++i)p[i]=mp(x[i],i);
	sort(p+1,p+n+1);
	sol2();
	for(int i=1;i<=n;++i)z[i]=z[i]%3+1;
	sol2();
	for(int i=1;i<=n;++i)z[i]=z[i]%3+1;
	sol2();
}
void rot(){
	for(int i=1;i<=n;++i){
		int X=y[i],Y=-x[i];
		x[i]=X,y[i]=Y;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d%d",x+i,y+i,z+i);
	sol();
	rot();
	sol();
	rot();
	sol();
	rot();
	sol();
	printf("%d\n",ans*3);
    return 0;
}