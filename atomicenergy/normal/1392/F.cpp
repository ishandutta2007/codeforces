using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
#include <assert.h>
#include <functional>
#include <math.h>
#include <ctime>

typedef long long ll;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //srand(time(NULL));

    long long n;
    cin >> n;
    vector<ll> v;
    ll tot = 0;
    ll a = 0;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;

        tot += x;
        a += i;
        v.push_back(x);
    }
    tot -= a;
    for (ll i = 0; i < n; i++) {
        if (i < tot % n) cout << (i + (tot / n) + 1) << " ";
        else cout << (i + (tot / n)) << " ";
    }
    cout << endl;




}