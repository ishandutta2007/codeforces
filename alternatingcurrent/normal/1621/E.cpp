#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
double EPS = 1e-8;

int T;
int N, m;
ll a[300300];
int k[300300];
int bel[300300];
ll b[300300];
ll sum[300300];
double ave[300300];
int p[300300];
int rp[300300];
int ok[300300], preok[300300], nxtok[300300];
bool cmp(int u, int v){
	return ave[u] < ave[v];
}

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> N >> m;
		rep(i, N)
			cin >> a[i];
		int nowk = 0;
		rep(i, m){
			sum[i] = 0;
			cin >> k[i];
			rep(j, k[i]){
				bel[nowk + j] = i;
				cin >> b[nowk + j];
				sum[i] += b[nowk + j];
			}
			nowk += k[i];
		}
		rep(i, m)
			ave[i] = 1. * sum[i] / k[i];
		rep(i, m)
			p[i] = i;
		sort(p, p + m, cmp);
		rep(i, m)
			rp[p[i]] = i;
		ok[0] = preok[0] = nxtok[0] = 0;
		sort(a, a + N);
		rep(i, m)
			a[i] = a[i + N - m];
		rep(i, m){
//			cout << a[i] << " " << ave[p[i]] << endl;
			ok[i + 1] = (1ll * a[i] * k[p[i]] >= sum[p[i]]);
			preok[i + 1] = (i ? (1ll * a[i] * k[p[i - 1]] >= sum[p[i - 1]]) : 1);
			nxtok[i + 1] = (i < m ? (1ll * a[i] * k[p[i + 1]] >= sum[p[i + 1]]) : 1);
		}
		for(int i = 1; i <= m; i++)
			ok[i] += ok[i - 1], preok[i] += preok[i - 1], nxtok[i] += nxtok[i - 1];
		bool allok = (ok[m] == m);
		rep(i, nowk){
			int pos = rp[bel[i]];
			double toave = 1. * (sum[p[pos]] - b[i]) / (k[p[pos]] - 1);
			ll nowsum = sum[p[pos]] - b[i], nowk = k[p[pos]] - 1;
			if(toave < ave[p[pos]] + EPS && allok){
				cout << "1";
			} else if(toave > ave[p[pos]] && !allok){
				cout << "0";
			} else {
				int lb = 0, ub = m - 1;
				while(lb <= ub){
					int mid = (lb + ub) >> 1;
					if(ave[p[mid]] <= toave + EPS)
						lb = mid + 1;
					else
						ub = mid - 1;
				}
				int to = lb;
				if(to == pos)
					to++;
				if(toave > ave[p[pos]] && allok){
					if(to == pos + 1){
						cout << (bool)(nowk * a[pos] >= nowsum);
					} else {
						cout << (bool)(nxtok[to - 1] - nxtok[pos] >= (to - 1 - pos) && nowk * a[to - 1] >= nowsum);
					}
				} else {
					if(to == pos + 1){
						cout << (bool)(nowk * a[pos] >= nowsum && ok[m] - ok[pos + 1] + ok[pos] >= m - 1);
					} else {
						cout << (bool)(preok[pos + 1] - preok[to + 1] >= (pos - to) && nowk * a[to] >= nowsum && ok[m] - ok[pos + 1] + ok[to] >= m - (pos - to + 1));
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}