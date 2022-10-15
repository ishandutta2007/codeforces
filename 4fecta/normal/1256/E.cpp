#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pt;

#define x first
#define y second
#define mp make_pair

const int N = 200043;
const int INF = int(1e9) + 43;

int n;
int dp[N];
int p[N];
pt a[N];
int t[N];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
    	a[i].y = i;
    	scanf("%d", &a[i].x);
    }
    sort(a, a + n);
    for(int i = 1; i <= n; i++)
    {
    	dp[i] = INF;
    	p[i] = -1;
    }
    for(int i = 0; i < n; i++)
    	for(int j = 3; j <= 5 && i + j <= n; j++)
    	{
    		int diff = a[i + j - 1].x - a[i].x;
    		if(dp[i + j] > dp[i] + diff)
    		{
    			p[i + j] = i;
    			dp[i + j] = dp[i] + diff;
    		}
    	}
    int cur = n;
    int cnt = 0;
    while(cur != 0)
    {
    	for(int i = cur - 1; i >= p[cur]; i--)
    		t[a[i].y] = cnt;
    	cnt++;
    	cur = p[cur]; 
    }
    printf("%d %d\n", dp[n], cnt);
    for(int i = 0; i < n; i++)
    {
    	if(i) printf(" ");
    	printf("%d", t[i] + 1); 
    }
    puts("");
    return 0;
}