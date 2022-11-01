#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair < int, int > ipair;

const int MAXN = 200000;

int n, k, s, t;
ipair car[MAXN];
int zap[MAXN];
int pref[MAXN];

int f(int d, int v)
{
    if(v >= 2*d)
        return d;
    int t1 = v - d;
    return t1 + (d - t1) * 2;
}

int can(int v)
{
    if(zap[0] > v) return t+1;
    int r = f(zap[0], v);
    for(int i = 1; i < k; i++)
    {
        if(zap[i] - zap[i-1] > v)
            return t+1;
        r += f(zap[i] - zap[i-1], v);
    }
    if(s - zap[k-1] > v)
        return t+1;
    return r + f(s - zap[k-1], v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> k >> s >> t;
    for(int i = 0; i < n; i++)
        cin >> car[i].first >> car[i].second;
    sort(car, car+n);
    for(int i = 0; i < k; i++)
        cin >> zap[i];
    sort(zap, zap+k);
    pref[0] = car[0].second;
    for(int i = 1; i < n; i++)
        pref[i] = max(pref[i-1], car[i].second);
    if(can(pref[n-1]) > t)
        return cout << -1, 0;
    int bl = 0, br = n-1;
    while(bl < br)
    {
        int bm = (bl + br) >> 1;
        if(can(pref[bm]) <= t)
            br = bm;
        else
            bl = bm + 1;
    }
    cout << car[bl].first;
}