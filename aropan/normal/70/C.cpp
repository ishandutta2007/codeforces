#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>

using namespace std;

const int MAXM = 100001;
const int INF = (int)1e+9;

map < pair <int, int>, int > last;
int next[MAXM];
long long ansx = INF;
long long ansy = INF;
multiset <int> S;
int maxx, maxy, res;

int rev(int x)
{
    int res = 0;
    do res = res * 10 + x % 10; while (x /= 10);
    return res;
}

int main()
{
#ifdef ADEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    cin >> maxx >> maxy >> res;

    for (int i = max(maxx, maxy); i >= 1; i--)
    {
        int gcd = __gcd(i, rev(i));
        pair <int, int> p = make_pair(i / gcd, rev(i) / gcd);

        int &l = last[p];


        next[i] = l;
        l = i;
    }

    for (int i = 1; i <= maxx; i++)
    {
        int gcd = __gcd(i, rev(i));
        pair <int, int> p = make_pair(rev(i) / gcd, i / gcd);

        int j = last[p];
        while (j && j <= maxy)
        {
            S.insert(j);
            j = next[j];
        }


        if (S.size() < res) continue;

        multiset <int> :: iterator iter;

        while (S.size() > res)
        {
            iter = S.end();
            iter--;
            S.erase(iter);
        }

        iter = S.end();
        iter--;
        if (ansx * ansy > (long long)i * (long long)*iter)
        {
            ansx = i;
            ansy = *iter;
        }
    }
    if (ansx == INF)
        puts("-1");
    else
        cout << ansx << " " << ansy << endl;
    return 0;
}