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
const int LIM=1<<20;
int przedzial[LIM];
int prefiks[LIM];
int sufiks[LIM];
int prefiks_zer[LIM];
int prefiks_jedynek[LIM];
int sufiks_zer[LIM];
int sufiks_jedynek[LIM];
int rozmiar[LIM];
int przedzial2[LIM];
int sufiks2[LIM];
int prefiks2[LIM];
int lazy[LIM];
int N=1;
vector<pair<int,int>>V;
void licz(int i) {
	rozmiar[i]=rozmiar[2*i]+rozmiar[2*i+1];
	prefiks_zer[i]=prefiks_zer[2*i];
	if(prefiks_zer[2*i]==rozmiar[2*i]) {
		prefiks_zer[i]+=prefiks_zer[2*i+1];
	}
	prefiks_jedynek[i]=prefiks_jedynek[2*i];
	if(prefiks_jedynek[2*i]==rozmiar[2*i]) {
		prefiks_jedynek[i]+=prefiks_jedynek[2*i+1];
	}
	sufiks_zer[i]=sufiks_zer[2*i+1];
	if(sufiks_zer[2*i+1]==rozmiar[2*i+1]) {
		sufiks_zer[i]+=sufiks_zer[2*i];
	}
	sufiks_jedynek[i]=sufiks_jedynek[2*i+1];
	if(sufiks_jedynek[2*i+1]==rozmiar[2*i+1]) {
		sufiks_jedynek[i]+=sufiks_jedynek[2*i];
	}
	prefiks[i]=prefiks[2*i];
	if(prefiks[2*i]==rozmiar[2*i]) {
		prefiks[i]+=prefiks_jedynek[2*i+1];
	}
	if(prefiks_zer[2*i]==rozmiar[2*i]) {
		prefiks[i]=max(prefiks[i], prefiks_zer[2*i]+prefiks[2*i+1]);
	}
	sufiks[i]=sufiks[2*i+1];
	if(sufiks[2*i+1]==rozmiar[2*i+1]) {
		sufiks[i]+=sufiks_zer[2*i];
	}
	if(sufiks_jedynek[2*i+1]==rozmiar[2*i+1]) {
		sufiks[i]=max(sufiks[i], sufiks_jedynek[2*i+1]+sufiks[2*i]);
	}
	przedzial[i]=max(przedzial[2*i], przedzial[2*i+1]);
	przedzial[i]=max(przedzial[i], sufiks[2*i]+prefiks_jedynek[2*i+1]);
	przedzial[i]=max(przedzial[i], sufiks_zer[2*i]+prefiks[2*i+1]);
	prefiks2[i]=prefiks2[2*i];
	if(prefiks2[2*i]==rozmiar[2*i]) {
		prefiks2[i]+=prefiks_zer[2*i+1];
	}
	if(prefiks_jedynek[2*i]==rozmiar[2*i]) {
		prefiks2[i]=max(prefiks2[i], prefiks_jedynek[2*i]+prefiks2[2*i+1]);
	}
	sufiks2[i]=sufiks2[2*i+1];
	if(sufiks2[2*i+1]==rozmiar[2*i+1]) {
		sufiks2[i]+=sufiks_jedynek[2*i];
	}
	if(sufiks_zer[2*i+1]==rozmiar[2*i+1]) {
		sufiks2[i]=max(sufiks2[i], sufiks_zer[2*i+1]+sufiks2[2*i]);
	}
	przedzial2[i]=max(przedzial2[2*i], przedzial2[2*i+1]);
	przedzial2[i]=max(przedzial2[i], sufiks2[2*i]+prefiks_zer[2*i+1]);
	przedzial2[i]=max(przedzial2[i], sufiks_jedynek[2*i]+prefiks2[2*i+1]);
}
void spl(int v) {
	lazy[2*v]^=lazy[v];
	swap(prefiks_zer[2*v], prefiks_jedynek[2*v]);
	swap(sufiks_zer[2*v], sufiks_jedynek[2*v]);
	swap(prefiks[2*v], prefiks2[2*v]);
	swap(sufiks[2*v], sufiks2[2*v]);
	swap(przedzial[2*v], przedzial2[2*v]);
	lazy[2*v+1]^=lazy[v];
	swap(prefiks_zer[2*v+1], prefiks_jedynek[2*v+1]);
	swap(sufiks_zer[2*v+1], sufiks_jedynek[2*v+1]);
	swap(prefiks[2*v+1], prefiks2[2*v+1]);
	swap(sufiks[2*v+1], sufiks2[2*v+1]);
	swap(przedzial[2*v+1], przedzial2[2*v+1]);
	lazy[v]=0;
}
void upd(int v, int l, int r, int a, int b) {
	if(b<l || a>r) return;
	if(a<=l && r<=b) {
		V.pb({l, v});
		lazy[v]^=1;
		swap(prefiks_zer[v], prefiks_jedynek[v]);
		swap(sufiks_zer[v], sufiks_jedynek[v]);
		swap(prefiks[v], prefiks2[v]);
		swap(sufiks[v], sufiks2[v]);
		swap(przedzial[v], przedzial2[v]);
		return;
	}
	if(lazy[v]) spl(v);
	int mid=(l+r)/2;
	upd(2*v, l, mid, a, b);
	upd(2*v+1, mid+1, r, a, b);
	licz(v);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	while(N<n) N*=2;
	rep(i, n) {
		char a;
		cin >> a;
		przedzial[N+i]=prefiks[N+i]=sufiks[N+i]=rozmiar[N+i]=1;
		przedzial2[N+i]=sufiks2[N+i]=prefiks2[N+i]=1;
		if(a=='<') {
			prefiks_jedynek[N+i]=1;
			sufiks_jedynek[N+i]=1;
		} else {
			prefiks_zer[N+i]=1;
			sufiks_zer[N+i]=1;
		}
	}
	for(int i=N-1; i>=0; --i) licz(i);
	while(q--) {
		int l, r;
		cin >> l >> r; --l; --r;
		V.clear();
		upd(1, 0, N-1, l, r);
		sort(all(V));
		vector<int>zera(V.size()), jedynki(V.size());
		int ans=0;
		rep(i, V.size()) {
			ans=max(ans, przedzial[V[i].nd]);
			zera[i]=sufiks_zer[V[i].nd];
			if(sufiks_zer[V[i].nd]==rozmiar[V[i].nd] && i) zera[i]+=zera[i-1];
		}
		for(int i=V.size()-1; i>=0; --i) {
			jedynki[i]=prefiks_jedynek[V[i].nd];
			if(prefiks_jedynek[V[i].nd]==rozmiar[V[i].nd] && i<V.size()-1) jedynki[i]+=jedynki[i+1];
		}
		rep(i, V.size()) {
			int akt=prefiks[V[i].nd];
			if(i) akt+=zera[i-1];
			ans=max(ans, akt);
			akt=sufiks[V[i].nd];
			if(i<V.size()-1) akt+=jedynki[i+1];
			ans=max(ans, akt);
			if(przedzial[V[i].nd]<rozmiar[V[i].nd]) continue;
			akt=przedzial[V[i].nd];
			if(i) akt+=zera[i-1];
			if(i<V.size()-1) akt+=jedynki[i+1];
			ans=max(ans, akt);
		}
		cout << ans << '\n';
	}
}