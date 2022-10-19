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

int q;
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> s;
		int ans = 10;
		for(int i = 0 ; i < 2 ; i++){
			int cnt0 = 0 , cnt1 = 0;
			for(int j = 0 ; j < 10 ; j++){
				int cur = 0;
				if(s[j] == '1' || (s[j] == '?' && j % 2 == i % 2))	cur = 1;
				if(j % 2 == 0)	cnt0 += cur;
				if(j % 2 == 1)	cnt1 += cur;
				int rem0 = (9 - j) / 2 , rem1 = (10 - j) / 2;
				//cout << cnt0 << sep << rem0 << sep << cnt1 << sep << rem1 << endl;
				if(cnt0 + rem0 < cnt1 || cnt1 + rem1 < cnt0)	ans = min(ans , j + 1);
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/