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

int n , k , ans , L[MAXN] , R[MAXN];
vector<pii> vec;
set<pii> st;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> L[i] >> R[i];
		vec.push_back({L[i] , i});
	}
	sort(all(vec));
	for(pii i : vec){
		int ind = i.Y , l = L[ind] , r = R[ind];
		st.insert({r , ind});
		if(SZ(st) > k){
			st.erase(st.begin());
		}
		if(SZ(st) == k){
			int len = max(0 , (*st.begin()).X - l + 1);
			ans = max(ans , len);
		}
	}
	cout << ans << endl;
	st.clear();
	for(pii i : vec){
		int ind = i.Y , l = L[ind] , r = R[ind];
		st.insert({r , ind});
		if(SZ(st) > k){
			st.erase(st.begin());
		}
		if(SZ(st) == k){
			int len = max(0 , (*st.begin()).X - l + 1);
			if(len == ans){
				for(auto &j : st){
					cout << j.Y << sep;
				}
				return 0;
			}
		}
	}

    return 0;
}
/*

*/