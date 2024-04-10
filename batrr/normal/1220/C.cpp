#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)5e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

char s[N];
int n, mn;
int main()
{
	scanf("%s", &s);
	n = strlen(s);
	mn = inf;
	for(int i = 0; i < n; i++){
		if(mn >= s[i])        
			printf("Mike\n");
		else
			printf("Ann\n");
		mn = min(mn, (int)s[i]);	
	}
	return 0;
}