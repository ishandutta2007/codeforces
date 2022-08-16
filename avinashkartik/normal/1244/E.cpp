#include<bits/stdc++.h>
 
using namespace std;
 
#define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define foo(i,a,n) for(ll i = (a); i <= n; i++)
#define frr(i,a,n) for(ll i = (a); i >= n; i--)
#define fr(i,n) for(ll i = n-1; i >= 0; i--)
#define fo(i,n) for(ll i = 0; i < n; i++)
#define newl cout<<"\n"
#define pb push_back
#define mp make_pair
#define s second
#define f first
 
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef unordered_map<ll,ll> um;
typedef vector<pll> vpll;
 
const ll MOD=1e+9+7;
const ll MAXN=1e+5+7;
const ll INF=1e+18;
 
//<<-----Declare Variable Here------->>//
ll n, k, a[MAXN];
um m;
vpll aa;
vll res;
//<<-----Implement Functions Here---->>//
 
 
//<<-----Start of Main--------------->>//
 
int main(){
	fastio;
 
	cin>>n>>k;
	fo(i,n)cin>>a[i],m[a[i]]++;
	
	//fo(i,n)cout<<a[i]<<" ";newl;
	
	for(auto it: m)aa.pb(mp(it.f,it.s));
	sort(aa.begin(),aa.end());
	//for(auto it: aa){	cout<<it.f<<"-"<<it.s;newl;}
 
	ll lp=0; ll rp=aa.size()-1; ll f=1;
 
	while(lp!=rp){
		ll num1,num2,cnt1=aa[lp].s,cnt2=aa[rp].s;
		if(cnt1<=cnt2){
			num1=aa[lp].f;num2=aa[lp+1].f;
			cnt1=aa[lp].s;cnt2=aa[lp+1].s;
 
			if(k/(num2-num1)>=cnt1){
				k-=cnt1*(num2-num1);
				//aa[lp].f=aa[lp+1].f;
				aa[lp+1].s+=cnt1;
				aa[lp].s=0;
				lp++;
			}
			else{
				if(!cnt1)break;
				ll r=k/cnt1;
				if(r)aa[lp].f+=r;
				break;
			}
		}
		else{
			num1=aa[rp].f;num2=aa[rp-1].f;
			cnt1=aa[rp].s;cnt2=aa[rp-1].s;
			if(k/(num1-num2)>=cnt1){
				k-=cnt1*(num1-num2);
				//aa[lp].f=aa[lp+1].f;
				aa[rp-1].s+=cnt1;
				aa[rp].s=0;
				rp--;
			}
			else{
				if(!cnt1)break;
				ll r=k/cnt1;
				if(r)aa[rp].f-=r;
				break;
			}
		}
		//cout<<k;newl;
 
	}
	//for(auto it: aa){	cout<<it.f<<"-"<<it.s;newl;}
	for(auto it: aa) if(it.s)res.pb(it.f);
	cout<<res[res.size()-1]-res[0];
	
 
}