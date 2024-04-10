#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

int a[10000];

main()
{
    int n;
    cin >> n;
    fr(i, n - 1)
        cin >> a[i];
    int b, c;
    cin >> b >> c;
    b--, c--;
    int s = 0;
    for (int i = b; i < c; i++)
        s += a[i];
    cout << s;
}