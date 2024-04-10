#include <bits/stdc++.h>
using namespace std;
const int N = 3003;

bool c[N];
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        c[x] = true;
    }
    for (int i = 1; ; ++i)
    {
        if (!c[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}