#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b)
{
    if(a > b)
        swap(a, b);
    while(b != 0)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}


int main()
{
    int n;
    cin >> n;
    int w[n];
    int c[n];
    for(int i = 0; i < n; ++i)
        cin >> w[i];
    for(int i = 0; i < n; ++i)
        cin >> c[i];

    pair<int, int> v[n];
    for(int i = 0; i < n; ++i)
        v[i] = {w[i], c[i]};
    sort(v, v + n);
    /*for(int i = 0; i < n; ++i)
    {
        cout << i << " " << v[i].first << " " << v[i].second << endl;
    }*/
    int ans = 1000000000;
    for(int i = 0; i < n; ++i)
    {
        map<int, int> s;
        s[v[i].first] = v[i].second;
        for(int j = i + 1; j < n; ++j)
        {
            vector<pair<int, int>> z;
            for(auto k : s)
            {
                /*cout << k.first << " " << k.second << " -> ";
                cout << gcd(k.first, v[j].first) << " " << k.second + v[j].second << endl;*/
                z.push_back({gcd(k.first, v[j].first), k.second + v[j].second});
            }
            for(auto k : z)
            {
                //cout << i << " " << j << " " << k.first << " " << k.second << endl;
                if(s.find(k.first) == s.end())
                    s[k.first] = k.second;
                else
                    s[k.first] = min(s[k.first], k.second);
            }
        }
        if(s.find(1) != s.end())
            ans = min(ans, s[1]);
    }
    if(ans == 1000000000)
    {
        cout << -1;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}