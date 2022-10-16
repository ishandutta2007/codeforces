#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

const int NMAX = 3000 + 5;

priority_queue <int> pq;

int main() {
    int N;
    cin >> N;
    lint ans = 0;
    for (int i = 1; i <= N; ++ i) {
        int x;
        cin >> x;
        x -= i;
        if (i == 1 || x > pq.top())
            pq.push(x);
        else {
            pq.push(x), pq.push(x);
            ans += (pq.top() - x);
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}