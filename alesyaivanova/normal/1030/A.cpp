#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    bool t = true;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i])
            t = false;
    }
    if (t)
        cout << "EASY";
    else
        cout << "HARD";
}