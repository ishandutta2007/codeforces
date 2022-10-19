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

int q , n , m;
string s[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m;
		int flag1 = 0 , flag2 = 0;
		for(int i = 0 ; i < n ; i++){
			cin >> s[i];
			for(int j = 0 ; j < m ; j++){
				if(s[i][j] == 'W' && (i + j) % 2 == 0)	flag1 = 1;
				if(s[i][j] == 'W' && (i + j) % 2 == 1)	flag2 = 1;
				if(s[i][j] == 'R' && (i + j) % 2 == 0)	flag2 = 1;
				if(s[i][j] == 'R' && (i + j) % 2 == 1)	flag1 = 1;							
			}
		}
		if(flag1 && flag2){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		int cur = (flag1 ? 0 : 1);
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cout << ((i + j) % 2 == cur ? 'W' : 'R');
			}
			cout << endl;
		}
	}

    return 0;
}
/*

*/