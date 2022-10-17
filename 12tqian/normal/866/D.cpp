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
    priority_queue<int, vi, greater<int>> pq;
    ll ans = 0;
    f0r(i, n) {
        int p; cin >> p;
        ans -= p;
        f0r(j, 2) pq.push(p);
        pq.pop();
    }
    f0r(i, n) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << '\n';
    return 0;
}