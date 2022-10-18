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

const int N = 21234;

int fwdRL[N], bwdRL[N];
char s[N];
int n;
int ans;
bitset<N> u;

void single(int l, int len) {
    // cerr << l << " " << len << endl;
    if (fwdRL[l] >= len) return;
    u.reset();
    int r = l; // [l, r)
    bool ok = 1;
    auto add = [&](int x) {
        if (x < l || x > n || u[x])
            ok = 0;
        else
            u[x] = 1;
    };
    while (r + len - 1 <= n) {
        int nr = r + len;
        bool haveD = false;
        for (int i = r; i < nr; i++) {
            if ((i == r && s[i] == 'L') || (i == nr - 1 && s[i] == 'R'))
                return;
            if (s[i] == 'L') add(i - 1);
            else if (s[i] == 'R') add(i + 1);
            else if (s[i] == 'D') add(i + len), haveD = true;
            else if (s[i] == 'U') add(i - len);
            else assert(0);
            if (!ok) return;
        }
        if (!haveD) {
            if (len & 1) {
                ans++;
                //cerr << "Case 1: " << l << " " << nr - 1 << "\n";
            }
            else {
                /*for (int i = 0; i < 1 + bwdRL[l - 1] / len; ++i)
                    cerr << "Case 2: " << l - i * len << " " << nr - 1 << "\n";*/
                ans += 1 + bwdRL[l - 1] / len;
            }
        }
        r = nr;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    {
        string _s;
        cin >> _s;
        n = SZ(_s);
        for (int i = 1; i <= n; i++)
            s[i] = _s[i - 1];
    }
    /*for (int i = 1; i <= n; ++i)
        cerr << i / 10;
    cerr << "\n";
    for (int i = 1; i <= n; ++i)
        cerr << i % 10;
    cerr << "\n";*/
    for (int i = 1; i <= n; i++)
        if (s[i] == 'R' && s[i + 1] == 'L')
            bwdRL[i + 1] = 2 + bwdRL[i - 1];
    for (int i = n; i >= 1; i--)
        if (s[i] == 'R' && s[i + 1] == 'L')
            fwdRL[i] = 2 + fwdRL[i + 2];
    for (int i = 1; i <= n; i++)
        ans += fwdRL[i] / 2;
    //cerr << ans << "\n"; 
    
    for (int i = 1; i <= n; i++) {
        int j = i + fwdRL[i];
        //cerr << i << " -> " << j << "\n";
        if (j > n || s[j] == 'U' || s[j] == 'L')
            continue;
        if (s[j] == 'R'); // that's it
        else {
            assert(s[j] == 'D');
            ++j;
            while (j <= n && s[j] == 'L')
                j++;
            --j;
        }
        // j is the one with in-degree 0
        int k = j + 1;
        while (k <= n && s[k] != 'U')
            ++k;
        if (k > n)
            continue;
        // we want to match j with k
        int len = k - j;
        single(i, len); 
        // cerr << ans << endl;
    }

    cout << ans << "\n";
}