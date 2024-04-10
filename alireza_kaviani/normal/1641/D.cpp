#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<pll , ll> Data;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e5 + 10;
const ll LOG = 32;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;
const ll MAX = 1e6;

int n , m , vec[5] , A[MAXN][5] , L[MAXN] , R[MAXN] , W[MAXN] , ind[MAXN][1 << 5] , cnt[MAXN * LOG];
vector<pll> compress;
vector<int> values , w , Q[MAXN];

pll get(int v , int mask){
	int ptr = 0;
	for(int i = 0 ; i < 5 ; i++){
		if(mask & (1 << i)){
			vec[ptr++] = A[v][i];
		}
	}
	while(ptr < 5){
		vec[ptr++] = MAX - 1;
	}
	return {MAX * MAX * vec[0] + MAX * vec[1] + vec[2] , vec[3] * MAX + vec[4]};
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	w.push_back(-MOD);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> A[i][j];
			values.push_back(A[i][j]);
		}
		sort(A[i] , A[i] + m);
		cin >> W[i];
		w.push_back(W[i]);
	}
	sort(all(values));
	values.resize(unique(all(values)) - values.begin());
	sort(all(w));
	w.resize(unique(all(w)) - w.begin());
	compress.reserve(n * (1 << m));
	for(int i = 0 ; i < n ; i++){
		W[i] = lower_bound(all(w) , W[i]) - w.begin();
		for(int j = 0 ; j < m ; j++){
			A[i][j] = lower_bound(all(values) , A[i][j]) - values.begin();
		}
		for(int j = 0 ; j < (1 << m) ; j++){
			compress.push_back(get(i , j));
		}
	}
	sort(all(compress));
	compress.resize(unique(all(compress)) - compress.begin());
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < (1 << m) ; j++){
			pll val = get(i , j);
			ind[i][j] = lower_bound(all(compress) , val) - compress.begin();
		//	cout << i << sep << j << sep << ind[i][j] << endl;
		}
		R[i] = MAXN;
	}

	for(int i = 0 ; i < 20 ; i++){
		memset(cnt , 0 , sizeof(cnt));
		for(int j = 0 ; j < MAXN ; j++){
			Q[j].clear();
		}
		for(int j = 0 ; j < n ; j++){
			Q[W[j]].push_back(-(j + 1));
		}
		for(int j = 0 ; j < n ; j++){
			int mid = L[j] + R[j] >> 1;
			Q[mid].push_back(j);
		}
		int tot = 0;
		for(int j = 0 ; j < MAXN ; j++){
			for(int l : Q[j]){
				int x = l;
				if(x < 0){
					x = -x - 1;
					for(int k = 1 ; k < (1 << m) ; k++){
						cnt[ind[x][k]]++;
					}
					tot++;
				}
				else{
					int sum = 0;
					for(int k = 1 ; k < (1 << m) ; k++){
						if(__builtin_popcount(k) & 1){
							sum += cnt[ind[x][k]];
						}
						else{
							sum -= cnt[ind[x][k]];
						}
					}
					if(sum == tot)	L[x] = j;
					else	R[x] = j;
				}
			}
		}
	}
	ll ans = INF;
	for(int i = 0 ; i < n ; i++){
		if(R[i] != MAXN){
			ans = min(ans , (ll)w[R[i]] + w[W[i]]);
		}
	}
	cout << (ans == INF ? -1 : ans) << endl;

    return 0;
}
/*

*/