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

int q , n , mark[200];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> s; n = SZ(s);
		fill(mark , mark + 200 , 0);
		int ans = n;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(!mark[s[i]]){
				mark[s[i]] = 1;
				ans = i;
			}
		}
		cout << s.substr(ans) << endl;
	}

    return 0;
}
/*

*/