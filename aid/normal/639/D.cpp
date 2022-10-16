#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXN = 200 * 1000 + 5, B = 5, INF = 1000 * 1000 * 1000 + 5;
int t[MAXN], lst[B], lstt[B];
long long sum[B], add[B];
set< pair<long long, int> > st[B];
vector<int> x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k, b, c;
    cin >> n >> k >> b >> c;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    sort(t, t + n);
    b = min(b, 5 * c);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < B; j++)
            x.push_back(t[i] + j);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for(int i = 0; i < B; i++)
        lstt[i] = -1;
    long long ans = (long long)INF * INF;
    for(size_t i = 0; i < x.size(); i++) {
        int id = (x[i] % 5 + 5) % 5;
        long long dd = (long long)((lstt[id] == -1? 0 : x[i] - x[lstt[id]]) / B) * b;
        lstt[id] = i;
        add[id] += dd;
        sum[id] += (int)st[id].size() * dd;
        int j;
        for(j = lst[id]; j < n && t[j] <= x[i]; j++) {
            long long d = (long long)((x[i] - t[j]) / B) * b +
                (long long)((x[i] - t[j]) % B) * c;
            st[id].insert(make_pair(d - add[id], j));
            sum[id] += d;
        }
        lst[id] = j;
        while((int)st[id].size() > k) {
            set< pair<long long, int> >::iterator it = st[id].end();
            it--;
            sum[id] -= it->first + add[id];
            st[id].erase(it);
        }
        if((int)st[id].size() == k)
            ans = min(ans, sum[id]);
    }
    cout << ans << '\n';
    return 0;
}