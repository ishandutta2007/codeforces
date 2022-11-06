#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[200010];

bool chk[1000010];

vector<int> pri;
vector<int> pri2;

int res;

void solve(int p)
{
    int c = 0;
    for(int i = 0; i < n && c < res; i++)
    {
        if(arr[i] < p)
            c += p - arr[i];
        else
        {
            int t = arr[i] % p;
            c += min(t, p - t);
        }
    }
    res = min(res, c);
}

set<long long> vit;
void solve2(int p)
{
    if(!vit.insert(p).second)
        return;

    int c = 0;
    for(int i = 0; i < n && c < res; i++)
    {
        if(arr[i] < p)
            c += p - arr[i];
        else
        {
            int t = arr[i] % p;
            c += min(t, p - t);
        }
    }
    res = min(res, c);
}

void solvell(long long p)
{
    if(!vit.insert(p).second)
        return;

    long long c = 0;
    for(int i = 0; i < n && c < res; i++)
    {
        if(arr[i] < p)
            c += p - arr[i];
        else
        {
            long long t = arr[i] % p;
            c += min(t, p - t);
        }
    }
    res = min(0LL + res, c);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    auto st = clock();

    long long mn = *min_element(arr, arr + n);
    long long mx = *max_element(arr, arr + n);

    if(mn == mx)
    {
        if(mn == 1)
            printf("%d\n", n);
        else
            puts("0");
        return 0;
    }

    for(int p = 2; p < 1000010; p++)
    {
        if(chk[p])
            continue;

        pri.push_back(p);
        for(int i = 2 * p; i < 1000010; i += p)
            chk[i] = 1;
    }

    res = n;
    int idx = 0;
    for(int p : pri)
    {
        if(clock() - st > 1.5 * CLOCKS_PER_SEC)
            break;

        solve(p);
        idx++;
    }

    for(int i = idx; i < (int)pri.size(); i++)
        pri2.push_back(pri[i]);
    pri.resize(idx);

    vector<long long> v;
    v.push_back(mn);

    for(int i = 1; i < res; i++)
    {
        v.push_back(mn + i);
        if(mn - i >= 2)
            v.push_back(mn - i);
    }

    for(long long x : v)
    {
        if(x == 1)
            continue;

        if(clock() - st > 2.3 * CLOCKS_PER_SEC)
            break;

        long long t = x;
        for(int p : pri)
        {
            if(t % p == 0)
            {
                t /= p;
                while(t % p == 0)
                    t /= p;

                if(t == 1)
                    break;
            }
        }
        if(t == 1)
            continue;

        for(int p : pri2)
        {
            if(t % p == 0)
            {
                t /= p;
                while(t % p == 0)
                    t /= p;

                solve2(p);

                if(t == 1)
                    break;
            }
        }
        if(t == 1)
            continue;

        solvell(t);
    }

    printf("%d\n", res);
    return 0;
}