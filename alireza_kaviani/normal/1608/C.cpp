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
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int q , n , A[MAXN] , B[MAXN] , mx[MAXN] , can[MAXN];

int cmp(int i , int j){
	return A[i] < A[j];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		vector<int> vec;
		cin >> n;
		fill(can , can + n + 5 , 0);
		fill(mx , mx + n + 5 , -MOD);
		for(int i = 0 ; i < n ; i++){
			cin >> A[i];
			vec.push_back(i);
		}
		for(int i = 0 ; i < n ; i++){
			cin >> B[i];
		}
		sort(all(vec) , cmp);
		for(int i = 0 ; i < n ; i++){
			mx[i] = (i == 0 ? B[vec[i]] : max(mx[i - 1] , B[vec[i]]));
		//	cout << i << sep << mx[i] << endl;
		}
		int mn = MOD;
		for(int i = n - 1 ; i >= 0 ; i--){
			mn = min(mn , B[vec[i]]);
			can[vec[i]] = 1;
			if(i > 0 && mn > mx[i - 1]){
				break;
			}
		}
		for(int i = 0 ; i < n ; i++){
			cout << can[i];
		}
		cout << endl;
	}

    return 0;
}
/*

*/