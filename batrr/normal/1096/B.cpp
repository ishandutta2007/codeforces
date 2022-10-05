#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int n;
char s[N];
int main(){         
	scanf("%d", &n);
	scanf("%s", &s);
	ll l = 0, r = 0;     
	while(l < n && s[l] == s[0])
		l++;
    while(r < n && s[n - 1 - r] == s[n - 1])
		r++;
	l++, r++;
	cerr << l << " " << r << endl;
	if(s[0] == s[n - 1])
		printf("%lld", l * r % mod);
	else
		printf("%lld", l + r - 1);
	return 0;
}