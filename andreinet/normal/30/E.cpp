
#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

vector<int> manacher(const string& S) {
    int n = SZ(S);
    vector<int> p(n, 0);
    int c = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (r > i) {
            p[i] = min(p[2 * c - i], r - i);
        }
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 &&
                S[i + p[i] + 1] == S[i - p[i] - 1]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    return p;
}

vector<int> prefixes(const string& S) {
    int n = SZ(S);
    int l = 0, r = 0;
    vector<int> z(n, 0);
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;
            while (r < n && S[r] == S[r - l]) ++r;
            z[i] = r - l;
            r--;
        } else {
            if (z[i - l] < r - i + 1) {
                z[i] = z[i - l];
            } else {
                l = i;
                while (r < n && S[r] == S[r - l]) ++r;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

string reverse(string s) {
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    int n = SZ(S);

    vector<int> pal = manacher(S);
    vector<int> z = prefixes(reverse(S) + S);
    z.erase(z.begin(), z.begin() + n);

    vector<vector<int>> erases(n + 1), palBegin(n);
    for (int i = 0; i < n; ++i) {
        palBegin[i - pal[i]].push_back(i + pal[i]);
        int x = min(z[i], n - i);
        if (x > 0) {
            erases[i + x].push_back(i);
        }
    }

    int abeg = -1, aend = -2, bbeg = -1, bend = -1, cbeg = n;
    int maxLen = 0;

    multiset<int> begs;
    
    int mbeg = -1, mend = -2;
    for (int i = 0; i < n; ++i) {
        for (int p: erases[i]) {
            begs.erase(begs.find(p));
            if (i - p > mend - mbeg + 1) {
                mbeg = p;
                mend = i - 1;
            }
        }

        int rbeg, rend;
        if (!begs.empty() && i - *begs.begin() > mend - mbeg + 1) {
            rbeg = *begs.begin();
            rend = i - 1;
        } else {
            rbeg = mbeg;
            rend = mend;
        }

        for (int r: palBegin[i]) {
            int x = min(rend - rbeg + 1, n - r - 1);
            if (2 * x + (r - i + 1) > maxLen) {
                maxLen = 2 * x + (r - i + 1);
                abeg = rbeg;
                aend = rbeg + x - 1;
                bbeg = i;
                bend = r;
                cbeg = n - x;
            }
        }
        
        if (z[i] > 0) 
            begs.insert(i);
    }

    if (abeg > aend) {
        cout << "1\n";
        cout << bbeg + 1 << ' ' << bend - bbeg + 1 << '\n';
    } else {
        cout << "3\n";
        cout << abeg + 1 << ' ' << aend - abeg + 1 << '\n';
        cout << bbeg + 1 << ' ' << bend - bbeg + 1 << '\n';
        cout << cbeg + 1 << ' ' << n - cbeg << '\n';
    }
}