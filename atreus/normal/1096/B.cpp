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

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++){
		cnt1 = i;
		if (i > 0 and s[i] != s[i - 1])
			break;
	}
	for (int i = n - 1; i >= 0; i--){
		cnt2 = n - i - 1;
		if (i < n - 1 and s[i] != s[i + 1])
			break;
	}
	if (s[0] == s[n - 1]){
		cout << 1ll * (cnt1 + 1) * (cnt2 + 1) % mod << endl;
	}
	else {
		cout << (1ll * (cnt1 + 1) + (cnt2)) % mod << endl;
	}
}