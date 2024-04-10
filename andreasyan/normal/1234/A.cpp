#include <bits/stdc++.h>
using namespace std;
const int N = 103;

int n;
void solv()
{
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
    }
    cout << (sum / n) + !!(sum % n) << endl;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
        solv();
    return 0;
}