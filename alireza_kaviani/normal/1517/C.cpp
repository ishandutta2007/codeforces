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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , A[MAXN] , ans[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++)	cin >> A[i];
	for(int i = 0 ; i < n ; i++){
		int ptr = 0;
		for(int j = 0 ; j < n ; j++){
			if(A[j] > i){
				ans[ptr + i][ptr] = A[j]; ptr++;
			}
		}
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <= i ; j++){
			cout << ans[i][j] << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/