#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n;
bool ans[N];
char s[N];
ll k;
int main()
{
	int q;
	scanf("%d", &q);
	while(q--){
		scanf("%d%lld", &n, &k);
		scanf("%s", &s);
		int p = 0;
		for(int i = 0; i < n; i++)
			ans[i] = 0;
		for(int i = 0; i < n; i++)
			if(s[i] == '0'){
				ll x = min(k, (ll)i - p);
				k -= x;
				ans[i - x]++;
				p++;
			}
		for(int i = 0; i < n; i++)
			if(ans[i])      
				printf("0");
            else
            	printf("1");
		printf("\n");
	}
	return 0;
}