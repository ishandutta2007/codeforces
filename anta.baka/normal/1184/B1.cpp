#include<bits/stdc++.h>
#define x first
#define y second
#define size(a) (ll)(a).size()

typedef long long ll;
typedef long double ld;

using namespace std;
ll n, m;
string s;


int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");


    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    vector<int> Num(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> Num[i];
    }

    vector<pair<ll, ll>> Base(m);

    for (int i = 0; i < m; i++)
    {
        cin >> Base[i].x >> Base[i].y;
    }

    sort(Base.begin(), Base.end());

    vector<ll> Pref(m);

    Pref[0] = Base[0].y;

    for (int i = 1; i < m; i++)
    {
        Pref[i] = Pref[i - 1] + Base[i].y;
    }

    for (int i = 0; i < n; i++)
    {
        ll l = -1, r = m;

        while (r - l > 1)
        {
            int mid = (l + r) / 2;

            if (Base[mid].x <= Num[i])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }

        if (l == -1)
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << Pref[l] << ' ';
        }
    }

}