#include <bits/stdc++.h>
using namespace std;

long long n;

int main()
{
    cin >> n;
    /*for (int i = 1; i <= n; ++i)
    {
        set<int> s;
        s.insert(1);
        int j = 1 + i;
        j %= n;
        while (j != 1)
        {
            s.insert(j);
            j += i;
            j %= n;
        }
        cout << i << ' ';
        if (s.size() == n)
            cout << 0 << endl;
        else
            cout << s.size() << endl;
    }*/
    vector<long long> v;
    for (long long i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            long long ii = i;
            i = n / i;
            long long m = n / i;
            long long d = i;
            long long a1 = 1;
            long long am = a1 + (m - 1) * d;
            v.push_back(((a1 + am) * m) / 2);
            i = ii;
            m = n / i;
            d = i;
            a1 = 1;
            am = a1 + (m - 1) * d;
            v.push_back(((a1 + am) * m) / 2);
        }
    }
    v.push_back(1);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i)
    {
        if (!i || v[i] != v[i - 1])
            cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}