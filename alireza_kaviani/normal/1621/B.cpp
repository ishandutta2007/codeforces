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

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		pii mx = {-MOD , -MOD}, mn = {MOD , MOD} , mxl = {-MOD , -MOD};
		for(int i = 0 ; i < n ; i++){
			int l , r , c;
			cin >> l >> r >> c;
			mn = min(mn , pii(l , c));
			mx = max(mx , pii(r , -c));
			mxl = max(mxl , pii(r - l + 1 , -c));
			int res = mn.Y - mx.Y;
			if(mx.X - mn.X + 1 == mxl.X)	res = min(res , -mxl.Y);
			cout << res << endl;
		}
	}

    return 0;
}
/*

*/