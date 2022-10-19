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

int n , ans , cnt[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		cnt[x]++;
	}
	for(int i = 1 ; i < MAXN ; i++){
		for(int j = i + i ; j < MAXN ; j += i){
			cnt[i] += cnt[j];
		}
	}
	for(int i = 1 ; i < MAXN ; i++){
		int flag = (cnt[i] > 0);
		for(int j = i + i ; j < MAXN ; j += i){
			if(cnt[i] == cnt[j]){
				flag = 0;
			}
		}
		ans += flag;
	}
	cout << ans - n << endl;

    return 0;
}
/*

*/