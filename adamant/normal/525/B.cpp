#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n;
    n = s.size();
    int m;
    cin >> m;
    map<int, int> x;
    while(m--)
    {
        int a;
        cin >> a;
        x[a] = (x[a] + 1) % 2;
    }
    vector<int> d;
    for(auto it: x)
        if(it.second)
            d.push_back(it.first - 1);
    d.push_back(n / 2 + 1);
    int j = 0;
    bool c = 0;
    for(int i = 0; 2 * i < n; i++)
    {
        if(d[j] == i)
        {
            j++;
            c ^= 1;
        }
        if(c)
            swap(s[i], s[n - i - 1]);
    }
    cout << s << "\n";
    return 0;
}