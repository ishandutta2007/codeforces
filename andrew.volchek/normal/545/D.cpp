#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>
#include <string>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld lond double
#define mp make_pair
#define pb push_back
#define fst first
#define snd second

template<typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}



int main() {
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum <= a[i]) {
            ans++;
            sum += a[i];
        } else {
            
        }
    }
    cout << ans;

    return 0;
}