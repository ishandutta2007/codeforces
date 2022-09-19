#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const long MOD = (long)1e9 + 7;
ll const MAXN = 100001;


int main(){
    ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    ll n, m, a;
    cin >> n >> m >> a;
    cout << ((n + a - 1)/a)*((m + a - 1)/a);

    return 0;
}