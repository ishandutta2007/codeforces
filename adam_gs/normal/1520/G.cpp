#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define lg(a) (31-__builtin_clz(a))
#define all(a) a.begin(), a.end()
ll pow(ll a,ll b,ll c){ll w=1;while(b){if(b&1)w=(w*a)%c;b/=2;a=(a*a)%c;}return w;}
const int LIM=2e3+7;
const ll INF=1e18+7;
ll mindo[LIM][LIM], minod[LIM][LIM], T[LIM][LIM];
int up[4]={1, 0, -1, 0}, rt[4]={0, 1, 0, -1};
void solve() {
	int n, m;
   	ll w;
	cin >> n >> m >> w;
	rep(i, n) rep(j, m) {
		cin >> T[i][j];
		mindo[i][j]=minod[i][j]=INF;
	}
	mindo[0][0]=0;
	queue<pair<int,int>>q;
	q.push({0, 0});
	while(!q.empty()) {
		int a=q.front().st, b=q.front().nd; q.pop();
		rep(i, 4) {
			if(0<=a+up[i] && a+up[i]<n && 0<=b+rt[i] && b+rt[i]<m) {
				if(T[a+up[i]][b+rt[i]]!=-1) {
					if(mindo[a+up[i]][b+rt[i]]>mindo[a][b]+w) {
						mindo[a+up[i]][b+rt[i]]=mindo[a][b]+w;
						q.push({a+up[i], b+rt[i]});
					}
				}
			}
		}
	}
	minod[n-1][m-1]=0;
	q.push({n-1, m-1});
	while(!q.empty()) {
		int a=q.front().st, b=q.front().nd; q.pop();
		rep(i, 4) {
			if(0<=a+up[i] && a+up[i]<n && 0<=b+rt[i] && b+rt[i]<m) {
				if(T[a+up[i]][b+rt[i]]!=-1) {
					if(minod[a+up[i]][b+rt[i]]>minod[a][b]+w) {
						minod[a+up[i]][b+rt[i]]=minod[a][b]+w;
						q.push({a+up[i], b+rt[i]});
					}
				}
			}
		}
	}
	ll mi=INF, ans=mindo[n-1][m-1];
	rep(i, n) {
		rep(j, m) {
			if(T[i][j]>0) {
				mi=min(mi, T[i][j]+minod[i][j]);
			}
		}
	}
	rep(i, n) rep(j, m) if(T[i][j]>0) ans=min(ans, mi+mindo[i][j]+T[i][j]);
	cout << (ans>=INF?-1:ans) << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t=1;
	while(t--) solve();
}