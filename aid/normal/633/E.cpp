#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 1000 * 1000 + 5, INF = 1000 * 1000 * 1000 + 5;
int v[MAXN], c[MAXN], a[MAXN];
long double pr[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        v[i] *= 100;
    }
    for(int i = 0; i < n; i++)
        cin >> c[i];
    priority_queue< pair<int, int> > pqv;
    priority_queue<pair<int, int>, vector< pair<int, int> >,
                   greater< pair<int, int> > > pqc;
    for(int i = 0, j = 0; i < n; i++) {
        j = max(j, i);
        while(!pqv.empty() && pqv.top().second < i)
            pqv.pop();
        while(!pqc.empty() && pqc.top().second < i)
            pqc.pop();
        while(j < n) {
            int maxv = max(v[j], pqv.empty()? -INF : pqv.top().first),
                minc = min(c[j], pqc.empty()? INF : pqc.top().first);
            if(maxv >= minc)
                break;
            pqv.push(make_pair(v[j], j));
            pqc.push(make_pair(c[j], j));
            j++;
        }
        a[i] = pqv.empty()? -INF : pqv.top().first;
        if(j < n) {
            int maxv = max(v[j], pqv.empty()? -INF : pqv.top().first),
                minc = min(c[j], pqc.empty()? INF : pqc.top().first);
            a[i] = max(a[i], min(maxv, minc));
        }
    }
    pr[0] = 1;
    for(int i = 0; i + 1 <= n - k; i++)
        pr[i + 1] = (pr[i] * (n - i - k)) / (n - i);
    sort(a, a + n);
    long double ans = 0;
    for(int i = 0; i < n;) {
        int j = i + 1;
        while(j < n && a[j] == a[i])
            j++;
        ans += (pr[i] - pr[j]) * a[i];
        i = j;
    }
    cout << ans << '\n';
    return 0;
}