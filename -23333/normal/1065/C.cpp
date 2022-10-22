#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+2345;
int s[N],t[N];
ll ans,ax;
ll k,n,maxer,miner;
int main(){
	miner=N;
	//freopen("p.in","r",stdin);
	//freopen("p.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	ll a;
	cin>>a;
	t[a]++;
	maxer=max(maxer,a);
	miner=min(miner,a);
	}
	for(int i=1;i<=maxer;i++)
	s[i]=t[i]+s[i-1];
	int az=maxer;
	while(az>=miner){
	ans+=s[maxer]-s[az];
	if(ans>k){ax++;ans=0;}
	else {
	if(ans>0&&az==miner){ax++;}
	az--;}
	}
	cout<<ax;
	return 0;
}