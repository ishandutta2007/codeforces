#include <bits/stdc++.h>
using namespace std;
const int N = 55;

int n;
long long k;

long long f[N];

vector<int> v;
int main()
{
    cin >> n >> k;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        f[i] = f[i - 1] + f[i - 2];
    while (1)
    {
        if (v.size() == n)
            break;
        int x = v.size() + 1;
        if (k <= f[n - v.size()])
        {
            v.push_back(x);
        }
        else
        {
            k -= f[n - v.size()];
            v.push_back(x + 1);
            v.push_back(x);
        }
    }
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
    return 0;
}