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

int q , n , x , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> x;
		int sum = 0 , ind = -1;
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			sum += A[i];
			if(sum == x)	ind = i;
		}
		if(ind == n - 1){
			cout << "NO" << endl;
			continue;
		}
		if(ind != -1)	swap(A[ind] , A[ind + 1]);
		cout << "YES" << endl;
		for(int i = 0 ; i < n ; i++){
			cout << A[i] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/