#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII  pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n, m;
string s1, s2;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> s1 >> s2;
	
	int t[4] = {0, 0, 0, 0};
	for(int i = 0; i < n; ++i){
		int b1 = s1[i] - '0', b2 = s2[i] - '0';
		t[2 * b1 + b2]++;
	}
	
	cout << 1LL * t[0] * t[2] + 1LL * t[0] * t[3] + 1LL * t[1] * t[2];
	return 0;
}