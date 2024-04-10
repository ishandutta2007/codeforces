#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, mare, mic, t, act;

int main()
{
    ios::sync_with_stdio(false);

    cin >> t;

    while(t--)
    {
        cin >> a >> b >> c >> d;

        mare = 0;
        mic = 0;

        if(a || d) mare = 1;
        if(b || c) mic = 1;

        act = 1;

        a %= 2;

        while(a)
        {
            act *= -1;
            --a;
        }

        b %= 2;

        while(b)
        {
            act *= -1;
            --b;
        }

        if(act == -1 && mare) cout << "Ya ";
        else cout << "Tidak ";

        if(act == -1 && mic) cout << "Ya ";
        else cout << "Tidak ";

        if(act == 1 && mic) cout << "Ya ";
        else cout << "Tidak ";

        if(act == 1 && mare) cout << "Ya ";
        else cout << "Tidak ";

        cout << '\n';
    }

    return 0;
}