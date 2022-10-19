#include <bits/stdc++.h>

using namespace std;

#define M 100100

int n;
vector<int> A;
vector<pair<int, int>> ans;

void read() {
    cin >> n;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        A[i]--;
    }
}

void build(const vector<int> &a, vector<int> &a1, vector<int> &a2) {
    a1.clear();
    a2.clear();
    for (int i = 0; i < (int) a.size(); ++i)
        if (a[i] == 0)
            a1.push_back(i);
        else
            a2.push_back(i);
}

void kill() {
    vector<int> a[2];
    build(A, a[0], a[1]);


    for (int t = 1; t <= n; ++t) {
        int i[2] = {0, 0};
        int s[2] = {0, 0};
        int last = -1;
        bool pos = true;

        while (i[0] < a[0].size() || i[1] < a[1].size()) {
            int w = -1, bs = n + 10;

            if (i[0] + t <= a[0].size()) {
                bs = a[0][i[0] + t - 1] + 1;
                w = 0;
            }

            if (i[1] + t <= a[1].size() && a[1][i[1] + t - 1] + 1 < bs) {
                bs = a[1][i[1] + t - 1] + 1;
                w = 1;
            }

            if (w == -1) {
                pos = false;
                break;
            }

            s[w]++;
            last = s[w];
            for (int j = 0; j < 2; ++j)
                i[j] = lower_bound(a[j].begin(), a[j].end(), bs) - a[j].begin();
        }

        if (!pos)
            continue;

        if (s[0] != s[1] && last == max(s[0], s[1]))
            ans.push_back(make_pair(max(s[0], s[1]), t));
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    
    read();

    kill();

    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for (auto x : ans)
        cout << x.first << " " << x.second << "\n";


    return 0;
}