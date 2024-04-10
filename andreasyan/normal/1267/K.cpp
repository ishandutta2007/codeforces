#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 102;

long long solvv(const vector<int>& v)
{
    long long ans = 1;
    int q = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
            q = 1;
        else
            ++q;
        ans *= (v.size() - max(0, v[i] - 1) - i);
        ans /= q;
    }
    return ans;
}

void solv()
{
    long long n;
    scanf("%I64d", &n);
    vector<int> v;
    for (int i = 2; n > 0; ++i)
    {
        v.push_back(n % i);
        n /= i;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long ans = solvv(v);
    if (v.back() == 0)
    {
        v.pop_back();
        ans -= solvv(v);
    }
    --ans;
    printf("%I64d\n", ans);
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}