#include <bits/stdc++.h>
using namespace std;

#define MAXN 312345

pair<int,int> s[MAXN];

int main(void)
{
    int n, k;
    multiset<int> l;

    long long total_length = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &s[i].second, &s[i].first);
    }

    sort(s, s+n);
    long long ans = 0;
    for (int i = n-1; i >= 0; i--)
    {
        int b = s[i].first;
        int t = s[i].second;

        total_length += t;
        l.insert(t);
        if (l.size() > k)
        {
            total_length -= *l.begin();
            l.erase(l.begin());
        }

        ans = max(ans, total_length * b);
    }

    cout << ans << endl;
}