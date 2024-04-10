#include <bits/stdc++.h>

using namespace std;

#define int long long

int st[20];

int get_sum(int l, int r) {
    int len = (r - l + 1);
    return len * (len + 1) / 2 + (l - 1) * len;
}

int gets(int x) {
    int ans = 0;
    int cnt = 1, t = 9, lst_t = 0, r = 10;
    while (1) {
        if (r - 1 <= x) {
            int start = r / 10, stop = r - 1;
            ans += cnt * ((stop - start + 1) * (x + 1) - get_sum(start, stop));
        }
        else {
            int start = r / 10, stop = x;
            ans += cnt * ((stop - start + 1) * (x + 1) - get_sum(start, stop));
            break;
        }
        r *= 10;
        lst_t = t;
        t *= 10, cnt++;
    }
    return ans;
}

void solve() {
    int x;
    cin >> x;
    int lef = 0, righ = 1e9;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        int ans = gets(mid);
        if (ans < x) lef = mid;
        else righ = mid;
    }
    x -= gets(lef);
    string curs = to_string(lef + 1);
    int cnt = 1, cur = 9;
    //cout << lef << endl;
    //cout << cnt << " " << curs << " " << x << endl;
    while (1) {
        if (cnt * cur < x) {
            x -= cnt * cur;
        }
        else {
            string S;
            //cout << curs.size() << " " << cnt << '\n';
            for (int pos = 0; pos < cnt; ++pos) {
                int start = 1;
                if (pos != 0) start = 0;
                int ok = 1;
                int stop;
                if ((int)curs.size() == cnt) stop = curs[pos] - '0' - 1;
                else stop = 9;
                for (int i = start; i <= stop; ++i) {
                    int tmp = st[cnt - pos - 1] * cnt;
                    //cout << i << " " << pos << " " << tmp << " " << x << endl;
                    if (tmp < x) x -= tmp;
                    else {
                        S += char('0' + i);
                        ok = 0;
                        break;
                    }
                }
                if (ok == 0) {
                    //cout << "OK" << endl;
                    for (int i = pos + 1; i < cnt; ++i) {
                        for (int j = 0; j < 10; ++j) {
                            int tmp = st[cnt - i - 1] * cnt;
                            if (tmp < x) x -= tmp;
                            else {
                                S += char('0' + j);
                                break;
                            }
                        }
                    }
                    //cout << S << '\n';
                    //cout << x << '\n';
                    cout << S[x - 1] << '\n';
                    return;
                }
                else {
                    S += curs[pos];
                }
            }
            cout << S[x - 1] << '\n';
            return;
        }
        cnt++, cur *= 10;
    }
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    st[0] = 1;
    for (int i = 1; i <= 18; ++i) st[i] = st[i - 1] * 10;
    while (q--) solve();
    return 0;
}