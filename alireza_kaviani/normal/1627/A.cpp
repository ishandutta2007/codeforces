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

int q , n , m , r , c;
string s[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m >> r >> c;
		r--; c--;
		int black = 0 , row = 0 , col = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> s[i];
			for(int j = 0 ; j < m ; j++){
				if(s[i][j] == 'B'){
					black = 1;
					if(i == r)	row = 1;
					if(j == c)	col = 1;
				}
			}
		}
		if(black == 0){
			cout << -1 << endl;
			continue;
		}
		if(s[r][c] == 'B'){
			cout << 0 << endl;
			continue;
		}
		if(row || col){
			cout << 1 << endl;
			continue;
		}
		cout << 2 << endl;
	}

    return 0;
}
/*

*/