#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
// #define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , A[MAXN] , OR[3][3] , AN[3][3];

int getOr(int i , int j){
	int ans; i++; j++;
	cout << "or " << i << sep << j << endl;
	cin >> ans;
	return ans;
}

int getAnd(int i , int j){
	int ans; i++; j++;
	cout << "and " << i << sep << j << endl;
	cin >> ans;
	return ans;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			if(i >= j){
				OR[i][j] = OR[j][i];
				AN[i][j] = AN[j][i];
				continue;
			}
			OR[i][j] = getOr(i , j);
			AN[i][j] = getAnd(i , j);
		}
	}
	for(int i = 0 ; i < 3 ; i++){
		int o1 = OR[i][(i + 1) % 3], o2 = OR[i][(i + 2) % 3] , o3 = OR[(i + 1) % 3][(i + 2) % 3];
		int a1 = AN[i][(i + 1) % 3], a2 = AN[i][(i + 2) % 3] , a3 = AN[(i + 1) % 3][(i + 2) % 3];
		for(int j = 0 ; j < LOG ; j++){
			if((a1 | a2) & (1 << j)){
				A[i] |= (1 << j);
				continue;
			}
			if(((o1 & o2) & (1 << j)) == 0){
				continue;
			}
			if(a3 & (1 << j)){
				continue;
			}
			A[i] |= (1 << j);
		}
//		cout << A[i] << sep;
	}
	for(int i = 3 ; i < n ; i++){
		A[i] = getOr(0 , i) + getAnd(0 , i) - A[0];
//		cout << A[i] << sep;
	}
	sort(A , A + n);
	cout << "finish " << A[k - 1] << endl;

    return 0;
}
/*

*/