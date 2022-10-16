#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5;
int ans[MAXN];
long long l[MAXN], r[MAXN], a[MAXN];
vector< pair<long long, pair<char, int> > > ev;
priority_queue<pair<long long, int>, vector< pair<long long, int> >,
               greater< pair<long long, int> > > pq;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for(int i = 0; i < m; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        ev.push_back(make_pair(l[i + 1] - r[i], make_pair(0, i)));
        ev.push_back(make_pair(r[i + 1] - l[i], make_pair(2, i)));
    }
    for(int i = 0; i < m; i++)
        ev.push_back(make_pair(a[i], make_pair(1, i)));
    sort(ev.begin(), ev.end());
    for(int i = 0; i < n - 1; i++)
        ans[i] = -1;
    for(size_t i = 0; i < ev.size(); i++) {
        char t = ev[i].second.first;
        int id = ev[i].second.second;
        if(t == 0)
            pq.push(make_pair(r[id + 1] - l[id], id));
        else if(t == 1) {
            if(pq.empty())
                continue;
            ans[pq.top().second] = id;
            pq.pop();
        }
        else {
            if(ans[id] != -1)
                continue;
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for(int i = 0; i < n - 1; i++)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
    return 0;
}