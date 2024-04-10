#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 100005;

int b, n;
int a[N];

int main()
{
    cin >> b >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (i == n - 1)
            ans = (ans + ((x % 2))) % 2;
        else
            ans = (ans + ((x % 2) * (b % 2))) % 2;
    }
    if (ans == 0)
        cout << "even" << endl;
    else
        cout << "odd" << endl;
    return 0;
}