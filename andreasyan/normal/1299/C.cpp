#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
const int N = 1000006;

int n;
vector<pair<long double, int> > v;

int main()
{
    scanf("%d", &n);
    vector<pair<int, long double> > v;
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        v.push_back(m_p(1, x));
        while (v.size() >= 2 && (v[v.size() - 2].second + v[v.size() - 1].second) / (v[v.size() - 2].first + v[v.size() - 1].first) <= v[v.size() - 2].second / v[v.size() - 2].first)
        {
            v[v.size() - 2].first += v[v.size() - 1].first;
            v[v.size() - 2].second += v[v.size() - 1].second;
            v.pop_back();
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        double x = (v[i].second / v[i].first);
        for (int j = 0; j < v[i].first; ++j)
            printf("%.12f\n", x);
    }
    return 0;
}