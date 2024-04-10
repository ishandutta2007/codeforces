#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) x.begin(), x.end()

const int INF = 1e9;

int gen(vector <int> &a, vector <int> &b, vector <int> &ans) {
    int n = ans.size();
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0) {
            if (b[i] != 0 || ans[i + 1] != 0) {
                return 0;
            }
            ans[i + 1] = 0;
            continue;
        }
        if (a[i] == 1) {
            if (ans[i] != 1 && ans[i] != 0) {
                return 0;
            }
            if (ans[i] == 0) {
                ans[i + 1] = 1;
            }
            if (ans[i] == 1 && b[i] == 0) {
                ans[i + 1] = 0;
            }
            if (ans[i] == 1 && b[i] == 1) {
                ans[i + 1] = 1;
            }
            if (b[i] != 0 && b[i] != 1) {
                return 0;
            }
            if (b[i] == 1 && ans[i] == 0) {
                return 0;
            }
        }
        if (a[i] == 2) {
            if (b[i] == 3 || b[i] == 1) {
                return 0;
            }
            if (ans[i] == 1 || ans[i] == 3) {
                return 0;
            }
            if (ans[i] == 0) {
                if (b[i] != 0) {
                    return 0;
                }
                ans[i + 1] = 2;
            }
            if (ans[i] == 2) {
                if (b[i] == 0) {
                    ans[i + 1] = 0;
                }
                if (b[i] == 2) {
                    ans[i + 1] = 2;
                }
            }
        }
        if (a[i] == 3) {
            if (ans[i] == 0) {
                if (b[i] != 0) {
                    return 0;
                }
                ans[i + 1] = 3;
            }
            if (ans[i] == 1) {
                if (b[i] == 0) {
                    ans[i + 1] = 2;
                }
                if (b[i] == 1) {
                    ans[i + 1] = 3;
                }
                if (b[i] == 2 || b[i] == 3) {
                    return 0;
                }
            }
            if (ans[i] == 2) {
                if (b[i] == 0) {
                    ans[i + 1] = 1;
                }
                if (b[i] == 1) {
                    return 0;
                }
                if (b[i] == 2) {
                    ans[i + 1] = 3;
                }
                if (b[i] == 3) {
                    return 0;
                }
            }
            if (ans[i] == 3) {
                if (b[i] == 0) {
                    ans[i + 1] = 0;
                }
                if (b[i] == 1) {
                    ans[i + 1] = 1;
                }
                if (b[i] == 2) {
                    ans[i + 1] = 2;
                }
                if (b[i] == 3) {
                    ans[i + 1] = 3;
                }
            }
        }
    }
    cout << "YES" << "\n";
    for (auto c : ans) {
        cout << c << " ";
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    vector <int> ans(n);
    vector <int> a(n - 1);
    vector <int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < 4; i++) {
        vector <int> ans(n);
        ans[0] = i;
        if (gen(a, b, ans) == 1) {
            return 0;
        }
    }
    cout << "NO";
	return 0;
}