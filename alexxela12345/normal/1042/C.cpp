#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int cntZero = 0;
    int cntNeg = 0;
    int maxNeg = -1;
    vector<int> used(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            used[i] = 1;
            cntZero++;
        } else if (arr[i] < 0) {
            cntNeg++;
            if (maxNeg == -1 || abs(arr[maxNeg]) > abs(arr[i])) {
                maxNeg = i;
            }
        }
    }
    if (cntNeg % 2 == 1) {
        used[maxNeg] = 1;
    }
    if (cntZero == n || (cntZero == n - 1 && cntNeg == 1)) {
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << " " << i + 1 << " " << i + 2 << endl;
        }
        return 0;
    }
    
    int lst = -1;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            if (lst != -1) {
                cout << 1 << " " << lst + 1 << " " << i + 1 << endl;
            }
            lst = i;
        }
    }
    if (lst != -1) {
        cout << 2 << " " << lst + 1 << endl;
    }

    lst = -1;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (lst != -1)
                cout << 1 << " " << lst + 1 << " " << i + 1 << endl;
            lst = i;
        }
    }
    return 0;
}