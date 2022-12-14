/*
Women
Life
Freedom
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000 + 10;
long long a[MAXN], b[MAXN], match[MAXN];
map<long long,int> cnt, tmp;

void solve() {
    cnt.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<long long>());
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cnt[b[i]]++;
    }
    vector<long long> ths;
    for (int i = 0; i < n; i++) {
        ths.push_back(a[0] + b[i]);
        ths.push_back(abs(a[0] - b[i]));
    }
    sort(ths.begin(), ths.end());
    ths.resize(unique(ths.begin(), ths.end()) - ths.begin());
    for (auto th : ths) {
        tmp.clear();
        tmp = cnt;
        bool is_correct = true;
        for (int i = 0; is_correct and i < n; i++) {
            if (tmp[a[i] + th] > 0) {
                tmp[a[i] + th]--;
                match[i] = a[i] + th;
            }
            else if (tmp[abs(a[i] - th)] > 0) {
                tmp[abs(a[i] - th)]--;
                match[i] = abs(a[i] - th);
            }
            else
                is_correct = false;
        }
        if (is_correct) {
            cout << "YES\n";
            long long me = 0;
            for (int i = 0; i < n; i++)
                if (a[i] + match[i] != th and a[i] <= match[i])
                    me = max(me, a[i]);
            for (int i = 0; i < n; i++) {
                if (a[i] + match[i] == th or a[i] > match[i]) {
                    cout << me + a[i] << " ";
                    assert(abs(a[i] - th) == match[i]);
                }
                else {
                    cout << me - a[i] << " ";
                    assert(abs(a[i] + th) == match[i]);
                }
            }
            cout << '\n' << me << " " << me + th << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}

/*
th = 5

24 - 19 - 14 - 9 - 4 - 1 - 6 - 11 - 16 - 



*/