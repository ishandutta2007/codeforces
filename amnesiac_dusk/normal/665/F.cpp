/*
 * 	The way if it's all predetermined
 * 		And the way i should go all my life
 * 			I swear to go wherever will be
 * 				'Cause there'll be something to see and to find
 * 	I don't know the meaning of life
 * 		But i know what's truly precious
 * 			The way it's leading me to be in love
 * 				No fear i can find me always in my heart
 * 	The life it's not for comparing things
 * 		So i hold both of light and shadow
 * 			The rays of stars will bring me to you
 * 				Throught the dark night skies
 * 					See the way to be shined
 * 	I dont know what's right for our lives
 * 		But i know the truth of my love
 * 			The way it feels our breaths at the wind
 * 				And the way i should go all my life
 * 					I swear to go wherever will be
 * 						Thus the grace i wouldn't have
 * 							Will always in my heart
 * 								Thus the grace i wouldn't have
 * 									Will always in my heart
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef rd
#define endl '\n'
#endif
#ifdef rd
#define trace(...) cout<<"Line:"<<__LINE__<<" "; __f(#__VA_ARGS__, __VA_ARGS__)
template<typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma=strchr(names+1,',');
	cout.write(names,comma-names)<<" : "<<arg1<<" | ";
	__f(comma+1,args...);
}
#else
#define trace(...)
#endif
#define deb cout<<"Line: "<<__LINE__<<" plz "
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=490019;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int MAX_N=2.2e7+2;
vector<bool> np(MAX_N,0);
int prime[MAX_N],pi[MAX_N];
int getprime() {
	int cnt=0;
	np[0]=np[1]=true;
	pi[0]=pi[1]=0;
	for(int i=2; i<MAX_N; ++i) {
		if(!np[i])
			prime[++cnt]=i;
		pi[i]=cnt;
		for(int j=1; j<=cnt&&i*prime[j]<MAX_N; ++j) {
			np[i*prime[j]]=true;
			if(i%prime[j]==0)
				break;
		}
	}
	return cnt;
}
const int M=7;
const int PM=2*3*5*7*11*13*17;
int phi[PM+1][M+1],sz[M+1];
void init() {
	getprime();
	sz[0]=1;
	for(int i=0; i<=PM; ++i)
		phi[i][0]=i;
	for(int i=1; i<=M; ++i) {
		sz[i]=prime[i]*sz[i-1];
		for(int j=1; j<=PM; ++j)
			phi[j][i]=phi[j][i-1]-phi[j/prime[i]][i-1];
	}
}
int sqrt2(ll x) {
	ll r=(ll)sqrt(x-0.1);
	while(r*r<=x)
		++r;
	return r-1;
}
int sqrt3(ll x) {
	ll r=(ll)cbrt(x-0.1);
	while(r*r*r<=x)
		++r;
	return r-1;
}
ll getphi(ll x, int s) {
	if(s==0)
		return x;
	if(s<=M)
		return phi[x%sz[s]][s]+(x/sz[s])*phi[sz[s]][s];
	if(x<=prime[s]*prime[s])
		return pi[x]-s+1;
	if(x<=prime[s]*prime[s]*prime[s]&&x<MAX_N) {
		int s2x=pi[sqrt2(x)];
		ll ans=pi[x]-(s2x+s-2)*(s2x-s+1)/2;
		for(int i=s+1; i<=s2x; ++i)
			ans+=pi[x/prime[i]];
		return ans;
	}
	return getphi(x,s-1)-getphi(x/prime[s],s-1);
}
ll getpi(ll x) {
	if(x<MAX_N)
		return pi[x];
	ll ans=getphi(x,pi[sqrt3(x)])+pi[sqrt3(x)]-1;
	for(int i=pi[sqrt3(x)]+1,ed=pi[sqrt2(x)]; i<=ed; ++i)
		ans-=getpi(x/prime[i])-i+1;
	return ans;
}
ll lehmer_pi(ll x) {
	if(x<MAX_N)
		return pi[x];
	int a=(int)lehmer_pi(sqrt2(sqrt2(x)));
	int b=(int)lehmer_pi(sqrt2(x));
	int c=(int)lehmer_pi(sqrt3(x));
	ll sum=getphi(x,a)+(ll)(b+a-2)*(b-a+1)/2;
	for(int i=a+1; i<=b; i++) {
		ll w=x/prime[i];
		sum-=lehmer_pi(w);
		if(i>c)
			continue;
		ll lim=lehmer_pi(sqrt2(w));
		for(int j=i; j<=lim; j++)
			sum-=lehmer_pi(w/prime[j])-(j-1);
	}
	return sum;
}

void solve() {
	int n;
	init();
	cin>>n;
	int ans=0;
	for(int i=2; i*i<=n; i++) {
		if(pi[i]!=pi[i-1]) {
			trace(lehmer_pi(n/i),n/i,i);
			ans+=lehmer_pi(n/i)-lehmer_pi(i);
		}
	}
	trace(ans);
	for(int i=2; i*i*i<=n; i++)
		if(pi[i]!=pi[i-1])
			ans++;
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cerr<<endl<<endl<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}