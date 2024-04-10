#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[100000];

main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    for (int i = 0; i < (int)s.size(); i++)
        a[s[i]]++;
    for (int i = 0; i < 10000; i++)
        if (a[i] % k)
        {
            cout << -1;
            return 0;
        }
    for (int k1 = 0; k1 < k; k1++)
        for (int i = 0; i < 10000; i++)
            for (int j = 0; j < a[i] / k; j++)
                cout << (char)i;
}