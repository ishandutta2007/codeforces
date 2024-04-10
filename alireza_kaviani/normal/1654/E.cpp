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

const ll SQ1 = 210;
const ll SQ2 = 510;
const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , ans = 1 , A[MAXN] , B[MAXN] , cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> A[i];
	}
	
	for(int i = -SQ1 ; i <= SQ1 ; i++){
		for(int j = 0 ; j < n ; j++){
			B[j] = A[j] - i * j;
		}
		sort(B , B + n);
		int cur = 1 , res = 1;
		for(int j = 1 ; j < n ; j++){
			if(B[j] != B[j - 1]){
				cur = 1;
				continue;
			}
			cur++;
			res = max(res , cur);
		}
		ans = max(ans , res);
	}
	
	for(int i = 0 ; i < n ; i++){
		int res = 0;
		for(int j = i + 1 ; j < n && j < i + SQ2 ; j++){
			if((A[i] - A[j]) % (j - i) != 0)	continue;
			int g = (A[i] - A[j]) / (j - i) + MAXN / 2;
			cnt[g]++;
			res = max(res , cnt[g]);
		}
		for(int j = i + 1 ; j < n && j < i + SQ2 ; j++){
			if((A[i] - A[j]) % (j - i) != 0)	continue;
			int g = (A[i] - A[j]) / (j - i) + MAXN / 2;
			cnt[g]--;
		}
		ans = max(ans , res + 1);
	}

	cout << n - ans << endl;

    return 0;
}
/*

*/