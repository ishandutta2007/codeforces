#include <iostream>

using namespace std;

const int MAXN = 100 * 1000 + 5;
int a[MAXN], t[MAXN], r[MAXN], b[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests;
    cin >> tests;
    for(int tt = 0; tt < tests; tt++) {
        int m, k;
        cin >> m >> k;
        for(int i = 0; i < k; i++)
            cin >> a[i];
        m--;
        for(int i = 0; i < m; i++) {
            cin >> t[i] >> r[i];
            t[i]--;
        }
        int cnt = 0, x = -1;
        for(int i = 0; i < m; i++) {
            if(r[i] && x == -1) {
                x = cnt;
                for(int j = 0; j < k; j++)
                    b[j] = a[j];
            }
            if(t[i] == -1)
                cnt++;
            else
                a[t[i]]--;
        }
        if(x == -1) {
            for(int i = 0; i < k; i++)
                cout << (cnt >= a[i]? 'Y' : 'N');
            cout << '\n';
        }
        else {
            int mina = MAXN;
            for(int i = 0; i < k; i++)
                if(a[i] == b[i])
                    mina = min(mina, a[i]);
            for(int i = 0; i < k; i++)
                cout << ((x >= b[i] && b[i] == a[i]) ||
                         cnt - mina >= a[i]? 'Y' : 'N');
            cout << '\n';
        }
    }
    return 0;
}