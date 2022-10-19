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

int q , n;
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> s;
		t = s; sort(all(t));
		int ans = 0;
		for(int i = 0 ; i < n ; i++){
			if(s[i] != t[i])	ans++;
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/