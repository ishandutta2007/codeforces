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
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , cnt[LOG];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		fill(cnt , cnt + LOG , 0);
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			for(int j = 0 ; j < LOG ; j++){
				if(A[i] & (1 << j)){
					cnt[j]++;
				}
			}
		}
		for(int i = 1 ; i <= n ; i++){
			int flag = 1;
			for(int j = 0 ; j < LOG ; j++){
				if(cnt[j] % i != 0){
					flag = 0;
				}
			}
			if(flag){
				cout << i << sep;
			}
		}
		cout << endl;
	}

    return 0;
}
/*

*/