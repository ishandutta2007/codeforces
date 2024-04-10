#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<int> ans;

void print(int *p, int n) {
    for(int i = 0; i < n; i++) {
        cout << p[i] << ' ';
    }
    cout << endl;
}

void apply(int *p, int n, int x) {
    //print(p, n);
    rotate(p, p + n - x, p + n);
    //print(p, n);
    reverse(p, p + x);
    //prin(p, n);
    ans.push_back(x);
}

void abc_shift(int A, int num, int *p, int n) {
    for(int i = 0; i < n; i++) {
        if(p[i] == num) {
            apply(p, n, n - i - 1);
            apply(p, n, i - A + 1);
            apply(p, n, A);
            break;
        }
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int p[n];
    int used[n];
    fill(used, used + n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!used[j] && a[i] == b[j]) {
                used[j] = true;
                p[i] = j;
                break;
            }
        }
    }
    if(accumulate(used, used + n, 0) != n) {
        cout << -1 << endl;
        return 0;
    }
    int cur = n / 2;
    for(int i = 0; i < n; i++) {
        abc_shift(i, cur, p, n);
        //cout << cur << ": \n";
        //print(p, n);
        if(i % 2 == 0) {
            cur -= i + 1;
        } else {
            cur += i + 1;
        }
    }
    if(!is_sorted(p, p + n)) {
        ans.push_back(n);
    }
    cout << ans.size() << endl;
    for(auto it: ans) {
        cout << it << ' ';
    }
    return 0;
}