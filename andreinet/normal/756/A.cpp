#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define SZ(x) ((int) (x).size())
using namespace std;

int main()
{
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    #endif // LOCAL_RUN
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        A[i]--;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cnt ^= x;
    }

    int cycles = 0;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            for (int j = i; !used[j]; j = A[j]) {
                used[j] = true;
            }
            cycles++;
        }
    }
    if (cycles == 1) {
        cycles = 0;
    }
    cout << cycles + (cnt ^ 1) << '\n';
}