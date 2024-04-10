#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PDD pair <D, D>
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int T = 3 * N + 7;

const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
string s;

bool bad(char a){
	return a != 'a' && a != 'e' && a != 'o' && a != 'i' && a != 'u';
}

int main(){
	cin >> s, n = s.size();

	string res;
	int ile = 0, diff = 0;
	for(int i = 0; i < n; ++i){
		if(!bad(s[i])){
			ile = 0, diff = 0;
			res.pb(s[i]);
			continue;
		}
		
		++ile;
		if(i == 0 || s[i] != s[i - 1])
			++diff;
		
		if(ile >= 3 && diff >= 2){
			res.pb(' ');
			ile = 1, diff = 1;
		}
		
		res.pb(s[i]);
	}
	
	cout << res;
	return 0;
}