#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
struct ban
{
    int x1, x2;
    int y1, y2;
};
bool sox(const ban& a, const ban& b)
{
    return a.x2 < b.x2;
}
bool soy(const ban& a, const ban& b)
{
    return a.y2 < b.y2;
}

int n;
vector<ban> a;

int minu[N];

bool solv(vector<ban> a)
{
    int n = a.size();
    if (n == 1)
        return true;
    sort(a.begin(), a.end(), sox);
    minu[n - 1] = a[n - 1].x1;
    for (int i = n - 2; i >= 0; --i)
        minu[i] = min(minu[i + 1], a[i].x1);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i].x2 <= minu[i + 1])
        {
            vector<ban> l, r;
            for (int j = 0; j <= i; ++j)
                l.push_back(a[j]);
            for (int j = i + 1; j < n; ++j)
                r.push_back(a[j]);
            if (solv(l) && solv(r))
                return true;
            return false;
        }
    }
    sort(a.begin(), a.end(), soy);
    minu[n - 1] = a[n - 1].y1;
    for (int i = n - 2; i >= 0; --i)
        minu[i] = min(minu[i + 1], a[i].y1);
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i].y2 <= minu[i + 1])
        {
            vector<ban> l, r;
            for (int j = 0; j <= i; ++j)
                l.push_back(a[j]);
            for (int j = i + 1; j < n; ++j)
                r.push_back(a[j]);
            if (solv(l) && solv(r))
                return true;
            return false;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        ban t;
        cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
        a.push_back(t);
    }
    if (solv(a))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}