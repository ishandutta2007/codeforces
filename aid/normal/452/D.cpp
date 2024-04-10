#include <iostream>
#include <queue>

using namespace std;

queue<int> q0, q1, q2;

int main() {
    ios_base::sync_with_stdio(false);
    int k, n0, n1, n2, t0, t1, t2;
    cin >> k >> n0 >> n1 >> n2 >> t0 >> t1 >> t2;
    int t = 0;
    for(int i = 0; i < k; i++) {
        while(!q0.empty() && q0.front() <= t)
            q0.pop();
        while((int)q0.size() >= n0) {
            t = q0.front();
            q0.pop();
        }
        while(!q1.empty() && q1.front() <= t + t0)
            q1.pop();
        while((int)q1.size() >= n1) {
            t = q1.front() - t0;
            q1.pop();
        }
        while(!q2.empty() && q2.front() <= t + t0 + t1)
            q2.pop();
        while((int)q2.size() >= n2) {
            t = q2.front() - t0 - t1;
            q2.pop();
        }
        q0.push(t + t0);
        q1.push(t + t0 + t1);
        q2.push(t + t0 + t1 + t2);
    }
    cout << t + t0 + t1 + t2 << '\n';
    return 0;
}