#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	n = s.size();
	
	int res = 0;
	s = s + s;
	
	for(int i = 0; i < n + n; ++i){
		int cur = 1;
		while(i + 1 < n + n && s[i + 1] != s[i]){
			++i; ++cur;
		}
		
		res = max(res, cur);
	}
	
	printf("%d\n", min(res, n));
	return 0;
}