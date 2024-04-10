#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double DD;

#define PLL pair <LL, LL>
#define PII pair <int, int>
#define PDD pair <DD, DD>
#define mp make_pair
#define st first
#define nd second
#define pb push_back

string s;
set <string> S;
int both;

int main(){
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		S.insert(s);
	}
	
	for(int i = 1; i <= m; ++i){
		cin >> s;
		if(S.find(s) != S.end())
			both++;
	}
	
	if(both%2 == 1)
		n++;
	
	if(n > m)
		puts("YES");
	else
		puts("NO");
	return 0;
}