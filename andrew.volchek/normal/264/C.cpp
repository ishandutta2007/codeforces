#include <cstdio>
#include <algorithm>
#include <functional>


using namespace std;

const int maxn = 100005;
int v[maxn];
int c[maxn];
int n, q;
long long dp[maxn];
const long long inf = 1000000000000;

int main()
{
    scanf("%d %d\n", &n, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &c[i]);
        
    while (q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        long long curr_max = 0;
        pair < long long, int > m[3];
        
        for (int i = 0; i <= n; i++)
            dp[i] = -inf;
            
        m[0] = make_pair(0, -1);
        m[1] = make_pair(0, -1);
        m[2] = make_pair(0, -1);
        
        for (int i = 0; i < n; i++)
        {
            long long curr = -inf;
            
            long long prmax = -inf;
            
            for (int j = 0; j < 2; j++)
                if (m[j].second != c[i])
                    prmax = max(m[j].first, prmax);
                
            curr = prmax + (long long)v[i] * b;
            if (dp[c[i]] != -inf)
                curr = max(curr, dp[c[i]] + (long long)v[i] * a);
                
            dp[c[i]] = max(dp[c[i]], curr);
            curr_max = max(curr_max, curr);
            
            if (m[0].second == c[i])
                m[0].first = max(m[0].first, curr);
            else if (m[1].second == c[i])
                m[1].first = max(m[1].first, curr);
            else
            {
                m[2].first = curr;
                m[2].second = c[i];
                sort(m, m+3, greater< pair<long long, int> >());
            }
        }
        
        printf("%I64d\n", curr_max);
    }
}