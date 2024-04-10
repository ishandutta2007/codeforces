#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    pair<int, int> b[n];
    for (int i = 0; i < n; i++)
    {
        b[i].first = 0;
        while (a[i] % 3 == 0)
        {
            a[i] /= 3;
            b[i].first--;
        }
        b[i].second = 0;
        while (a[i] % 2 == 0)
        {
            a[i] /= 2;
            b[i].second++;
        }
    }
    sort(b, b + n);
    long long t[100];
    t[0] = 1;
    long long p[100];
    p[0] = 1;
    for (int i = 1; i < 100; i++)
    {
        t[i] = t[i - 1] * 3;
        p[i] = p[i - 1] * 2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << t[-b[i].first] * p[b[i].second] * a[0] << " ";
    }
}