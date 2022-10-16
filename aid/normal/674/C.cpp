#include <iostream>
#include <vector>

using namespace std;

struct Line {
    double a, b;

    Line() {}

    Line(double _a, double _b): a(_a), b(_b) {}
};

const int MAXN = 200 * 1000 + 5, MAXK = 55;
const double EPS = 1e-8;
int t[MAXN], pos;
long long s[MAXN];
double sinv[MAXN], dp[MAXK][MAXN];
vector<Line> st;

bool bad(const Line &l0, const Line &l1, const Line &l2) {
    return (l1.a - l0.a) / (l0.b - l1.b) >
        (l2.a - l1.a) / (l1.b - l2.b) - EPS;
}

void add(const Line &l) {
    while(st.size() >= 2 && bad(st[(int)st.size() - 2], st.back(), l))
        st.pop_back();
    pos = min(pos, max(0, (int)st.size() - 1));
    st.push_back(l);
}

double f(const Line &l, double x) {
    return l.a + l.b * x;
}

double get(double x) {
    while(pos + 1 < (int)st.size() && f(st[pos + 1], x) > f(st[pos], x) + EPS)
        pos++;
    return f(st[pos], x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, k;
    cin >> n >> k;
    k--;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    s[0] = 0;
    for(int i = 0; i < n; i++)
        s[i + 1] = s[i] + t[i];
    sinv[0] = 0;
    for(int i = 0; i < n; i++)
        sinv[i + 1] = sinv[i] + 1. / t[i];
    for(int i = 0; i < k; i++) {
        st.clear();
        add(Line(dp[i][0], 0));
        for(int j = 1; j <= n; j++) {
            dp[i + 1][j] = get(sinv[j]);
            add(Line(dp[i][j] - s[j] * sinv[j], s[j]));
        }
    }
    double ans = -dp[k][n];
    for(int i = 0; i < n; i++)
        ans += (double)s[i + 1] / t[i];
    cout << ans << '\n';
    return 0;
}