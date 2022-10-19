#include <iostream>
#include <queue>

using namespace std;

#define M 100100

struct Node {
    Node * next;
    int val;
    Node() : next(NULL) {}
} a[M];

queue<pair<Node *, int>> q; 
int n;

void read() {
    cin >> n;

    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        a[i].val = x;
    }

    for (int i = 0; i + 1 < n; ++i) {
        a[i].next = a + (i + 1);
    }
}

void kill() {
    for (int i = n - 2; i >= 0; --i)
        if (a[i].val > a[i + 1].val)
            q.emplace(a + i, 1);

    int ans = 0;
    while (!q.empty()) {
        Node * x = q.front().first;
        ans = q.front().second;
        q.pop();
        x -> next = (x -> next) -> next;
        if (x -> next != NULL && x -> val > (x -> next) -> val)
            q.emplace(x, ans + 1);
    }
    cout << ans << "\n";
}




int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    read();
    kill();
    return 0;
}