#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, a, b;
        priority_queue<int> pq;
        scanf("%d%d%d%d", &n, &m, &a, &b);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x;
            scanf("%d", &x);
            pq.push(x);
        }
        int numFired = abs(a-b)-1;
        int timeAlive = 0;
        if (a < b) {
            timeAlive = b-1;
        } else {
            timeAlive = n-b;
        }
        //printf("%d %d\n", timeAlive, numFired);
        for (int i = 1; i <= min(numFired, m); i++) {
            while (pq.size() && pq.top()+i > timeAlive) {
                pq.pop();
            }
            if (pq.size()) {
                ans++;
                pq.pop();
            }
        }
        printf("%d\n", ans);
    }
}