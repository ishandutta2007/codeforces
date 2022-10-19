#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
vector<pair<int,int>>trie;
vector<int>ile;
void dodaj(int x) {
	int akt=0;
	for(int i=29; i>=0; --i) {
		if(x&(1<<i)) {
			if(trie[akt].nd==-1) {
				trie[akt].nd=trie.size();
				trie.pb({-1, -1});
				ile.pb(0);
			}
			akt=trie[akt].nd;
		} else {
			if(trie[akt].st==-1) {
				trie[akt].st=trie.size();
				trie.pb({-1, -1});
				ile.pb(0);
			}
			akt=trie[akt].st;
		}
		++ile[akt];
	}
}
void usun(int x) {
	int akt=0;
	for(int i=29; i>=0; --i) {
		if(x&(1<<i)) {
			akt=trie[akt].nd;
		} else {
			akt=trie[akt].st;
		}
		--ile[akt];
	}
}
int licz(int a, int b) {
	int ans=0, akt=0;
	for(int i=29; i>=0; --i) {
		if(b&(1<<i)) {
			if(a&(1<<i)) {
				if(trie[akt].nd!=-1) ans+=ile[trie[akt].nd];
			} else {
				if(trie[akt].st!=-1) ans+=ile[trie[akt].st];
			}
		}
		if(((a&(1<<i))^(b&(1<<i)))) {
			if(trie[akt].nd==-1) return ans;
			akt=trie[akt].nd;
		} else {
			if(trie[akt].st==-1) return ans;
			akt=trie[akt].st;
		}
	}
	ans+=ile[akt];
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	trie.pb({-1, -1});
	ile.pb(0);
	int q;
	cin >> q;
	while(q--) {
		int t;
		cin >> t;
		if(t==1) {
			int x;
			cin >> x;
			dodaj(x);
		} else if(t==2) {
			int x;
			cin >> x;
			usun(x);
		} else {
			int a, b;
			cin >> a >> b; --b;
			cout << licz(a, b) << '\n';
		}
	}
}