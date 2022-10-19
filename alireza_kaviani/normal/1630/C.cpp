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

int n , A[MAXN] , L[MAXN] , R[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		L[A[i]] = (L[A[i]] == 0 ? i : L[A[i]]);
		R[A[i]] = i;
	}
	vector<pii> vec , vec2 , tot;
	for(int i = 0 ; i < MAXN ; i++){
		if(L[i] != R[i]){
			vec.push_back({L[i] , R[i]});
		}
	}
	sort(all(vec));
	for(pii i : vec){
		if(SZ(vec2) == 0 || vec2.back().Y < i.Y){
			vec2.push_back(i);
		}
	}
	if(SZ(vec2) == 0){
		return cout << 0 << endl , 0;
	}
	tot.push_back(vec2[0]);
	for(int i = 1 ; i + 1 < SZ(vec2) ; i++){
		if(vec2[i + 1].X <= tot.back().Y){
			continue;
		}
		tot.push_back(vec2[i]);
	}
	if(SZ(vec2) != 1){
		tot.push_back(vec2.back());
	}
	int ans = tot[0].Y - tot[0].X - SZ(tot) , prv = tot[0].Y + 1;
//	cout << ans << endl;
	for(int i = 1 ; i < SZ(tot) ; i++){
		int L = max(prv , tot[i].X) , R = tot[i].Y;
		ans += R - L + 1;
		if(prv <= tot[i].X){
			ans--;
		}
		prv = R + 1;
//		cout << L << sep << R << sep << ans << endl;
	}
	cout << ans << endl;

    return 0;
}
/*

*/