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

int q , n , A[MAXN][5];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		int ans = 0;
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			int cnt = 0;
			for(int j = 0 ; j < 5 ; j++){
				cin >> A[i][j];
				if(A[i][j] < A[ans][j]){
					cnt++;
				}
			}
			if(cnt >= 3)	ans = i;
		}
		int flag = 1;
		for(int i = 0 ; i < n ; i++){
			int cnt = 0;
			for(int j = 0 ; j < 5 ; j++){
				if(A[i][j] < A[ans][j]){
					cnt++;
				}
			}
			if(cnt >= 3)	flag = 0;
		}
		cout << (flag ? ans + 1 : -1) << endl;
	}

    return 0;
}
/*

*/