#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1003;

int n;

bool c[N * N];
void pre()
{
    c[0] = true;
    c[1] = true;
    for (int i = 2; i < N * N; ++i)
    {
        if (c[i])
            continue;
        if (i * 1LL * i >= N * N)
            break;
        for (int j = i * i; j < N * N; j += i)
            c[j] = true;
    }
}

vector<pair<int, int> > ans;
int t[N];

void kpc(int x, int y)
{
    t[x]++;
    t[y]++;
    ans.push_back(m_p(x, y));
}

void solv()
{
    ans.clear();
    memset(t, 0, sizeof t);
    for (int i = 1; i < n; ++i)
    {
        kpc(i, i + 1);
    }
    kpc(n, 1);
    for (int i = 1; i <= n / 2; ++i)
    {
        if (!c[ans.size()])
            break;
        if (i + n / 2 <= n)
            kpc(i, i + n / 2);
    }
    if (c[ans.size()])
        cout << n << endl;
}

int main()
{
    pre();
    scanf("%d", &n);
    solv();
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    return 0;
}