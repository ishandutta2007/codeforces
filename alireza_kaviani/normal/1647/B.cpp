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

int q , n , m;
string s[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		for(int i = 0 ; i < n ; i++){
			cin >> s[i];
		}
		int flag = 0;
		for(int i = 0 ; i + 1 < n ; i++){
			for(int j = 0 ; j + 1 < m ; j++){
				int cnt = 0;
				for(int k = i ; k <= i + 1 ; k++){
					for(int l = j ; l <= j + 1 ; l++){
						cnt += (s[k][l] == '1');
					}
				}
				if(cnt == 3){
					flag = 1;
				}
			}
		}
		cout << (flag ? "NO" : "YES") << endl;
	}

    return 0;
}
/*

*/