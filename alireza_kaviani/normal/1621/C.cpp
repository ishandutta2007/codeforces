#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
//#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int ask(int x){
	int res;
	cout << "? " << x << endl;
	cin >> res;
	return res;
}

int q , n , ans[MAXN] , mark[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n;
		fill(mark , mark + n + 5 , 0);
		fill(ans , ans + n + 5 , 0);
		for(int i = 1 ; i <= n ; i++){
			if(mark[i])	continue;
			vector<int> vec;
			while(1){
				int x = ask(i);
				vec.push_back(x);
				if(mark[x]){
					break;
				}
				mark[x] = 1;
			}
			for(int j = 0 ; j + 1 < SZ(vec) ; j++){
				ans[vec[j]] = vec[j + 1];
			}
		}
		cout << "!" << sep;
		for(int i = 1 ; i <= n ; i++){
			cout << ans[i] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/