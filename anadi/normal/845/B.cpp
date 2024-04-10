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
const int inf = 1e9 + 9;

string s;

int ile(int nr){
	int cur = 0;
	int ret = 0;
	int s1 = 0, s2 = 0;
	for(int i = 1; i < 1e6; i *= 10){
		if(i < 1000)
			s1 += (nr / i)%10;
		else
			s2 += (nr / i)%10;

		if((nr / i)%10 != s[cur] - '0')
			++ret;
		++cur;
	}
	
	return s1 == s2 ? ret : 10;
}

int main(){
	cin >> s;
	int cur = 10;
	for(int i = 0; i < 1e6; ++i)
		cur = min(cur, ile(i));
	cout << cur << "\n";
	return 0;
}