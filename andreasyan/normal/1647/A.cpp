#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);

void solv()
{
    int n;
    vector<int> v;

    cin >> n;
    while (n > 1)
    {
        if (v.empty() || v.back() == 1)
            v.push_back(2);
        else
            v.push_back(1);
        n -= v.back();
    }

    if (n == 1)
    {
        reverse(all(v));
        v.push_back(1);
    }

    for (int i = 0; i < sz(v); ++i)
        cout << v[i];
    cout << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}