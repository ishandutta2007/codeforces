#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const ll INF=1e9+7;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		ll k[n], c[m], sum=0;
		pair<ll,int>T[m];
		rep(i, n) cin >> k[i];
		rep(i, m) {
			cin >> c[i];
			T[i]={c[i], 0};
		}
		rep(i, n) {
			++T[k[i]-1].nd;
			sum+=c[k[i]-1];
		}
		int N=1;
		while(N<m) N*=2;
		pair<ll, int>tr[2*N];
		rep(i, m) tr[i+N]={c[i], i};
		for(int i=N-1; i; --i) {
			tr[i].st=min(tr[2*i].st, tr[2*i+1].st);
			if(tr[2*i].st<tr[2*i+1].st) tr[i].nd=tr[2*i].nd; else tr[i].nd=tr[2*i+1].nd;
		}
		for(int i=m-1; i>=0; --i) {
			while(T[i].nd) {
				/*ll mi=INF;
				rep(j, i+1) mi=min(mi, c[j]);*/

				ll x=i+N, mi=tr[x].st, p=tr[x].nd;
				while(x>1) {
					if(x%2==1 && tr[x-1].st<mi) {
						p=tr[x-1].nd;
						mi=tr[x-1].st;
					}
					x/=2;
				}
				if(mi<T[i].st) {
					sum-=T[i].st;
					sum+=mi;
					p+=N;
					tr[p].st=INF;
					p/=2;
					while(p) {
						tr[p].st=min(tr[2*p].st, tr[2*p+1].st);
						if(tr[2*p].st<tr[2*p+1].st) tr[p].nd=tr[2*p].nd;
						else tr[p].nd=tr[2*p+1].nd;
						p/=2;
					}
				}
				//rep(j, i+1) if(c[j]==mi) { c[j]=INF; break; }
				--T[i].nd;
			}
		}
		cout << sum << '\n';
	}
}