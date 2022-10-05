#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m;
string s[N];
int ans;
int r(char c){
	if(c == '1')
		return '0';
	return '1';
}
int main()
{
	m = 10000;
	cin >> n;
	cin >> s[0];
	for(int j = 1; j <= m; j++)
		s[j] = s[j - 1];
	
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		for(int j = b; j <= m; j += a + a)
			for(int q = 0; q < a && j + q <= m; q++)
				s[j + q][i] = r(s[j + q][i]);
	}
	for(int i = 0; i <= m; i++){
		int cur = 0;
		for(int j = 0; j < n; j++)
			if(s[i][j] == '1')
				cur++;
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}