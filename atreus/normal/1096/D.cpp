#include <bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int mod = 998244353;
const int maxn = 1e5 + 100;

ll a[maxn], dp[5];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++){
		if (s[i] == 'h'){
			dp[0] += a[i];
		}
		else if (s[i] == 'a'){
			dp[1] = min(dp[0], dp[1] + a[i]);
		}
		else if (s[i] == 'r'){
			dp[2] = min(dp[1], dp[2] + a[i]);
		}
		else if (s[i] == 'd'){
			dp[3] = min(dp[2], dp[3] + a[i]);
		}
		else{
			continue;
		}
	}
	cout << dp[3] << endl;
}