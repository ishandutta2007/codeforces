#include<bits/stdc++.h>
using namespace std;
const int MAXN = 202020;
int a[MAXN];
int b[MAXN];
long long ans = 0;
map<pair<int, int>, int> M;
int main()
{
    int N; scanf("%d", &N);
    for(int i=1; i<=N; ++i)
    {
        scanf("%d", a+i);
        ans += a[i];
    }
    int Q; scanf("%d", &Q);
    for(int i=0; i<Q; ++i)
    {
        int s, t, u; scanf("%d%d%d", &s, &t, &u);
        int x = M[{s,t}];
        if(x != 0)
        {
            ans -= max(a[x]-b[x], 0);
            b[x]--;
            ans += max(a[x]-b[x], 0);
        }
        //M[{s,t}] = 0 implicitly
        if(u != 0)
        {
            ans -= max(a[u]-b[u], 0);
            b[u]++;
            ans += max(a[u]-b[u], 0);
        }
        M[{s, t}] = u;
        printf("%lld\n", ans);
    }
}