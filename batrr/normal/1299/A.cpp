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
 
int n, a[N], b[N], cnt[N];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		for(int j = 0; j < 30; j++)
			if((a[i] >> j) & 1)
				cnt[j]++;
	}
	int p = 1;
    for(int i = 1; i <= n; i++){
		for(int j = 0; j < 30; j++)
			if(((a[i] >> j) & 1) && cnt[j] == 1)
				b[i] |= (1 << j);
		if(b[p] < b[i])
			p = i;
	}
	printf("%d ", a[p]);
	for(int i = 1; i <= n; i++)
		if(i != p)
			printf("%d ", a[i]);
}