#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<vi> cnt(m+1, vi(m+2, 0));

	rep(_,0,n){
		int k;
		cin >> k;
		rep(_,0,k){
			int l, r;
			cin >> l >> r;
			++cnt[l][r+1];
		}
	}

	vector<vi> mem(m+1, vi(m+2, -1));

	function<int(int, int)> calc = [&](int fr, int to){
		if(mem[fr][to] == -1){
			int cur = 0;
			vi todo(to - fr);
			rep(s, fr+1, to) rep(t, s+1, to+1){
				todo[s - fr - 1] += cnt[s][t];
				todo[t - fr - 1] -= cnt[s][t];
			}
			rep(i, 1, to-fr) todo[i] += todo[i-1];
			rep(mi, fr+1, to)
				cur = max(cur, calc(fr, mi) + todo[mi-fr-1] * todo[mi-fr-1] + calc(mi, to));
			mem[fr][to] = cur;
		}
		return mem[fr][to];
	};

	cout << calc(0, m+1) << endl;
}