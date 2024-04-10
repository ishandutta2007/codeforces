#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
typedef long long ll;
int n;
struct point{
    int x, y;
    void read() {
        cin >> x >> y;
    }
} A, B, F;
void solve() {
    A.read();
    B.read();
    F.read();
    int dis = abs(A.x-B.x) + abs(A.y-B.y);
    if(A.x == B.x) {
        if(F.x == A.x) {
            if(F.y >= A.y && F.y <= B.y) dis += 2;
            else if(F.y >= B.y && F.y <= A.y) dis += 2;
        }
    } else if(A.y == B.y) {
        if(F.y == A.y) {
            if(F.x >= A.x && F.x <= B.x) dis += 2;
            else if(F.x >= B.x && F.x <= A.x) dis += 2;
        }
    }
    cout << dis << "\n";
}
int main() {
    int t = 1;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}