#include <iostream>
#include <set>

using namespace std;

const int MAXN = 1005, MAXK = 1000 * 1000 + 5;
int rs[MAXN], cs[MAXN], r[MAXN], c[MAXN];
long long pr[MAXK];
set< pair<long long, int> > str, stc;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int a;
            cin >> a;
            rs[i] += a;
            cs[j] += a;
        }
    for(int i = 0; i < n; i++) {
        r[i] = 0;
        str.insert(make_pair(-(rs[i] - (long long)m * p * r[i]), i));
    }
    for(int i = 0; i < m; i++) {
        c[i] = 0;
        stc.insert(make_pair(-(cs[i] - (long long)n * p * c[i]), i));
    }
    long long ans = 0;
    for(int i = 0; i < k; i++) {
        long long addr = -str.begin()->first;
        int posr = str.begin()->second;
        str.erase(str.begin());
        pr[i] = addr;
        ans += addr;
        r[posr]++;
        str.insert(make_pair(-(rs[posr] - (long long)m * p * r[posr]), posr));
    }
    long long bans = ans;
    for(int i = 0; i < k; i++) {
        long long addc = -stc.begin()->first;
        int posc = stc.begin()->second;
        stc.erase(stc.begin());
        ans -= pr[k - i - 1];
        ans += addc;
        c[posc]++;
        stc.insert(make_pair(-(cs[posc] - (long long)n * p * c[posc]), posc));
        bans = max(bans, ans - (long long)(k - i - 1) * (i + 1) * p);
    }
    cout << bans << '\n';
    return 0;
}