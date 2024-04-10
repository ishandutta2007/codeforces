#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n;
vector<int> pr, pr2;
ll lim = 1e18, lim2=1e9;

ll VAL = -1;
ll ask(ll x) {
    if(x == 1) return 1;
    if(VAL != -1) return __gcd(VAL, x);
    cout << "? " << x << endl;
    ll ans;
    cin >> ans;
    return ans;
}
ll calc(ll ans, ll p) {
    ll cur = 1;
    while(cur * p * ans <= lim2) cur *= p;
    return cur;
}

void solve() {
    ll ans = 1;

    vector<int> P;

    for(int i = 0; i < pr.size(); ) {
        ll cur = 1;
        int j=i;
        while(i < pr.size() && lim/cur >= pr[i] && cur * pr[i] <= lim) {
            cur *= pr[i];
            i++;
        }
        ll val = ask(cur);
        ans *= val;
        for(int k = j; k < i; k++) if(val % pr[k] == 0) P.push_back(pr[k]);
    }
    if(ans == 1) {
        cout <<"! " << 8 << endl;
        return;
    }
    ll cnt = 1;
    ll cur = 1;
    for(int i = 0; i < P.size(); i++) {
        ll val = calc(ans, P[i]);
        if(val <= lim/cur && cur * val <= lim) {
            cur *= val;
        }else {
            ll C = ask(cur);
            ans = ans * C / __gcd(ans, C);
            cur = val;
        }
    }
    ll C = ask(cur);
    ans = ans * C/__gcd(ans, C);
    for(int i = 0; i < pr.size(); i++) {
        ll cnt2 = 0;
        while(ans % pr[i] == 0) {
            ans /= pr[i];
            cnt2++;
        }
        cnt *= cnt2+1;
    }
    cout << "! " << cnt * 2 << "\n";
}


int main() {
    for(int i = 2; i <= 800; i++) {
        int good = 1;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) good = 0;
        }
        if(good) pr.push_back(i);
    }
    for(int i = 2; i <= 1000; i++) {
        int good = 1;
        for(int j = 2; j < i; j++) {
            if(i % j == 0) good = 0;
        }
        if(good) pr2.push_back(i);
    }
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}