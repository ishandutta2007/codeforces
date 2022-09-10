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
const LL INF = 1e18 + 17LL;

string s;

int main(){
	cin >> s;
	int res = 0, last = 0;
	while(s.size() > 0 && s[s.size() - 1] == '9')
		res += 9, s.pop_back();
	
	if(s.size() == 0){
		printf("%d\n", res);
		return 0;
	}
	
	for(int i = s.size() - 1; i >= 1; --i){
		res += s[i] - '0' + 10 - last;
		last = true;
	}
	
	res += s[0] - '0' - last;
	printf("%d\n", res);
	return 0;
}