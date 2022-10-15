#include<bits/stdc++.h>

using namespace std;

const int MaxN = 3e2 + 15;
const int MOD = 1e9 + 7;
const long long INF = 1e18;

vector <long long> v[MaxN];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long cur = 0;

    for(int i = 0; i < n; ++i)
    {
        long long x;
        cin >> x;
        for(int bit = 60; bit >= 0; --bit)
        {
            if((1ll << bit) & x)
            {
                v[bit].push_back(x);
                break;
            }
        }
    }

    vector <long long> ans;

    for(int step = 0; step < n; ++step)
    {
        for(int pos = 0; pos <= 60; ++pos)
            if(!(cur & (1ll << pos)))
                if(!v[pos].empty())
                {
                    ans.push_back(v[pos].back());
                    cur ^= v[pos].back();
                    v[pos].pop_back();
                    break;
                }

        if(ans.size() != step + 1)
            return cout << "No\n", 0;
    }

    cout << "Yes\n";

    for(long long x : ans)
        cout << x << ' ';
    cout << '\n';

    return 0;
}

///7