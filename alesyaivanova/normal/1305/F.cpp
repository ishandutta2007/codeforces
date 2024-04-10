#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ff first
#define ss second
#define pii pair<int, int>
#define pb emplace_back
#define pf emplace_front
#define mp make_pair
#define ld long double
#define all(x) x.begin(), x.end()
#define uniq(x) sort(all(x)), x.resize(unique(all(x)) - x.begin())

random_device rd;
mt19937_64 gen(rd());

template<typename T>
T rand(T l, T r) {
    uniform_int_distribution<T> uid(l, r);
    return uid(gen);
}

const int maxn = 1e6 + 9;
int a[maxn];
int n;
int inf = 1e18;
bool pr[maxn];
vector<int> primes;
int ANS;
int sz = 2000;

void kek_choice(vector<int>& kek)
{
    int cur = a[rand(0ll, n - 1)];
    cur += rand(-1, 1);
    for (int p : primes)
    {
        if (p * p > cur)
            break;
        if (cur % p == 0)
            kek.pb(p);
        while (cur % p == 0)
            cur /= p;
    }
    if (cur > 1)
        kek.pb(cur);
}

int get(int p)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < p)
            ans += p - a[i];
        else
            ans += min(a[i] % p, p - a[i] % p);
        if (ans >= ANS)
            return ans;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i < maxn; i++)
        pr[i] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (pr[i])
        {
            primes.pb(i);
            for (int e = i * 2; e < maxn; e += i)
                pr[e] = 0;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<int> s;
    ANS = n;
    while (clock() * 1000 / CLOCKS_PER_SEC < 2400)
    {
        vector<int> kek;
        kek_choice(kek);
        for (int p : kek)
        {
            if (s.find(p) != s.end())
                continue;
            ANS = min(ANS, get(p));
            s.insert(p);
        }
    }
    cout << ANS;
}