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
const ll LOG = 31;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , sum , A[MAXN] , B[MAXN] , C[MAXN] , cnt[LOG];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> B[i];
		sum += B[i];
	}
	for(int i = 1 ; i <= n ; i++){
		cin >> C[i];
		sum += C[i];
	}
	if(sum % (2 * n) != 0){
		cout << -1 << endl;
		return 0;
	}
	sum /= 2 * n;
	for(int i = 1 ; i <= n ; i++){
		if(B[i] + C[i] - sum < 0){
			cout << -1 << endl;
			return 0;
		}
		if((B[i] + C[i] - sum) % n != 0){
			cout << -1 << endl;
			return 0;
		}
		A[i] = (B[i] + C[i] - sum) / n;
		for(int j = 0 ; j < LOG ; j++){
			if(A[i] & (1 << j)){
				cnt[j]++;
			}
		}
	}
	for(int i = 1 ; i <= n ; i++){
		ll val = 0;
		for(int j = 0 ; j < LOG ; j++){
			if(A[i] & (1 << j)){
				val += cnt[j] * (1ll << j);
			}
		}
		if(B[i] != val){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1 ; i <= n ; i++){
		cout << A[i] << sep;
	}

    return 0;
}
/*

*/