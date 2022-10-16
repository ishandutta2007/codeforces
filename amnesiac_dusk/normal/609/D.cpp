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
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,tune=native")
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
const int infi=1e9;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int a[200005],b[200005];
int ma[200005],mb[200005];
void solve() {
	int n,m,k,s,t,c;
	cin>>n>>m>>k>>s;
	a[0]=infl;
	b[0]=infl;
	fr(i,1,n)
	{
		cin>>a[i];
		if(a[i]>a[i-1]) {
			a[i]=a[i-1];
			ma[i]=ma[i-1];
		} else
			ma[i]=i;
	}
	fr(i,1,n)
	{
		cin>>b[i];
		if(b[i]>b[i-1]) {
			b[i]=b[i-1];
			mb[i]=mb[i-1];
		} else
			mb[i]=i;
	}
	vector<pii> dol, pou;
	fr(i,1,m) {
		cin>>t>>c;
		if(t==1)
			dol.pb({c,i});
		else
			pou.pb({c,i});
	}
	dol.pb({infi,infl});
	pou.pb({infi,infl});
	sort(all(dol));
	sort(all(pou));
	int lo=1,hi=n+1,mid=(lo+hi)/2;
	while(lo<hi) {
		int lol=0,i=0,j=0;
		while(i+j<k) {
			if(dol[i].fi*a[mid]<pou[j].fi*b[mid]) {
				lol+=dol[i].fi*a[mid];
				i++;
			} else {
				lol+=pou[j].fi*b[mid];
				j++;
			}
		}
		if(lol<=s) {
			hi=mid;
		} else
			lo=mid+1;
		mid=(lo+hi)/2;
	}
	if(mid==n+1)
		cout<<-1<<endl;
	else {
		cout<<lo<<endl;
		int lol=0,i=0,j=0;
		while(i+j<k) {
			if(dol[i].fi*a[mid]<pou[j].fi*b[mid]) {
				lol+=dol[i].fi*a[mid];
				cout<<dol[i].se<<" "<<ma[mid]<<endl;
				i++;
			} else {
				lol+=pou[j].fi*b[mid];
				cout<<pou[j].se<<" "<<mb[mid]<<endl;
				j++;
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
#ifdef rd
	cout<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}