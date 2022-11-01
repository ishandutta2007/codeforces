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

main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n ; i++)
        {cin >> a[i]; b[a[i]]++;}
    int s = 0;
    for (int i = 0; i <= 5 - k; i++)
        s += b[i];
    cout << s / 3;

}