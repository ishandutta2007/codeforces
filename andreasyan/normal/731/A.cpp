#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
char a[N];

int main()
{
    cin >> a;
    n = strlen(a);
    int b = 'a';
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += min(abs(b - a[i]), min((b - 'a') + ('z' - a[i]) + 1, (a[i] - 'a') + ('z' - b) + 1));
        b = a[i];
    }
    cout << ans << endl;
    return 0;
}