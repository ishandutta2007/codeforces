#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
const ll mod = 998244353;
int T;
int n,k;
int a[N],b[N];
int vis[N];

int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			vis[i]=0;
		}
		for(int i=1;i<=k;++i){
			cin>>b[i];
			vis[b[i]]=i;
		}
		ll ans=1;
		bool flag=1;
		vis[0]=0;
		for(int i=1,r=1;i<=n;i=++r)
		if(vis[a[i]]){
			while(r<n&&vis[a[r+1]])++r;
			if(i>1&&r<n)ans=ans*2%mod;
		}
		a[0]=a[n+1]=0;
		vis[0]=1e9;
		for(int i=1;i<=n;++i)
		if(vis[a[i]]&&vis[a[i+1]]&&vis[a[i-1]]){
			if(vis[a[i]]<vis[a[i+1]]&&vis[a[i]]<vis[a[i-1]]){
				flag=0;
			}
		}
		if(flag)cout<<ans<<endl;
		else cout<<0<<endl;
	}
}