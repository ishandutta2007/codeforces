#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 4005, MAXM = 20 * 1000 + 5;

struct Stack {
    int dp[MAXN][MAXN], cc[MAXN], hh[MAXN], n;

    void push(int c, int h) {
        for(int i = 0; i < MAXN; i++) {
            dp[n][i] = (n? dp[n - 1][i] : 0);
            if(i >= c && dp[n][i] < (n? dp[n - 1][i - c] : 0) + h)
                dp[n][i] = (n? dp[n - 1][i - c] : 0) + h;
        }
        cc[n] = c;
        hh[n] = h;
        n++;
    }

    void pop() {
        n--;
    }

    int get(int val) const {
        return dp[n - 1][val];
    }

    int getc() const {
        return cc[n - 1];
    }

    int geth() const {
        return hh[n - 1];
    }
};

struct Queue {
    Stack l, r;

    void push(int c, int h) {
        r.push(c, h);
    }

    void pop() {
        if(!l.n)
            while(r.n) {
                int c = r.getc(), h = r.geth();
                r.pop();
                l.push(c, h);
            }
        l.pop();
    }

    int get(int val) const {
        if(!l.n && !r.n)
            return 0;
        if(!l.n)
            return r.get(val);
        if(!r.n)
            return l.get(val);
        int res = 0;
        for(int i = 0; i <= val; i++)
            res = max(res, l.get(i) + r.get(val - i));
        return res;
    }
};

Queue q;
pair<pair<int, char>, pair<int, int> > ev[2 * MAXN + MAXM];
int ans[MAXM];

int main() {
    ios_base::sync_with_stdio(false);
    int n, p;
    cin >> n >> p;
    for(int i = 0; i < n; i++) {
        int c, h, t;
        cin >> c >> h >> t;
        ev[2 * i] = make_pair(make_pair(t, 1), make_pair(c, h));
        ev[2 * i + 1] = make_pair(make_pair(t + p, 0), make_pair(c, h));
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int val, t;
        cin >> t >> val;
        ev[2 * n + i] = make_pair(make_pair(t, 2), make_pair(i, val));
    }
    sort(ev, ev + 2 * n + m);
    for(int i = 0; i < 2 * n + m; i++)
        if(ev[i].first.second == 0)
            q.pop();
        else if(ev[i].first.second == 1)
            q.push(ev[i].second.first, ev[i].second.second);
        else
            ans[ev[i].second.first] = q.get(ev[i].second.second);
    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
    return 0;
}