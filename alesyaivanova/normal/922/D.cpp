#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(pair<long long, int> a, pair<long long, int> b)
{
    return a.first * b.second > a.second * b.first;
}

int main()
{
    int n;
    cin >> n;
    long long ans = 0;
    pair<long long, int> t[n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int c = 0;
        int h = 0;
        for (unsigned int e = 0; e < s.size(); e++)
        {
            if (s[e] == 's')
                c++;
            else
                ans += c, h++;
        }
        t[i].first = c;
        t[i].second = h;
    }
    sort(t, t + n, cmp);
    long long k = 0;
    for (int i = 0; i < n; i++)
    {
        ans += k * t[i].second;
        k += t[i].first;
    }
    cout << ans;
}