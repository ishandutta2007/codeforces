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

const ll MAXN = 2e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , f , ans , mark[MAXN] , cnt[MAXN] , grundy[MAXN];
bitset<MAXN> valid , bs[100];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> f;
	for(int i = 2 ; i < MAXN ; i++){
		if(mark[i])	continue;
		for(int j = i ; j < MAXN ; j += i){
			mark[j] = 1;
			int x = j;
			while(x % i == 0){
				cnt[j]++;
				x /= i;
			}
		}
	}
	for(int i = 2 ; i < MAXN ; i++){
		if(i != f && cnt[i] <= 2){
			valid[i] = 1;
		}
	}
	bs[0] |= valid;
	for(int i = 1 ; i < MAXN ; i++){
		while(bs[grundy[i]][i]){
			grundy[i]++;
		}
		bs[grundy[i]] |= (valid << i);
	}
	
	for(int i = 0 ; i < n ; i++){
		int b , w , r;
		cin >> b >> w >> r;
		ans ^= (grundy[w - b - 1] ^ grundy[r - w - 1]);
//		cout << grundy[w - b - 1] << sep << grundy[r - w - 1] << endl;
	}
	cout << (ans == 0 ? "Bob" : "Alice") << endl;
	cout << (ans != 0 ? "Bob" : "Alice") << endl;

    return 0;
}
/*

*/