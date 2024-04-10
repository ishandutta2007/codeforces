#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int LIM=1e5+7, SQ=307;
int nxt[LIM], nxtsq[LIM], prv[LIM];
void upd(int x) {
	int akt=x;
	rep(j, SQ) akt=nxt[akt];
	nxtsq[x]=akt;
	rep(j, SQ) {
		x=prv[x];
		akt=prv[akt];
		nxtsq[x]=akt;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	rep(i, n) {
		cin >> nxt[i]; --nxt[i];
		prv[nxt[i]]=i;
		nxtsq[i]=-1;
	}
	rep(i, n) if(nxtsq[i]==-1) {
		int akt=i, aktsq=i;
		rep(j, SQ) aktsq=nxt[aktsq];
		while(nxtsq[akt]==-1) {
			nxtsq[akt]=aktsq;
			akt=nxt[akt];
			aktsq=nxt[aktsq];
		}
	}
	while(q--) {
		int x, a, b;
		cin >> x >> a >> b;
		if(x==1) {
			--a; --b;
			swap(prv[nxt[a]], prv[nxt[b]]);
			swap(nxt[a], nxt[b]);
			upd(a); upd(b);
		} else {
			--a;
			while(b>=SQ) {
				a=nxtsq[a];
				b-=SQ;
			}
			while(b--) a=nxt[a];
			cout << a+1 << '\n';
		}
	}
}