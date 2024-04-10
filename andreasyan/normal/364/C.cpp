#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 5003;

bool prime[N];
vector<int> pp;
void pre()
{
    for (int i = 0; i < N; ++i)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for (int i = 2; i < N; ++i)
    {
        if (!prime[i])
            continue;
        for (int j = i + i; j < N; j += i)
            prime[j] = false;
    }
}

int n;

set<int> ans;

int rec(int x)
{
    if (x > n * n * 2)
        return -1;
    if (ans.find(x) == ans.end())
        return x;
    for (int i = 0; i < 4; ++i)
    {
        int u = rec(x * pp[(rnd() % pp.size())]);
        if (u != -1)
            return u;
    }
    return -1;
}

int s[N];
int u[N];

bool solv()
{
    for (int i = 1; i <= n; ++i)
        s[i] = 1;
    for (int j = 1; j <= n; ++j)
        u[j] = j;
    for (int i = 0; i < pp.size(); ++i)
    {
        for (int j = n; j >= 1; --j)
            swap(u[j], u[(rnd() % j) + 1]);
        for (int j = 1; j <= n / 2 + n % 2; ++j)
            s[u[j]] *= pp[i];
    }
    sort(s + 1, s + n + 1);
    reverse(s + 1, s + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int x = rec(s[i]);
        if (x == -1)
            return false;
        ans.insert(x);
    }
    return true;
}

void solvv()
{
    scanf("%d", &n);
    for (int i = 15; ; --i)
    {
        pp.clear();
        for (int j = i; j >= 0; --j)
            if (prime[j])
                pp.push_back(j);
        if (pp.size() < 3)
            continue;
        ans.clear();
        if (solv())
        {
            for (auto it = ans.begin(); it != ans.end(); ++it)
                printf("%d ", *it);
            printf("\n");
            return;
        }
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    solvv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}