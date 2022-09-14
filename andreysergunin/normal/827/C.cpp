#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef unsigned int uint;

const int MAXN = 1e5 + 10; 

string t[11][11];

vector<int> pref[11][11][4];

class BIT {
public:
    BIT() {};
    BIT(int n) {
        a.resize(n);
    }

    int sum(int l, int r) {
        if (r <= l)
            return 0; 
        return sum(r - 1) - sum(l - 1);
    }

    void update(int pos, int x) {
        for (int i = pos; i < sz(a); i |= (i + 1)) 
            a[i] += x;
    }

private:

    int sum(int pos) {
        int ans = 0;
        for (int i = pos; i >= 0; i = (i & (i + 1)) - 1)
            ans += a[i];
        return ans;
    }

    vector<int> a;
};

int f(char c) {
    if (c == 'A')
        return 0;
    else if (c == 'T')
        return 1;
    else if (c == 'G')
        return 2;
    else 
        return 3;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    string s;
    cin >> s;
    int n = sz(s);

    for (int p = 1; p <= 10; ++p) {
        for (int i = 0; i < n; ++i)
            t[p][i % p] += s[i];
    }

    BIT bit[11][11][4];


    for (int p = 1; p <= 10; ++p) {
        for (int i = 0; i < p; ++i) {
            for (int j = 0; j < 4; ++j) {
                bit[p][i][j] = BIT(sz(t[p][i]) + 1);
                for (int k = 0; k < sz(t[p][i]); ++k) {
                    if (f(t[p][i][k]) == j) {
                        bit[p][i][j].update(k, 1);
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    for (int qw = 0; qw < q; ++qw) {
        int type;
        cin >> type;

        if (type == 1) {
            int pos;
            char c;
            cin >> pos >> c;
            int x = f(c);
            --pos;

            for (int p = 1; p <= 10; ++p) {
                int i = pos % p;
                int k = pos / p;
                int j = f(t[p][i][k]);
                bit[p][i][j].update(k, -1);
                bit[p][i][x].update(k, 1);
                t[p][i][k] = c;
            }
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            string str;
            cin >> str;
            int ans = 0;
            int p = sz(str);
            for (int i = 0; i < p; ++i) {
                if (l + i >= r)
                    continue;
                // cout << i << " " << (l + i) / p << " " << r / p << endl;
                // cout << p << " " << (l + i) % p << " " << f(str[i]) << endl;
                // cout << bit[p][(l + i) % p][f(str[i])].sum((l + i) / p, (r + i) / p) << endl;
                int lf = (l + i) / p;
                int rg = lf + (r - l - i - 1) / p + 1;
                // cout << i << " " << lf << " " << rg << endl;
                ans += bit[p][(l + i) % p][f(str[i])].sum(lf, rg);
            }
            cout << ans << endl;
        }
    }


}