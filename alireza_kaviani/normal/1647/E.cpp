#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 31;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , cnt , diff , mark[MAXN] , P[LOG][MAXN] , A[MAXN] , E[MAXN] , rem[MAXN] , ans[MAXN] , used[MAXN];
vector<int> pos[MAXN];
set<int> st;

int get(int v , int h){
	for(int i = 0 ; i < LOG ; i++){
		if(h & (1 << i)){
			v = P[i][v];
		}
	}
	return v;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> P[0][i];
		if(!mark[P[0][i]]){
			mark[P[0][i]] = 1;
			diff++;
		}
	}
	int mx = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		mx = max(mx , A[i]);
		if(A[i] <= n){
			rem[A[i]] = i;
		}
	}
	cnt = (mx - n) / (n - diff);
	
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 1 ; j <= n ; j++){
			P[i][j] = P[i - 1][P[i - 1][j]];
		}
	}
	for(int i = n ; i >= 1 ; i--){
		E[i] = get(i , cnt);
		pos[E[i]].push_back(i);
	}
	for(int i = 1 ; i <= n ; i++){
		if(rem[i] == 0){
			st.insert(i);
		}
	}
	for(int i = 1 ; i <= n ; i++){
//		cout << i << sep << E[i] << endl;
		if(used[E[i]]){
			ans[i] = (*st.lower_bound(A[E[i]]));
			st.erase(ans[i]);
			continue;
		}
		used[E[i]] = 1;
		ans[i] = A[E[i]];
	}
	for(int i = 1 ; i <= n ; i++){
		cout << ans[i] << sep;
	}

    return 0;
}
/*

*/