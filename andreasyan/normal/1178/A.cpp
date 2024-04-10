#include <bits/stdc++.h>
using namespace std;
const int N = 102;

int n;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int sum = a[1];
    int ysum = a[1];
    vector<int> v;
    v.push_back(1);
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] * 2 <= a[1])
        {
            sum += a[i];
            v.push_back(i);
        }
        ysum += a[i];
    }
    if (sum * 2 > ysum)
    {
        cout << v.size() << endl;
        for (int i = 0; i < v.size(); ++i)
            cout << v[i] << ' ';
        cout << endl;
    }
    else
        cout << 0 << endl;
    return 0;
}