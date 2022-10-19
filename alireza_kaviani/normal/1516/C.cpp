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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , g , A[MAXN];
bitset<MAXN> bs;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
		g = __gcd(g , A[i]);
	}
	int sum = 0 , od = -1;
	for(int i = 0 ; i < n ; i++){
		A[i] /= g;
		sum += A[i];
		if(A[i] & 1)	od = i + 1;
	}
	if(sum & 1)	return cout << 0 << endl , 0;
	bs[0] = 1;
	for(int i = 0 ; i < n ; i++){
		bs |= (bs << A[i]);
	}
	if(bs[sum / 2])	return cout << 1 << endl << od << endl , 0;
	cout << 0 << endl;

    return 0;
}
/*

*/