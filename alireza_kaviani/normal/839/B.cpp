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

int n , k , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 0 ; i < k ; i++)	cin >> A[i];
	for(int i = 0 ; i < 3 * n ; i++){
		int cnt = (i < n ? 4 : 2);
		int mx = 0 , mn = -1;
		for(int j = 0 ; j < k ; j++){
			if(A[j] > A[mx])	mx = j;
		}
		for(int j = 0 ; j < k ; j++){
			if(A[j] > 0 && j != mx && (mn == -1 || A[j] < A[mn]))	mn = j;
		}
		if(A[mx] <= 0)	break;
		if(A[mx] <= 2 && mn != -1 && cnt == 4){
			A[mn]--;
		}
		A[mx] -= cnt;
	}
	for(int i = 0 ; i < k ; i++){
		if(A[i] > 0)	return cout << "NO" << endl , 0;
	}
	cout << "YES" << endl;

    return 0;
}
/*

*/