#include <iostream>

using namespace std;

const int MAXN = 500 * 1000 + 5;
int nxt[MAXN], s[MAXN];
char c[MAXN], ok[MAXN];

bool solve(int n, int k, int t) {
    if(s[n] + k < 0)
        return false;
    for(int i = 0; i < n; i++)
        ok[i] = (s[i + 1] + k >= 0);
    nxt[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; i--)
        nxt[i] = (ok[i]? i : nxt[i + 1]);
    int lasth = n - 1;
    while(c[lasth] != 'H')
        lasth--;
    int sum = k;
    for(int i = 0; i <= lasth; i++, t--) {
        if(c[i] == '.')
            continue;
        if(c[i] == 'S') {
            sum++;
            continue;
        }
        if(sum) {
            sum--;
            continue;
        }
        if(nxt[i] > lasth) {
            t -= 2 * (nxt[i] - i) + 1;
            break;
        }
        if(t - 2 * (nxt[lasth] - i) - 1 >= 0)
            return true;
        t -= 3 * (nxt[i] - i);
        i = nxt[i];
    }
    return t >= 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    s[0] = 0;
    for(int i = 0; i < n; i++)
        s[i + 1] = s[i] + (c[i] == 'H'? -1 : (c[i] == 'S'? 1 : 0));
    int l = -1, r = n;
    while(l < r - 1) {
        int k = (l + r) / 2;
        if(solve(n, k, t))
            r = k;
        else
            l = k;
    }
    if(!solve(n, r, t))
        cout << -1 << '\n';
    else
        cout << r << '\n';
    return 0;
}