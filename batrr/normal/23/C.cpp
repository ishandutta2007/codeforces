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

int t, n, m, k, ans[N], a[N], b[N], p[N], pp[N];
bool cmp(int i, int j){
	return a[i] < a[j] || (a[i] == a[j] && b[i] < b[j]);
}
int main()
{                         
	scanf("%d", &t);
	while(t--){
		k = m = 0;
		scanf("%d", &n);
		for(int i = 0; i < (2 * n - 1); i++){
			scanf("%d%d", &a[i], &b[i]);
			p[i] = i;
		}
		sort(p, p + (2 * n - 1), cmp);
		for(int i = 0; i < (2 * n - 1); i++)
			if(k && b[pp[k - 1]] <= b[p[i]])
				ans[m++] = p[i], k--;
			else
				pp[k++] = p[i];	
		for(int i = 0; i < k; i += 2)
			ans[m++] = pp[i];
		sort(ans, ans + n);
        puts("YES");
		for(int i = 0; i < n; i++)
			printf("%d ", ans[i] + 1);
		printf("\n");		
	}
	return 0;
}