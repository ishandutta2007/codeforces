#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    if (n <= 2)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    cout << n - 1 << " ";
    for (int i = 1; i < n; i++)
        cout << i << " ";
    cout << "\n";
    cout << "1 " << n;
}