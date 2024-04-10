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

int n , c , tot , cnt[MAXN];
vector<int> vec[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> c;
	for(int i = 0 ; i < n ; i++){
		int x;
		cin >> x;
		for(int j = 0 ; j < x ; j++){
			int k;
			cin >> k;
			vec[i].push_back(k);
		}
	}
	for(int i = 0 ; i + 1 < n ; i++){
		int ptr = 0;
		while(ptr < SZ(vec[i]) && ptr < SZ(vec[i + 1]) && vec[i][ptr] == vec[i + 1][ptr]){
			ptr++;
		}
		if(ptr == SZ(vec[i]))	continue;
		if(ptr == SZ(vec[i + 1])){
			return cout << -1 << endl , 0;
		}
		tot++;
		int x = c + 1 - vec[i][ptr] , y = c + 1 - vec[i + 1][ptr];
		if(x > y){
			cnt[0]++;
			cnt[c]--;
		}
		cnt[x]++;
		cnt[y]--;
	}
	partial_sum(cnt , cnt + MAXN , cnt);
	for(int i = 0 ; i < c ; i++){
		if(cnt[i] == tot){
			return cout << i << endl , 0;
		}
	}
	cout << -1 << endl;

    return 0;
}
/*

*/