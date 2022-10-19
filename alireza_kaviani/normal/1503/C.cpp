#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , A[MAXN] , B[MAXN] , sum , ans;
vector<pair<pii , int>> vec;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i] >> B[i];
		sum += B[i];
		B[i] += A[i];
		vec.push_back({{A[i] , B[i]} , i});
	}
	sort(all(vec));
	int mxb = 0;
	for(auto &i : vec){
//		cout << i.X.X << sep << i.X.Y << sep << i.Y << endl;
		ans += max(0 , i.X.X - mxb);
		mxb = max(mxb , i.X.Y);
	}
	cout << ans + sum - vec[0].X.X << endl;

    return 0;
}
/*

*/