#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll A = 31, mod = 1000000033LL;

vector<string> read(int n)
{
    vector<string> ans(n);
    for(auto &x: ans)
        cin >> x;
    return ans;
}

vector<ll> hsh(vector<string> vec, ll a)
{
    vector<ll> ans;
    for(auto x: vec)
    {
        ll h = 0;
        for(auto y: x)
            h = (h * a + (y - 'a')) % mod;
        ans.push_back(h);
    }
    return ans;
}

ll hsh(vector<ll> &vec, int beg, int end, ll a)
{
    ll h = 0;
    for(int i = beg; i < end; i++)
        h = (h * a + vec[i]) % mod;
    return h;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    ll Am = 1;
    for(int i = 0; i < m; i++)
        Am = Am * A % mod;
    auto m1 = read(n), tmp2 = read(m);
    vector<string> m2(n, string(m, ' '));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            m2[i][j] = tmp2[j][i];
            
    auto h1 = hsh(m1, A), h2 = hsh(m2, Am);
    vector<pair<ll, int>> vec;
    
    for(int i = 0; i + m <= n; i++)
        vec.emplace_back(hsh(h1, i, i + m, Am), i);
    sort(vec.begin(), vec.end());
    for(int i = 0; i + m <= n; i++)
    {
        auto h = hsh(h2, i, i + m, A);
        auto p = lower_bound(vec.begin(), vec.end(), make_pair( h, 0 ));
        if(p != vec.end() && p->first == h)
        {
            cout << p->second + 1 << " " << i + 1 << endl;
            return 0;
        }
    }
}