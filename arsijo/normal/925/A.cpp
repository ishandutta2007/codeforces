#include<bits/stdc++.h>

using namespace std;

const int MaxN = 1e5 + 15;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

int n, m, cl, ce, v;

vector <int> vl, vr;

void solve()
{
    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;

    if(a == c)
    {
        cout << abs(d - b) << '\n';
        return;
    }

    long long res = INF;


    if(!vl.empty())
    {
        int l = 0;
        int r = vl.size() - 1;
        int ans = r;

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(vl[mid] < b)
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }

        for(int i = ans - 3; i <= ans + 3; ++i)
        {
            if(i >= 0 && i < vl.size())
            {
                int pos = vl[i];
                res = min(res, 0ll + abs(a - c) + abs(b - pos) + abs(d - pos));
            }
        }
    }
    if(!vr.empty())
    {
        int l = 0;
        int r = vr.size() - 1;
        int ans = r;

        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(vr[mid] < b)
                l = mid + 1;
            else
            {
                ans = mid;
                r = mid - 1;
            }
        }

        for(int i = ans - 3; i <= ans + 3; ++i)
        {
            if(i >= 0 && i < vr.size())
            {
                int pos = vr[i];
                long long D = abs(a - c);
                long long k = D / v;
                if(D % v)
                    ++k;

                res = min(res, 0ll + k + abs(b - pos) + abs(d - pos));
            }
        }
    }

    cout << res << '\n';
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> cl >> ce >> v;

    for(int i = 0; i < cl; ++i)
    {
        int x;
        cin >> x;
        vl.push_back(x);
    }

    for(int i = 0; i < ce; ++i)
    {
        int x;
        cin >> x;
        vr.push_back(x);
    }

    int q;
    cin >> q;
    while(q --> 0)
        solve();

    return 0;
}

///7