#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 2e5;
const int INF = 2e9;

ll a[N];
vector <ll> odd;

int main() {
    //freopen("a.in", "r", stdin);
    ll n;
    cin >> n;
    for (ll i = 30; i >= 0; (i--))
        if (n & (1 << i))
            cout << i + 1 << " ";
}