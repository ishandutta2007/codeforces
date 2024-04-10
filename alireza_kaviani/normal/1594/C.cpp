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

int q , n , cnt[MAXN];
string c , s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> c >> s;
		fill(cnt , cnt + n + 10 , 0);
		for(int i = 1 ; i <= n ; i++){
			for(int j = i ; j <= n ; j += i){
				if(s[j - 1] != c[0]){
					cnt[i]++;
				}
			}
		}
		int mn = MAXN , mnInd = 1;
		for(int i = 1 ; i <= n ; i++){
			//cout << i << sep << cnt[i] << endl;
			if(cnt[i] < mn){
				mn = cnt[i];
				mnInd = i;
			}
		}
		if(cnt[1] == 0){
			cout << 0 << endl;
			continue;
		}
		if(mn == 0){
			cout << 1 << endl << mnInd << endl;
			continue;
		}
		cout << 2 << endl << n - 1 << sep << n << endl;
	}

    return 0;
}
/*

*/