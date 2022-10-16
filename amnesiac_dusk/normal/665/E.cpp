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

struct node {
	int cnt[2];
	node *pt[2];
	node() {
		for(int i=0; i<2; i++)
			cnt[i]=0,pt[i]= NULL;
	}
};
struct trie_bits {
	node *tr,*cur;int bits;
	trie_bits(int b) :
			bits(b) {
		tr=new node();
	} // b -> number of bits
	void insert(int x) {
		insert(tr,x,bits-1);
	}
	void insert(node *cur, int x, int b) {
		if(b==-1) {
			return;
		}
		bool c=(x&(1<<b))?1:0;
		if(cur->pt[c]==NULL)
			cur->pt[c]=new node();
		cur->cnt[c]++;
		insert(cur->pt[c],x,b-1);
	}
	int max_xor(node *cur, int x, int k, int b) {
		if(b==-1||cur==NULL)
			return 0;
		trace(b,cur->cnt[0],cur->cnt[1],x,k);
		bool c=(x&(1<<b))?1:0;
		c^=1;
		if(k==(1<<b)) {
			return cur->cnt[c];
		} else if(k<(1<<b)) {
			return cur->cnt[c]+max_xor(cur->pt[c^1],x,k,b-1);
		} else {
			return max_xor(cur->pt[c],x,k-(1<<b),b-1);
		}
	}
};

int a[1000005],pre[1000005];
trie_bits hola(30);
void solve() {
	int n,k;
	cin>>n>>k;
	hola.insert(0);
	int ans=0;
	fr(i,1,n) {
		trace(i);
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		int tem=hola.max_xor(hola.tr, pre[i], k, 29);
		ans+=tem;
		trace(tem);
		hola.insert(pre[i]);
	}
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