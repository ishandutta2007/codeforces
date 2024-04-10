#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 300ll;
const ll MOD = 1000000007ll;
const ll P = 259ll;

ll a[N];
ll b[N];
bool an[N];
bool am[N];
vector <int> np;

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    int quasm = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] >= 'a' && s[i] <= 'z')
            quasm++;
    if (quasm >= (int)s.size() - quasm)
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] < 'a' || s[i] > 'z')
                s[i] -= 'A' - 'a';
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
            if (s[i] < 'A' || s[i] > 'Z')
                s[i] -= 'a' - 'A';
    }
    cout << s;
}