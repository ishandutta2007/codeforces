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

int n, m, d, a[N], s;
int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for(int i = 1; i <= m; i++){
		scanf("%d", &a[i]);
		s += a[i];
	}
	if(s + (d - 1) * (m + 1) < n){
		puts("NO");
		return 0;
	}
	puts("YES");
	int x = n - s;
	for(int i = 1; i <= m + 1; i++){
		int y = min(d - 1, x);
		x -= y;
		while(y--)
			printf("0 ");				
		if(i <= m)
			while(a[i]--)
				printf("%d ", i);
	}
	
	return 0;
}