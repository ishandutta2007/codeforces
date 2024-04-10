#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n;
long long k;
char a[N];
vector<int> v;

void solv()
{
    scanf("%d%lld", &n, &k);
    scanf(" %s", a);
    v.clear();
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == '0')
            v.push_back(i);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] - i <= k)
        {
            k -= (v[i] - i);
            swap(a[i], a[v[i]]);
        }
        else
        {
            int x = v[i];
            while (k--)
            {
                swap(a[x], a[x - 1]);
                --x;
            }
            break;
        }
    }
    printf("%s\n", a);
}

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}