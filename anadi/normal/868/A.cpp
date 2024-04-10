#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 1e5 + 7;
const int MX = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
int x[N], y[N];

string a;
string s;

int main(){
	cin >> a >> n;
	for(int i = 1; i <= n; ++i){
		cin >> s;
		x[s[0]] = true;
		y[s[1]] = true;
		
		if(s == a){
			puts("YES");
			return 0;
		}
	}
	
	if(y[a[0]] && x[a[1]])
		puts("YES");
	else
		puts("NO");
	return 0;
}