#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, p;
    cin >> n >> p;
    
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    
    ll nowApples = 0, money = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == "half")
        {
            money += nowApples * p;
            nowApples *= 2;
        }
        else
        {
            money += nowApples * p + p / 2;
            nowApples *= 2;
            nowApples++;
        }
    }
    cout << money << endl;
    
    return 0;
}