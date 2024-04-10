#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef pair < int, int > ipair;

const int MAXN = 200010;

int n, s;
int a[MAXN];
int mist0 = 0;
int cnt[MAXN];
int hi = 1;
int lvl[MAXN];
int say0 = 0;
int suff[MAXN];
int ans = INT_MAX;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    --s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        hi = max(hi, a[i]);
        if(i != s && a[i] == 0)
            say0++;
    }
    if(n == 1)
        return cout << 0, 0;
    if(a[s] != 0)
    {
        mist0 = 1;
        a[s] = 0;
    }
    for(int i = 0; i < n; i++)
        lvl[a[i]]++;
    suff[hi] = lvl[hi];
    for(int i = hi-1; i > 0; i--)
        suff[i] = suff[i+1] + lvl[i];
    int cfr = 0;
    for(int i = 1; i <= hi; i++)
    {
        if(lvl[i] == 0)
            cfr++;
        ans = min(ans, max(cfr, say0 + suff[i+1]));
    }
    cout << mist0 + ans;
}