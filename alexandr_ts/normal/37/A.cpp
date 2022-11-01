#include <bits/stdc++.h>

using namespace std;

int a[100000];
int b[100000];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
            b[a[i]]++;
    }
    sort(b, b + 10000);
    cout << b[9999];
    int s = 0;
    for (int i = 0; i < 10000; i++)
        if (b[i])
            s++;
    cout << " " << s;
    return 0;
}