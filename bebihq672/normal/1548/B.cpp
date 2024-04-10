#include<bits/stdc++.h>
using namespace std;

long long a[202020];

long long gcd(long long x, long long y)
{
    if(x == 0)
        return y;
    if(y == 0)
        return x;
    return gcd(y, x % y);
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);

        int ans = 1;
        vector<pair<int, long long> > v;
        for(int i = 2; i <= n; i++)
        {
            long long w = abs(a[i] - a[i - 1]);
            
            v.push_back(make_pair(i, w));
            vector<pair<int, long long>> buf;
            for(int i = 0; i < (int)v.size(); i++)
            {
                long long cd = gcd(v[i].second, w);
                if(cd > 1)
                {
                    if(buf.size() == 0)
                        buf.push_back(make_pair(v[i].first, cd));
                    else if(buf[buf.size() - 1].second != cd)
                        buf.push_back(make_pair(v[i].first, cd));
                }
            }
            if(buf.size() > 0)
                ans = max(ans, i - buf[0].first + 2);
            v.clear();
            for(auto x: buf)
                v.push_back(x);
        }
        printf("%d\n", ans);
    }
    return 0;
}