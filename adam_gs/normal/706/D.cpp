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
int sum;
void dodaj(int x) {
	int akt=0;
	++sum;
	for(int i=30; i>=0; --i) {
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
	--sum;
	for(int i=30; i>=0; --i) {
		if(x&(1<<i)) {
			akt=trie[akt].nd;
		} else {
			akt=trie[akt].st;
		}
		--ile[akt];
	}
}
int znajdz(int x) {
	if(sum==0) return x;
	int akt=0, ans=0;
	for(int i=30; i>=0; --i) {
		if(x&(1<<i)) {
			if(trie[akt].st!=-1 && ile[trie[akt].st]) {
				akt=trie[akt].st;
			} else {
				akt=trie[akt].nd;
				ans+=1<<i;
			}
		} else {
			if(trie[akt].nd!=-1 && ile[trie[akt].nd]) {
				akt=trie[akt].nd;
				ans+=1<<i;
			} else {
				akt=trie[akt].st;
			}
		}
	}
	return max(ans^x, x);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	trie.pb({-1, -1});
	ile.pb(0);
	int q;
	cin >> q;
	while(q--) {
		char a;
		int x;
		cin >> a >> x;
		if(a=='+') dodaj(x);
		if(a=='-') usun(x);
		if(a=='?') cout << znajdz(x) << '\n';
	}
}