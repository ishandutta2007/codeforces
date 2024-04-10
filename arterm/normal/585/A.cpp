#include <bits/stdc++.h>

using namespace std;

const int M = 4040;

int n, v[M], d[M], p[M];
bool used[M];

void read() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> d[i] >> p[i];
    }
}

void cry(int j) {
    if (used[j])
        return;

    used[j] = true;
    for (int i = j + 1; i <= n; ++i)
        if (p[i] >= 0) {
            p[i] -= d[j];
            if (p[i] < 0)
                cry(i);
        }
}

void kill() {
    vector<int> ans;
    for (int i = 1; i <= n; ++i)
        if (p[i] >= 0) {
            ans.push_back(i);
            int j = i + 1, k = v[i];
            vector<int> to_cry;
            while (k > 0 && j <= n) {
                if (p[j] >= 0) {
                    p[j] -= k;
                    if (p[j] < 0)
                        to_cry.push_back(j);
                    --k;
                }
                ++j;
            }
            for (int x : to_cry)
                cry(x);
        }
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}

int main() {
    read();
    kill();
    return 0;
}