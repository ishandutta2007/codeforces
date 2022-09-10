#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	
	cin >> n >> s;
	
	int ans = 0;
	int cur = 0;
	int last = -1;
	
	for(int i = 0; i < n; ++i){
		if(s[i] == '('){
			++cur;
			if(cur == 0)
				ans += i - last;
		}
		else
			--cur;
		
		if(cur == 0)
			last = i;
	}
	
	if(cur != 0)
		puts("-1");
	else
		printf("%d\n", ans);
	return 0;
}