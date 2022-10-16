#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 100 * 1000 + 5;
char c[MAXN];
int nxt[MAXN];

int getAns(int l, int pos, int r) {
    return max(abs(pos - l), abs(pos - r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    nxt[n - 1] = n;
    for(int i = n - 2; i >= 0; i--)
        nxt[i] = (c[i + 1] == '0'? i + 1 : nxt[i + 1]);
    int l = (c[0] == '0'? 0 : nxt[0]), r = l;
    for(int i = 0; i < k; i++)
        r = nxt[r];
    int ans = MAXN;
    for(int i = 0; i < n; i++)
        if(c[i] == '0') {
            while(nxt[r] != n) {
                int ll = nxt[l], rr = nxt[r];
                if(getAns(ll, i, rr) < getAns(l, i, r)) {
                    l = ll;
                    r = rr;
                }
                else
                    break;
            }
            ans = min(ans, getAns(l, i, r));
        }
    cout << ans << '\n';
    return 0;
}