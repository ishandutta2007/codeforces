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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    ld s = 0.0;
    for (int i = 0; i < n; i++)
        s += (ld)a[i];
    cout << ((double)(s / (ld)n));

}