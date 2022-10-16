#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 200 * 1000 + 5;
pair<pair<int, int>, int> p[MAXN];
pair<int, int> q[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].first.first >> p[i].first.second;
        p[i].second = 1;
    }
    sort(p, p + n);
    int nn = 0;
    long long ans = 0;
    for(int i = 1; i < n; i++)
        if(p[i].first == p[nn].first) {
            ans += (long long)p[nn].second * p[i].second;
            p[nn].second += p[i].second;
        }
        else {
            nn++;
            p[nn] = p[i];
        }
    nn++;
    n = nn;
    for(int i = 0; i < n; i++)
        q[i] = make_pair(p[i].first.first, p[i].second);
    nn = 0;
    for(int i = 1; i < n; i++)
        if(q[i].first == q[nn].first) {
            ans += (long long)q[nn].second * q[i].second;
            q[nn].second += q[i].second;
        }
        else {
            nn++;
            q[nn] = q[i];
        }
    for(int i = 0; i < n; i++)
        swap(p[i].first.first, p[i].first.second);
    sort(p, p + n);
    for(int i = 0; i < n; i++)
        q[i] = make_pair(p[i].first.first, p[i].second);
    nn = 0;
    for(int i = 1; i < n; i++)
        if(q[i].first == q[nn].first) {
            ans += (long long)q[nn].second * q[i].second;
            q[nn].second += q[i].second;
        }
        else {
            nn++;
            q[nn] = q[i];
        }
    cout << ans << '\n';
    return 0;
}