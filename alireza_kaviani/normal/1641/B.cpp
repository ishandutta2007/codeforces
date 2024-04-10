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

int q , n;
vector<pii> opr;
vector<int> ans;
map<int, int> cnt;

void solve(vector<int> A){
	if(SZ(A) == 0)	return;
	int val = A.back(); A.pop_back();
	vector<int> vec;
	while(A.back() != val){
		vec.push_back(A.back());
		A.pop_back();
	}
	A.pop_back();
	for(int i = 0 ; i < SZ(vec) ; i++){
		opr.push_back({vec[i] , SZ(A)});
		A.push_back(vec[i]);
	}
	solve(A);
	ans.push_back(SZ(vec) + 1);
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		opr.clear();
		cnt.clear();
		ans.clear();
		vector<int> A;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			int x; cin >> x;
			A.push_back(x);
			cnt[x]++;
		}
		int flag = 0;
		for(auto &i : cnt){
			if(i.Y & 1){
				flag = 1;
			}
		}
		if(flag){
			cout << -1 << endl;
			continue;
		}
		solve(A);
		cout << SZ(opr) << endl;
		for(pii i : opr){
			cout << i.Y << sep << i.X << endl;
		}
		cout << SZ(ans) << endl;
		for(int i : ans){
			cout << i * 2 << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/