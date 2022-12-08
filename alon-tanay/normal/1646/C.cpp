#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define ppi pair<int,pi>
#define MOD 1000000007

using namespace std;

vector<ll> fct = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200};

ll x;
ll sol = 10000000;
ll dif = 0;
void rec(int i = 0, ll curr = x) {
    if(i == fct.size()) {
        sol = min(sol,dif+bitset<42>(curr).count());
        return;
    }
    rec(i + 1, curr);
    dif ++;
    rec(i + 1, curr - fct[i]);
    dif --;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> x;
        sol = 10000000;
        rec();
        cout << sol << "\n";
    }
    return 0;
}