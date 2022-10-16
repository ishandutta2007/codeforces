#include <iostream>

using namespace std;

const int MAXN = 105;
int q[MAXN], pq[MAXN], npq[MAXN], invq[MAXN], s[MAXN];

bool solve(int q[], int s[], int n, int k) {
    for(int i = 0; i < n; i++)
        pq[i] = q[i];
    for(int i = 1; i <= k; i++) {
        bool eq = true;
        for(int j = 0; j < n; j++)
            if(pq[j] != s[j]) {
                eq = false;
                break;
            }
        if(eq)
            return !((k - i) & 1);
        for(int j = 0; j < n; j++)
            npq[j] = pq[q[j]];
        for(int j = 0; j < n; j++)
            pq[j] = npq[j];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> q[i];
        q[i]--;
    }
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
    }
    bool id = true;
    for(int i = 0; i < n; i++)
        if(i != s[i]) {
            id = false;
            break;
        }
    if(id) {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < n; i++)
        invq[q[i]] = i;
    bool eq = true;
    for(int i = 0; i < n; i++)
        if(invq[i] != q[i]) {
            eq = false;
            break;
        }
    if(eq) {
        if(k > 1)
            cout << "NO\n";
        else {
            bool ok = true;
            for(int i = 0; i < n; i++)
                if(q[i] != s[i]) {
                    ok = false;
                    break;
                }
            cout << (ok? "YES" : "NO") << '\n';
        }
        return 0;
    }
    bool ok = solve(q, s, n, k) || solve(invq, s, n, k);
    cout << (ok? "YES" : "NO") << '\n';
    return 0;
}