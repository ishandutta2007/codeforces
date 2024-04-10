#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1LL * MX * MX;

bool can[N];

void solve(){
	for(int i = 'a'; i <= 'z'; ++i)
		can[i] = false;

	string s;
	cin >> s;
	
	for(int i = 0; i < (int)s.size(); ++i){
		int wsk = i;
		while(wsk + 1 < (int)s.size() && s[wsk + 1] == s[i])
			++wsk;
		
		if((wsk - i + 1) & 1)
			can[s[i]] = true;
		i = wsk;
	}
	
	for(int i = 'a'; i <= 'z'; ++i)
		if(can[i])
			cout << (char)i;
	cout << "\n";
}

int main(){
	int cases;
	cin >> cases;
	
	while(cases--)
		solve();
	return 0;
}