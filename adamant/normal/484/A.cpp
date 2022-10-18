#include <bits/stdc++.h>

using namespace std;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int64_t a, b;
        cin >> a >> b;
        bitset<65> x = a, y = b;
        bool ok = 0;
        for(int i = 64; i >= 0; i--)
        {
            if(ok) x[i] = 1;
            if(x[i] != y[i]) ok = 1;
        }
        a = x.to_ullong();
        if(__builtin_popcountll(b) > __builtin_popcountll(a)) a = b;
        cout << a << "\n";
    }
}