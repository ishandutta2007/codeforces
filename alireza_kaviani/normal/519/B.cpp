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

int n;
map<int , int> cnt[3];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < n - i ; j++){
			int x;
			cin >> x;
			cnt[i][x]++;
		}
	}
	for(auto &i : cnt[0]){
		int x = i.X;
		if(cnt[0][x] != cnt[1][x]){
			cout << x << endl;
		}
	}
	for(auto &i : cnt[0]){
		int x = i.X;
		if(cnt[1][x] != cnt[2][x]){
			cout << x << endl;
		}
	}
    return 0;
}
/*

*/