/*
 * 	In an empty-like sky
 * 		What were you looking at?
 * 			I did not even understand
 * 				The reason I woke up
 * 	I was terribly scared
 * 		Of believing
 * 			Because of that
 * 				I've thrown everything away
 * 	It would have been better
 * 		If this world that I hate so much
 * 			Could just disappear
 * 				If I continue to believe
 * 					Won't it hurt me?
 *
 * 	It was your voice
 * 		That has saved me
 * 			And keeps me going
 * 				The feeling that you taught me
 * 					That's true.
 * 	I will scream your name
 * 		Strongly hold your hand
 * 			I will not let go of it anymore
 * 				No matter what the future holds
 * 					If you're with me, I won't run away
 */
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
//#define int long long
typedef long long ll;
#define double long double
//typedef long double f80;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
const ll infl=2e18;
const int infi=2e9;
const int mod=1e9+7;
typedef vector<int> vi;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
mt19937 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
auto clk=clock();
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
const int inf=1e9+9;
struct node{
    int cnt[2];
    node *pt[2];
    node(){
        for(int i = 0; i < 2; i++)
            cnt[i] = 0, pt[i] = NULL;
    }
};
struct trie_bits{
    node *tr, *cur;
    int bits;
    trie_bits(int b): bits(b) { tr = new node(); } // b -> number of bits
    void insert(int x){
        insert(tr, x, bits - 1);
    }
    void del(int x){
        del(tr, x, bits - 1);
    }
    bool insert(node *cur, int x, int b, bool find = 0){
        if(b == -1){
            return 1;
        }
        bool c = (x & (1 << b)) ? 1 : 0;
        if(cur -> pt[c] == NULL)
        	cur -> pt[c] = new node();
        cur -> cnt[c]++;
        bool f = insert(cur -> pt[c], x, b - 1, find);
        return f;
    }
    void del(node *cur, int x, int b){
        if(b == -1){
            return;
        }
        bool c = (x & (1 << b)) ? 1 : 0;
        cur -> cnt[c]--;
        del(cur -> pt[c], x, b - 1);
    }
    int max_xor(int x){
        return max_xor(tr, x, bits - 1);
    }
    int max_xor(node *cur, int x,int b){
        if(b == -1)
            return 0;
        bool c = (x & (1 << b)) ? 1 : 0;
        c ^= 1;
        if(cur -> cnt[c])
            return (1 << b) + max_xor(cur -> pt[c], x, b - 1);
        else
            return max_xor(cur -> pt[(c ^ 1)], x, b - 1);
    }
};
trie_bits hola(30);
int revers=(1<<30)-1;
ll recursivesolver(vi a, int bit) {
	if(sz(a)==0||bit<0)
		return 0;
	vi b,c;
	for(int i:a)
		if(i&(1<<bit))
			b.pb(i^(1<<bit));
		else
			c.pb(i);
	if(sz(b)&&sz(c)) {
		int ans=infi;
		if(sz(b)<30||sz(c)<30) {
			for(int i:b)
				for(int j:c)
					ans=min(ans,i^j);
		}
		else {
			for(int i:b)
				hola.insert(i);
			for(int i:c)
				ans=min(ans,revers^hola.max_xor(i^revers));
			for(int i:b)
				hola.del(i);
		}
		return (1LL<<bit)+ans+recursivesolver(b, bit-1)+recursivesolver(c, bit-1);
	}
	else
		return recursivesolver(b, bit-1)+recursivesolver(c, bit-1);
}
void solve() {
	int n,te;
	cin>>n;
	vi a;
	fr(i,1,n) {
		cin>>te;
		a.pb(te);
	}
	cout<<recursivesolver(a,29);
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