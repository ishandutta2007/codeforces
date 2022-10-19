#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 200005;

ii a[N];
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].y;
    }
    sort(a + 1, a + n + 1);
    int cur = a[1].x - 1;
    priority_queue<ii> pq;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int foo = a[i].x;
        int t = min((int) pq.size(), foo - cur - 1);
        for (int j = 1; j <= t; j++) {
            int pos = cur + j;
            ans += 1LL * pq.top().x * (pos - pq.top().y);
            pq.pop();
        }
        pq.push({a[i].y, a[i].x});
        while (a[i + 1].x == a[i].x) {
            pq.push({a[i + 1].y, a[i + 1].x});
            i++;
        }
        ans += 1LL * pq.top().x * (foo - pq.top().y);
        pq.pop();
        cur = foo;
    }
    int t = (int) pq.size();
    for (int i = 1; i <= t; i++) {
        int pos = cur + i;
        ans += 1LL * pq.top().x * (pos - pq.top().y);
        pq.pop();
    }
    cout << ans;
    return 0;
}