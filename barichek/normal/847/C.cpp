#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;
typedef long long ll;

int n;
ll k;
ll cnt[MAXN];

int main() {
    #ifdef Fekete
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else

    #endif // Fekete

//    ios::sync_with_stdio(false);
  //  cin.tie(nullptr);


    cin >> n >> k;
    if(2 * k > 1ll *n * (n - 1)) return cout << "Impossible", 0;
    ll s = 1;
    while(s * (s + 1) / 2 <= k) s++;
    k -= s * (s - 1) / 2;
    if(s > n) return cout << "Impossible", 0;

    for(int i = 0; i < s; i++) {
        cnt[i]++;
    }
    for(int i = s - 1; i >= 1; i--) {
        cnt[i] += k / i;
        k %= i;
    }

    ll total = 0;
    for(int i = 0; i < s; i++) total += cnt[i];
    if(total > n) {
        return cout << "Impossible", 0;
    }

    string ss = "";
    for(int i = 0; i < s; i++) {
        for(int j = 1; j < cnt[i]; j++) {
            ss += "()";
        }
        ss += "(";
    }
    for(int i = 0; i < s; i++) {
        ss += ")";
    }
    while(ss.size() < 2 * n) {
        ss += "()";
    }
    //cerr << ss << endl;
    if(ss.size() > 2 * n) {
        cout << "Impossible";
    }
    else {
        cout << ss;
    }
}