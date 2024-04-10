#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, cnt[1000];
char s[N];
int main()
{
	scanf("%d", &n);
	scanf("%s", &s);
	for(int i = 0; i < n; i++)
		cnt[s[i]]++; 
	while(cnt['n']--)
		printf("1 ");
	while(cnt['z']--)
		printf("0 ");
	return 0;
}