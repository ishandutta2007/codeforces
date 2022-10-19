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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , ans ,  sum , L[MAXN] , D[MAXN];
vector<pii> vec[MAXN];
set<pii , greater<pii>> st;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> L[i];
	}
	for(int i = 0 ; i < n ; i++){
		cin >> D[i];
		vec[L[i]].push_back({D[i] , i});
		sum += D[i];
	}

	for(int i = 0 ; i < MAXN ; i++){
		int cnt = SZ(vec[i]) - 1 , cur = 0;
		for(auto it = st.begin() ; it != st.end() && cnt > 0 ; it++, cnt--){
			cur += (*it).X;
		}
		for(pii j : vec[i]){
			cur += j.X;
			st.insert(j);
		}
		ans = max(ans , cur);
	}
	cout << sum - ans << endl;

    return 0;
}
/*

*/