#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100 * 1000 + 5;
const long long INF = 10ll * 1000 * 1000 * 1000 + 5;
pair<int, int> p[MAXN];

bool check(int n, long long w) {
    priority_queue< pair<int, int> > maxpq;
    priority_queue<pair<int, int>, vector< pair<int, int> >,
                   greater< pair<int, int> > > minpq;
    for(int i = 0; i < n; i++) {
        maxpq.push(make_pair(p[i].second, i));
        minpq.push(make_pair(p[i].second, i));
    }
    for(int i = 0, j = 0; i < n; i++) {
        while(j < n && p[j].first <= p[i].first + w)
            j++;
        while(!maxpq.empty() &&
              i <= maxpq.top().second && maxpq.top().second < j)
            maxpq.pop();
        while(!minpq.empty() &&
              i <= minpq.top().second && minpq.top().second < j)
            minpq.pop();
        if(minpq.empty() || maxpq.top().first - minpq.top().first <= w)
            return true;
        maxpq.push(make_pair(p[i].second, i));
        minpq.push(make_pair(p[i].second, i));
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(12);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[i].first = x + y;
        p[i].second = x - y;
    }
    sort(p, p + n);
    long long l = -1, r = INF;
    while(l < r - 1) {
        long long m = (l + r) / 2;
        if(check(n, m))
            r = m;
        else
            l = m;
    }
    cout << (long double)r / 2 << '\n';
    return 0;
}