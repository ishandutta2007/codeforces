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

int q , n , dp[MAXN];
string s[2];

int Mex(int x , int y){
	int flag0 = 0 , flag1 = 0; x--;
	for(int i = x ; i < y ; i++){
		for(int j = 0 ; j < 2 ; j++){
			if(s[j][i] == '0')	flag0 = 1;
			if(s[j][i] == '1')	flag1 = 1;
		}
	}
	if(flag0 == 0)	return 0;
	return 1 + flag1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> q;
	while(q--){
		cin >> n >> s[0] >> s[1];
		dp[1] = Mex(1 , 1);
		for(int i = 2 ; i <= n ; i++){
			dp[i] = max(dp[i - 1] + Mex(i , i) , dp[i - 2] + Mex(i - 1 , i));
		}
		cout << dp[n] << endl;
	}

    return 0;
}
/*

*/