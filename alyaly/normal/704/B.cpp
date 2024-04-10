#include<bits/stdc++.h>
#include<vector>
#define int long long
#define N 5000
#define inf 999999999999
using namespace std;
int n,st,fi,x[N+1],a[N+1],b[N+1],c[N+1],d[N+1];
vector<int>ve;
void putin(){
	
	cin>>n>>st>>fi;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)cin>>d[i];
}
int cw(int p,int q){
	if(x[p]<x[q])return x[q]-x[p]+d[p]+a[q];
	else return x[p]-x[q]+c[p]+b[q];
}
void cal0(){
	ve.push_back(st),ve.push_back(fi);
	for(int i=1;i<=n;i++){
		if(i==st||i==fi)continue;
		int gans=0;vector<int>::iterator nans;
		for(vector<int>::iterator j=ve.begin(),nj;j!=ve.end();nj=j,j++){
			if(j==ve.begin())continue;
			if(!gans||cw(*nj,i)+cw(i,*j)-cw(*nj,*j)<gans)gans=cw(*nj,i)+cw(i,*j)-cw(*nj,*j),nans=j;
		}
		ve.insert(nans,i);
	}
	int ans=0;
	for(int i=1;i<ve.size();i++)ans+=cw(ve[i-1],ve[i]);
	cout<<ans<<endl;
}
signed main(){
	putin();
	cal0();
	return 0;
}