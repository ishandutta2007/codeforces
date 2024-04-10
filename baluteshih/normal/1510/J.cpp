#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

string gen(int n, vector<int> blk) {
    string rt;
    int sum = 0;
    for (int i = 0; i < SZ(blk); ++i)
        sum += blk[i] + !!i;
    if (sum > n) return "";
    int k = n - sum;
    for (int i = 0; i < SZ(blk); ++i) {
        if (i) rt += "_";
        if (blk[i] > k)
            rt += string(k, '_') + string(blk[i] - k, '#');
        else
            rt += string(blk[i], '_');
    }
    rt.resize(n, '_');
    return rt;
}

void print(vector<int> blk) {
    cout << SZ(blk) << "\n";
    for (int i = 0; i < SZ(blk); ++i)
        cout << blk[i] << " \n"[i + 1 == SZ(blk)];
    exit(0);
}

vector<int> get_blk(string s) {
    vector<int> blk;
    int lst = 0;
    for (int i = 0; i <= SZ(s); ++i)
        if (i == SZ(s) || s[i] == '_') {
            if (lst > 0) blk.pb(lst);
            lst = 0;
        }
        else
            ++lst;
    return blk;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    string s;
    cin >> s;
    if (gen(SZ(s), get_blk(s)) == s)
        print(get_blk(s));
    for (int k = 1; k < min(SZ(s), 5); ++k) {
        string t = s.substr(0, SZ(s) - k);
        for (int i = 0; i + 1 < SZ(t); ++i)
            if (t[i] == '_' && t[i + 1] == '#')
                for (int j = i; j >= 0 && j > i - k; --j)
                    t[j] = '#';
        for (int i = 0, j = 0; i < SZ(t); i = j) {
            if (t[j] == '#') {
                ++j;
                continue;
            }
            while (j < SZ(t) && t[j] == '_')
                ++j;
            int l = i + (i != 0);
            int r = j - 1 - (j < SZ(t));
            if (r - l >= 0) {
                if ((r - l) & 1)
                    t[r] = '#', --r;
                for (; l <= r; l += 2)
                    t[l] = '#';
            }
        }
        if (gen(SZ(s), get_blk(t)) == s)
            print(get_blk(t));
    }
    cout << "-1\n";
}