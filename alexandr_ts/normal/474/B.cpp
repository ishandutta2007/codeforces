#include <bits/stdc++.h>

#define fr(i, n) for (int i = 0; i < n; i++)

using namespace std;

typedef long long ll;

int a[1000000];
vector <int> b;

main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    fr(i, n)
    {
        cin >> a[i];
        fr(j, a[i])
            b.push_back(i);
    }
    int t;
    cin >> t;
    fr(i, t)
    {
        int tmp;
        cin >> tmp;
        cout << b[tmp - 1] + 1 << endl;
    }
}