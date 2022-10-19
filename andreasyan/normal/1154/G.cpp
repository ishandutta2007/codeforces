#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
const int M = 10000007;
mt19937 rnd(123);
int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

vector<int> v[M];

long long ans;
int ansi, ansj;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (v[a[i]].size() < 2)
            v[a[i]].push_back(i);
    }
    ans = a[1] * 1LL * a[2] / gcd(a[1], a[2]);
    ansi = 1;
    ansj = 2;
    for (int gcd = 1; gcd < M; ++gcd)
    {
        vector<int> t;
        for (int x = gcd; x < M; x += gcd)
        {
            for (int i = 0; i < v[x].size(); ++i)
            {
                t.push_back(v[x][i]);
                if (t.size() == 2)
                    break;
            }
            if (t.size() == 2)
                break;
        }
        if (t.size() == 2 && a[t[0]] * 1LL * a[t[1]] / gcd < ans)
        {
            ans = a[t[0]] * 1LL * a[t[1]] / gcd;
            ansi = t[0];
            ansj = t[1];
        }
    }
    if (ansi > ansj)
        swap(ansi, ansj);
    cout << ansi << ' ' << ansj << endl;
    return 0;
}