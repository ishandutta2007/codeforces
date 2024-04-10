#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 77779;
const long long M = 777777777777, MM = 10000007;

void por()
{
    vector<pair<pair<long long, long long>, int> > v;
    v.push_back(m_p(m_p(0, 0), 0));
    for (long long i = 1; i <= MM; ++i)
    {
        long double rr = i;
        rr = sqrt(rr);
        long double ll = sqrt(rr);
        long long l = ll;
        if (ll != l)
            ++l;
        long long r = rr;
        set<int> s;
        for (int j = 0; j < v.size(); ++j)
        {
            if (max(l, v[j].first.first) <= min(r, v[j].first.second))
                s.insert(v[j].second);
        }
        for (int k = 0; ; ++k)
        {
            if (s.find(k) == s.end())
            {
                if (k == v.back().second)
                    v.back().first.second++;
                else
                {
                    cout << i << ' ' << k << endl;
                    v.push_back(m_p(m_p(i, i), k));
                }
                break;
            }
        }
    }
    long long bl = MM + 1;
    long long br = M;
    long long ans = -1;
    int kk = -1;
    while (bl <= br)
    {
        long long i = (bl + br) / 2;
        long double rr = i;
        rr = sqrt(rr);
        long double ll = sqrt(rr);
        long long l = ll;
        if (ll != l)
            ++l;
        long long r = rr;
        set<int> s;
        for (int j = 0; j < v.size(); ++j)
        {
            if (max(l, v[j].first.first) <= min(r, v[j].first.second))
                s.insert(v[j].second);
        }
        int k;
        for (k = 0; ; ++k)
        {
            if (s.find(k) == s.end())
                break;
        }
        if (k == 1)
            bl = i + 1;
        else
        {
            kk = k;
            ans = i;
            br = i - 1;
        }
    }
    cout << ans << ' ' << kk << endl;
}

void solv()
{
    int ans = 0;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        long long x;
        scanf("%I64d", &x);
        if (x >= 2562991876LL)
            ans ^= 2;
        else if (x >= 50626)
            ans ^= 1;
        else if (x >= 6724)
            ans ^= 3;
        else if (x >= 82)
            ans ^= 0;
        else if (x >= 16)
            ans ^= 2;
        else if (x >= 4)
            ans ^= 1;
    }
    if (ans)
        printf("Furlo\n");
    else
        printf("Rublo\n");
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    //por();
    //return 0;
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}