#include <bits/stdc++.h>
/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
*/
#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define IOS ios_base::sync_with_stdio(0);

using namespace std;                    

const int maxn=1.1e6+123,inf=1e9,N=1e5+123,mod=1e9+7;
ll M=2e16;
bool was[N][10];
ll dp[N][10];

void calc(ll l,int q);

ll get(ll l,int q){
	ll x=0;
	if(l>1e5)
		x=l-1e5,l=1e5;
	calc(l,q);
	return min((ll)1e18,dp[l][q]+x);			
}
void calc(ll l,int q){
	if( was[l][q] )
		return ;
	was[l][q]=1;
	if(q==1){
		dp[l][q]=l+min((ll)1e4,l)-1;
		return;
	}

	ll r=l;
	for(int i=0;i<1e4 && i<l && r<1e18;i++)
		r=get(r,q-1)+2;
	dp[l][q]=get(r,q-1);
}

void solve(ll l,int q){
	if(q==1){
		cout<<min(10000ll,l)<<" ";
		for(ll i=l;i<l+min(10000ll,l);i++)
			cout<<i<<" ";
		exit(0);
	}
	vector<ll> v;
	ll cur=l,ans;
	for(int i=0;i<1e4 && i<l && cur<M;i++){
		cur=get(cur,q-1)+1;
		v.pb(cur);
		cur++;
	}
	cout<<v.size()<<" ";
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	cout.flush();
	cin>>ans;
	if(ans==-1)
		exit(0);
	if(ans==0)
		solve(l,q-1);
	else
		solve(v[ans-1]+1,q-1);
}
int main(){              
	solve(1,5);  
}