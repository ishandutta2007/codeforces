#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000001;

bool prime[MAXN];
int x[1000];
int cnt;

int main() {
    vector <int> ans;
    int ans_sz = 0;
    memset(prime, 1, sizeof prime);
    for (int i = 2; i * i <= MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                prime[j] = 0;
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cnt += (x[i] == 1);
    }
    ans_sz = 1;
    ans.push_back(x[0]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (prime[x[i] + x[j]]) {
                if (x[i] == 1 ^ x[j] == 1) {
                    if (cnt + 1 > ans_sz) {
                        ans_sz = cnt + 1;
                        ans.clear();
                        ans.push_back(x[i]);
                        ans.push_back(x[j]);
                        for (int i = 0; i < cnt - 1; i++) {
                            ans.push_back(1);
                        }
                    }
                } else if (x[i] == 1 && x[j] == 1) {
                    if (cnt > ans_sz) {
                        ans_sz = cnt;
                        ans.clear();
                        for (int i = 0; i < ans_sz; i++) {
                            ans.push_back(1);
                        }
                    }
                } else {
                    if (2 > ans_sz) {
                        ans_sz = 2;
                        ans.clear();
                        ans.push_back(x[i]);
                        ans.push_back(x[j]);
                    }
                }
            }
        }
    }
    cout << ans_sz << endl;
    for (int i = 0; i < ans_sz; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}