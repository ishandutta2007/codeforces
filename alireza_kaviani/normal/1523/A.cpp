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

int q , n , m , val[MAXN] , val2[MAXN];
string s;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> m >> s; s = "." + s + ".";
		fill(val , val + n + 5 , 0);
		fill(val2 , val2 + n + 5 , 0);
		for(int i = 1 ; i <= n ; i++){
			if(s[i] == '1')	val[i] = val2[i] = 1;
		}
		for(int i = 1 ; i <= min(n , m) ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(val[j - 1] ^ val[j + 1])	val2[j] = 1;
			}
			for(int j = 1 ; j <= n ; j++)	val[j] = val2[j];
		}
		for(int i = 1 ; i <= n ; i++)	cout << val[i];
		cout << endl;
	}

    return 0;
}
/*

*/