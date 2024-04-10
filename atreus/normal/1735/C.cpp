/*
Women
Life
Freedom
*/
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int din[MAXN];
int dout[MAXN];

int get_din(int v) {
    return din[v] == -1 ? v : get_din(din[v]);        
}

void solve() {
    memset(din, -1, sizeof din);
    memset(dout, -1, sizeof dout);
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int now = (int)(s[i] - 'a');
        if (din[now] != -1)
            continue;
        for (int alph = 0; alph < 26; alph++) {
            if (dout[alph] != -1 or alph == now)
                continue;
            if (get_din(alph) == now and cnt != 25)
                continue;
            dout[alph] = now;
            din[now] = alph;
            cnt++;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << (char)(din[(int)(s[i] - 'a')] + 'a');
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}