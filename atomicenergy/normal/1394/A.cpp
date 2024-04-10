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
    ll n, d, m;
    cin >> n >> d >> m;

    vector<ll> a;
    vector<ll> b;
    vector<ll> prefa(1, 0);
    vector<ll> prefb(1, 0);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x <= m) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    for (auto i : a) prefa.push_back(prefa.back() + i);
    for (auto i : b) prefb.push_back(prefb.back() + i);
    ll bst = -1;
    for (ll i = 0; i <= n; i++) {
        if (b.size() < i) continue;
        if (i == 0) {
            if (b.size() > 0) continue;
            cout << prefa[a.size()] << endl;
            return 0;
        }
        if ( b.size() > (i) * (d + 1)) continue;
        
        ll toignore = max(i * (d + 1) - d - (ll)b.size(), (ll)0);
        if (a.size() < toignore) continue;
        //cout << i << "!" << a.size() - toignore << endl;
        ll cur = prefb[i] + prefa[a.size() - toignore];
        //cout << i << " " << cur << endl;
        if (cur > bst) bst = cur;
    }
    cout << bst << endl;

}