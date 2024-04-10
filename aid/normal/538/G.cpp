#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5, MAXL = 2000 * 1000 + 5;
long long t[MAXN], x[MAXN], y[MAXN], a[MAXN], b[MAXN];
pair<int, int> p[MAXN];
char ans[2][MAXL];

bool solve(int n, int l, long long x[], char ans[]) {
    for(int i = 0; i < n; i++) {
        if((x[i] + t[i]) & 1)
            return false;
        x[i] = (x[i] + t[i]) / 2;
    }
    for(int i = 0; i < n; i++) {
        a[i] = -(t[i] / l);
        b[i] = x[i];
        p[i] = make_pair(t[i] % l, i);
    }
    a[n] = 0;
    b[n] = 0;
    p[n] = make_pair(0, n);
    n++;
    a[n] = 1;
    b[n] = 0;
    p[n] = make_pair(l, n);
    n++;
    sort(p, p + n);
    long long ll = 0, rr = l;
    for(int i = 0; i + 1 < n && ll <= rr; i++) {
        long long aa = a[p[i + 1].second] - a[p[i].second],
            bb = b[p[i + 1].second] - b[p[i].second],
            lll = 0, rrr = p[i + 1].first - p[i].first;
        lll -= bb;
        rrr -= bb;
        if(!aa) {
            if(!(lll <= 0 && 0 <= rrr))
                return false;
            continue;
        }
        if(aa < 0) {
            swap(lll, rrr);
            lll *= -1;
            rrr *= -1;
            aa *= -1;
        }
        if(lll < 0)
            lll /= aa;
        else
            lll = (lll - 1) / aa + 1;
        if(rrr < 0)
            rrr = (rrr + 1) / aa - 1;
        else
            rrr /= aa;
        ll = max(ll, lll);
        rr = min(rr, rrr);
    }
    if(ll > rr)
        return false;
    int s = ll;
    for(int i = 0, j = 0, sum = 0; i < n; i++) {
        int ss = a[p[i].second] * s + b[p[i].second];
        while(j < p[i].first) {
            ans[j] = (sum < ss);
            sum += ans[j];
            j++;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;
    for(int i = 0; i < n; i++)
        cin >> t[i] >> x[i] >> y[i];
    for(int i = 0; i < n; i++) {
        x[i] += y[i];
        y[i] = x[i] - 2 * y[i];
    }
    if(!solve(n, l, x, ans[0]) || !solve(n, l, y, ans[1])) {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < l; i++)
        cout << (ans[0][i]? (ans[1][i]? 'R' : 'U') : (ans[1][i]? 'D' : 'L'));
    cout << '\n';
    return 0;
}