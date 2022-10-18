#include <bits/stdc++.h>

using namespace std;



int main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    for(int i = 0; i <= c; i++)
    {
        if(c - a * i < 0)
            continue;
        if((c - a * i) % b == 0)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}