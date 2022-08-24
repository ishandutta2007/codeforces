#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    scanf("%d", &n);
    deque <int> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        q.push_back(x);
    }
    int cnt = 0;
    vector <int> res(2);
    while (q.size()) {
        res[cnt] += max(q.back(), q.front());
        cnt ^= 1;
        if (q.back() > q.front()) {
            q.pop_back();
        } else {
            q.pop_front();
        }
    }
    printf("%d %d\n", res[0], res[1]);
}