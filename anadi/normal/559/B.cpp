#include <bits/stdc++.h>

using namespace std;

typedef double D;
typedef long long int LL;

#define st first
#define nd second
#define pb push_back
#define PLL pair <LL, LL>
#define PII pair <int, int>

const int N = 2e5 + 7;
const int MX = 1e9 + 7;
const LL INF = 1e18 + 9LL;

int n;
string s, t;

bool equal(int s1, int e1, int s2, int e2){
	for(int i = s1; i <= e1; ++i)
		if(s[i] != t[i - s1 + s2])
			return false;
	return true;
}

bool ok(int s1, int e1, int s2, int e2){
	if((e1 - s1 + 1) & 1)
		return equal(s1, e1, s2, e2);
	
	int m1 = (s1 + e1) / 2, m2 = (s2 + e2) / 2;
	if(rand() & 1){
		if(!ok(s1, m1, s2, m2))
			return ok(s1, m1, m2 + 1, e2) && ok(m1 + 1, e1, s2, m2);
		return ok(m1 + 1, e1, m2 + 1, e2);
	}

	if(!ok(s1, m1, m2 + 1, e2))
		return ok(s1, m1, s2, m2) && ok(m1 + 1, e1, m2 + 1, e2);
	return ok(m1 + 1, e1, s2, m2);
}

int main(){
	cin >> s >> t;
	n = s.size();
	
	if(ok(0, n - 1, 0, n - 1))
		puts("YES");
	else
		puts("NO");
	return 0;
}