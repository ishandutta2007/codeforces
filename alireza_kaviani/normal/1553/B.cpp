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

int q , n , m;
string s , t;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> s >> t;
		n = SZ(s); m = SZ(t);
		int flag = 0;
		for(int i = 0 ; i < n ; i++){
			for(int j = i ; j < n ; j++){
				int l = j + j - i - m + 1;
				if(j - i + 1 > m || l < 0)	continue;
				string x = s.substr(i , j - i);
				string y = s.substr(l , m - j + i);
				reverse(all(y));
				if(x + y == t)	flag = 1;
			}
		}
		if(flag == 0)	cout << "NO" << endl;
		else	cout << "YES" << endl;
	}

    return 0;
}
/*

*/