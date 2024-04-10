#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e6 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int main(){
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	
	for(int i = 0; i < s.size(); ++i){
		if(i + 1 < s.size() && s[i + 1] < s[i]){
			puts("NO");
			return 0;
		}
		
		if(s[i] == 'a')
			++a;
		else if(s[i] == 'b')
			++b;
		else
			++c;
	}
	
	if(a == 0 || b == 0){
		puts("NO");
		return 0;
	}
	
	if(a != c && b != c){
		puts("NO");
		return 0;
	}
	
	puts("YES");
	return 0;
}