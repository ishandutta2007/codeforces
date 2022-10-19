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

int q , n , u , v , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> u >> v;
		for(int i = 0 ; i < n ; i++)	cin >> A[i];
		int flag = 0;
		for(int i = 1 ; i < n ; i++){
			if(abs(A[i] - A[i - 1]) > 1)	flag = 1;
		}
		if(flag){
			cout << 0 << endl;
			continue;
		}
		for(int i = 1 ; i < n ; i++){
			if(A[i] != A[i - 1])	flag = 1;
		}
		if(flag){
			cout << min(u , v) << endl;
			continue;
		}
		cout << v + min(u , v) << endl;
	}

    return 0;
}
/*

*/