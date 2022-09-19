// vaziat meshki-ghermeze !
#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 1500 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

typedef vector<int> vi;

vector<vi> A, B;

int mk[N];
int cnt[N], mv[N];


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	// cin >> n >> m;
	scanf("%d%d", &n, &m);
	A.resize(n, vi(m, 0));
	B.resize(n, vi(m, 0));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	vi ans;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++)
			if(B[i - 1][j] > B[i][j]) cnt[j] ++;
	}
	for(int _ = 0; _ < m; _++){
		int id = -1;
		for(int j = 0; j < m; j++) if(cnt[j] == 0 && mv[j] == 0) id = j;
		if(id == -1) continue;
		mv[id] = 1;
		ans.pb(id);
		for(int i = 1; i < n; i++){
			if(mk[i]) continue;
			if(B[i - 1][id] < B[i][id]){
				mk[i] = 1;
				for(int j = 0; j < m; j++)
					if(B[i - 1][j] > B[i][j]) cnt[j] --;
			}
		}
	}
	reverse(all(ans));
	vi I(n), P(n);
	iota(all(I), 0);

	for(auto cl : ans){
		for(int i = 0; i < n; i++) P[I[i]] = i;
		sort(all(I), [&](int i, int j){
			if(A[i][cl] == A[j][cl])
				return P[i] < P[j];
			return A[i][cl] < A[j][cl];
		});
	}
	for(int i = 0; i < n; i++){
		if(B[i] != A[I[i]])
			return cout << "-1\n", 0;
	}
	// cout << ans.size() << '\n';
	int sz = ans.size();
	printf("%d\n", sz);
	for(auto x : ans) printf("%d ", x + 1);
	printf("\n");
	return 0;
}