#include <bits/stdc++.h>
 
using namespace std;

#define F first
#define S second 
#define pb push_back
#define mk make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
ll const inf = 1'000'000'000'000'000;
ll const mod = 1'000'000'007;
ll const max_n = 100'000 + 10;
ll a[max_n];

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0);
	ll p1 = 0;
    ll n;
    cin >> n;
    for (ll i = 0; i < n ; ++i) {
        cin >> a[i];
    }
    ll cnt = 0;
    sort(a, a + n);
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            --a[i];
            ++cnt;
            p1 = 1;
        }
    }
    if (cnt > 1){
        cout << "cslnb\n";
            return 0;
    }
    for (ll i = 0; i < n - 1; ++i) {
        if (a[i] == -1 || a[i] == a[i + 1]) {
            cout << "cslnb\n";
            return 0;
        }
    }
 
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += a[i];
    }
    ll pleh = sum - (n - 1) * n / 2;
    if (p1 == 0) {
        if (pleh % 2 == 0){
            cout << "cslnb\n";
            return 0;
        }
        else {
            cout <<  "sjfnb\n";
             return 0;
        }
 
    }
    if (p1 == 1) {
        if (pleh % 2 == 1){
            cout << "cslnb\n";
            return 0;
        }
        else{
            cout <<  "sjfnb\n";
            return 0;
        }
    }
	return 0;
}