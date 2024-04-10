#include <bits/stdc++.h>

using namespace std;

#define f1r(i, a, b) for (int i = a; i < b; i++) 
#define f0r(i, a) f1r(i, 0, a)
#define trav(t, a) for (auto& t : a)
#define eb emplace_back
#define pb push_back
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) (x).begin(), (x).end()

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;

int main() {
    int n; cin >> n;
    vl a(n);
    f0r(i, n) cin >> a[i], a[i] -= i;
    priority_queue<int> pq;
    ll ans = 0; // stores the right y intercept
    f0r(i, n) {
        ans -= a[i];
        f0r(j, 2) pq.push(a[i]);
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
    return 0;
}