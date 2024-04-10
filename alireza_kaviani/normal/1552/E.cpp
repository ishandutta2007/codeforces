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

const ll MAXN = 200 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , col[MAXN * MAXN] , A[MAXN] , B[MAXN] , last[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 1 ; i <= n * k ; i++)	cin >> col[i];
	for(int i = 0 ; i < n ; i++){
		fill(last , last + MAXN , -1);
		for(int j = 1 ; j <= n * k ; j++){
			if(A[col[j]])	continue;
			if(last[col[j]] != -1){
				A[col[j]] = last[col[j]];
				B[col[j]] = j;
				fill(last , last + MAXN , -1);
				continue;
			}
			last[col[j]] = j;
		}
	}
	for(int i = 1 ; i <= n ; i++)	cout << A[i] << sep << B[i] << endl;

    return 0;
}
/*

*/