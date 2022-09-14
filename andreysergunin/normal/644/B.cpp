#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <ctime>
#include <queue>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    queue<long long> q;
    queue<int> qN;
    long long curT = 0;
    vector<long long> ans(n);
    for (int i = 0; i < n; i++) {
        long long t, d;
        cin >> t >> d;
        while (!q.empty() && curT <= t) {
            curT += q.front();
            ans[qN.front()] = curT;
            q.pop();
            qN.pop();
        }
        if (curT <= t) {
            curT = t + d;
            ans[i] = curT;
        }
        else {
            if (q.size() == b)
                ans[i] = -1;
            else {
                q.push(d);
                qN.push(i);
            }
        }
    }
    while (!q.empty()) {
        curT += q.front();
        ans[qN.front()] = curT;
        q.pop();
        qN.pop();
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}