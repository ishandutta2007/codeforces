#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 30000ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;
ll a[N];
ll b[N];
bool an[N];
bool am[N];
vector <int> np;

queue <pair <int, int> > q;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        q.push(make_pair(t, i));
    }
    while(!q.empty())
    {
        if (q.size() == 1)
        {
            cout << q.front().second + 1;
            return 0;
        }
        pair <int, int> tmp;
        tmp.first = q.front().first;
        tmp.second = q.front().second;
        q.pop();
        tmp.first -= m;
        if (tmp.first > 0)
            q.push(tmp);
    }

}