#include <bits/stdc++.h>

using namespace std;

int a[10000];

main()
{
    int n;
    cin >> n;
    int q1;
    for (int i = 0; i< n; i++)
    {
        cin >> q1;
        a[i % 3] += q1;
    }
    if (max(max(a[0], a[1]), a[2]) == a[0])
        cout << "chest";
    else if (max(max(a[0], a[1]), a[2]) == a[1])
        cout << "biceps";
    else
        cout << "back";
}