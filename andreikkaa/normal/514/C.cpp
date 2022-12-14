#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const long long mod1 = 1e+9 + 7, mag1 = 5;

vector<long long> hf(const string& s)
{
    vector<long long> h(s.length() + 2);
    for(int i = 0; i < s.length(); ++i)
    {
        h[i + 1] = (h[i] * mag1 + (s[i] - 'a' + 1)) % mod1;
    }
    return h;
}
set<pair<pair<long long, long long>, char>> s[600001];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
    {
        string t;
        cin >> t;
        auto h1 = hf(t);
        reverse(t.begin(), t.end());
        auto h2 = hf(t);
        reverse(t.begin(), t.end());
        reverse(h2.begin(), h2.end());
        for(int j = 1; j <= t.length(); ++j)
        {
            s[t.length()].insert({{h1[j - 1], h2[j + 1]}, t[j - 1]});
        }
    }
    for(int i = 0; i < m; ++i)
    {
        string t;
        cin >> t;
        //cout << t << "!" << endl;
        auto h1 = hf(t);
        reverse(t.begin(), t.end());
        auto h2 = hf(t);
        reverse(t.begin(), t.end());
        reverse(h2.begin(), h2.end());
        bool st = true;
        for(int j = 1; j <= t.length(); ++j)
        {
            char av1;
            char av2;
            if(t[j - 1] == 'a')
                av1 = 'b', av2 = 'c';
            else if(t[j - 1] == 'b')
                av1 = 'a', av2 = 'c';
            else if(t[j - 1] == 'c')
                av1 = 'a', av2 = 'b';
            //cout << av1 << " " << av2 << endl;
            if(s[t.length()].find({{h1[j - 1], h2[j + 1]}, av1}) != s[t.length()].end())
            {
                cout << "YES" << endl;
                st = false;
                break;
            }
            if(s[t.length()].find({{h1[j - 1], h2[j + 1]}, av2}) != s[t.length()].end())
            {
                cout << "YES" << endl;
                st = false;
                break;
            }
        }
        if(st)
            cout << "NO" << endl;
    }
    return 0;
}