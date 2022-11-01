#include<bits/stdc++.h>
#define x first
#define y second
#define size(a) (ll)(a).size()

typedef long long ll;
typedef long double ld;

using namespace std;
ll n, k, m, t;
string s;


int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");


    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> k >> m >> t;

    vector<ll> Mvs(n, 0);

    Mvs[k - 1] = 1;

    while (t--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int pos;
            cin >> pos;
            pos--;
            Mvs.insert(Mvs.begin() + pos, 0);
        }
        else
        {
            int pos;
            cin >> pos;

            bool ok = 0;
            for (int i = 0; i < pos; i++)
            {
                if (Mvs[i])
                {
                    ok = 1;
                }
            }

            //cout << ok << ' ';
            if (!ok)
            {
                Mvs.erase(Mvs.begin(), Mvs.begin() + pos);
            }
            else
            {
                Mvs.erase(Mvs.begin() + pos, Mvs.end());
            }
        }

        cout << size(Mvs) << ' ';

        for (int i = 0; i < size(Mvs); i++)
        {
            if (Mvs[i] == 1)
            {
                cout << i + 1 << " ";
                break;
            }
        }

        cout << "\n";
    }



}