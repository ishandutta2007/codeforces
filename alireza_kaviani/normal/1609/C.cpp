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

int q , e , n , A[MAXN], mark[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	for(int i = 2 ; i < MAXN ; i++){
		if(mark[i])	continue;
		for(int j = i ; j < MAXN ; j += i){
			mark[j] = 2;
		}
		mark[i] = 1;
	}
	cin >> q;
	while(q--){
		cin >> n >> e;
		ll ans = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			//cout << A[i] << sep << mark[A[i]] << endl;
		}
		for(int i = 0 ; i < e ; i++){
			vector<int> vec = {0};
			for(int j = i ; j < n ; j += e){
				vec.push_back(vec.back() + mark[A[j]]);
			}
			int prv = -MOD , cur = -MOD , pcnt = 0 , cnt = 0;
			for(int i : vec){
				if(i != cur){
					pcnt = cnt;
					prv = cur;
					cur = i;
					cnt = 0;
				}
				if(i == prv + 1){
					ans += pcnt - (cnt == 0);
				}
				cnt++;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
/*

*/