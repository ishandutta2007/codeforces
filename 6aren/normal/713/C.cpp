#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    long long ans = 0;
    priority_queue<int> pq;
    for (int e : a) {
        if (pq.empty() || pq.top() <= e) pq.push(e);
        else {
            pq.push(e);
            pq.push(e);
            int u = pq.top(); pq.pop();
            ans += u - e;
        }
    }
    cout << ans;
    return 0;
}