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
    int n, m;
    cin >> n;
    int a1, b1;
    cin >> a1;
    for (int i = 0; i < a1; i++)
        {cin >> a[i]; an[a[i]] = true;}
    cin >> b1;
    for (int i = 0; i < b1; i++)
    {
        cin >> b[i]; an[b[i]] = true;
    }
    for (int i = 1; i<=n; i++)
        if (!an[i])
    {
        cout << "Oh, my keyboard!";
        return 0;
    }
    cout << "I become the guy.";
}