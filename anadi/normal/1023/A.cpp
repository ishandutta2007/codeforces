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

int n, m;
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s >> t;
	if(t.size() + 1 < s.size()){
		puts("NO");
		return 0;
	}

	int pl = -1;
	for(int i = 0; i < s.size(); ++i)
		if(s[i] == '*')
			pl = i;
	
	if(pl == -1){
		if(s == t)
			puts("YES");
		else
			puts("NO");
		return 0;
	}
	
	for(int i = 0; i < pl; ++i)
		if(s[i] != t[i]){
			puts("NO");
			return 0;
		}
	
	int tt = t.size();
	for(int j = s.size() - 1; j > pl; --j)
		if(t[--tt] != s[j]){
			puts("NO");
			return 0;
		}

	puts("YES");
	return 0;
}