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

int q , n , k , A[MAXN] , cnt[MAXN];

int check(int x){
	if(x >= n)	return 1;
	int val = (n + k + 1) / 2;
	for(int i = 1 ; i + x <= n ; i++){
		int l = i , r = i + x;
		if(cnt[r] - cnt[l - 1] >= val){
			return l;
		}
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> k;
		fill(cnt , cnt + n + 5 , 0);
		for(int i = 1 ; i <= n ; i++){
			cin >> A[i];
			cnt[A[i]]++;
		}
		partial_sum(cnt , cnt + n + 5 , cnt);
		int l = -1 , r = MAXN;
		while(r - l > 1){
			int mid = l + r >> 1;
			if(check(mid))	r = mid;
			else	l = mid;
		}
		int x = check(r), y = x + r , ind = 1 , C = 0 , prv = 1;
		cout << x << sep << y << endl;
		for(int i = 1 ; i <= n ; i++){
			if(x <= A[i] && A[i] <= y){
				C++;
			}
			else{
				C--;
			}
			if((ind != k && C > 0) || (ind == k && i == n)){
				cout << prv << sep << i << endl;
				prv = i + 1;
				ind++;
				C = 0;
			}
		}
	}

    return 0;
}
/*

*/