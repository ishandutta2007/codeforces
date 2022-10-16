#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 300 * 1000 + 5;
pair<int, int> p0[2 * MAXN];
pair< pair<int, int>, int> p1[MAXN];
int sufmin[MAXN], prefmin[MAXN], s[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    int n, w;
    cin >> n >> w;
    int n0 = 0, n1 = 0;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(b > 2 * a) {
            p0[n0] = make_pair(a, i);
            n0++;
            p0[n0] = make_pair(b - a, i);
            n0++;
        }
        else {
            p1[n1] = make_pair(make_pair(b, a), i);
            n1++;
        }
    }
    sort(p0, p0 + n0);
    sort(p1, p1 + n1);
    if(n1)
        sufmin[n1 - 1] = n1 - 1;
    for(int i = n1 - 2; i >= 0; i--)
        if(p1[i].first.second < p1[sufmin[i + 1]].first.second)
            sufmin[i] = i;
        else
            sufmin[i] = sufmin[i + 1];
    if(n1)
        prefmin[0] = 0;
    for(int i = 1; i < n1; i++)
        if(p1[i].first.second - p1[i].first.first <
           p1[prefmin[i - 1]].first.second - p1[prefmin[i - 1]].first.first)
            prefmin[i] = i;
        else
            prefmin[i] = prefmin[i - 1];
    long long ans = 0;
    int pos0 = 0, pos1 = 0, d = w;
    for(; pos1 < n1 && d > 1; pos1++, d -= 2)
        ans += p1[pos1].first.first;
    if(pos1 < n1 && d) {
        ans += min(p1[sufmin[pos1]].first.second,
                   p1[prefmin[pos1 - 1]].first.second -
                   p1[prefmin[pos1 - 1]].first.first + p1[pos1].first.first);
        d--;
    }
    for(; pos0 < n0 && d > 0; pos0++, d--)
        ans += p0[pos0].first;
    long long bans = ans;
    int pans = pos0;
    for(;pos0 < min(n0, w); pos0++) {
        if((w - pos0) & 1)
            ans -= min(p1[sufmin[pos1]].first.second,
                       p1[prefmin[pos1 - 1]].first.second -
                       p1[prefmin[pos1 - 1]].first.first +
                       p1[pos1].first.first);
        else {
            pos1--;
            ans += min(p1[sufmin[pos1]].first.second,
                       p1[prefmin[pos1 - 1]].first.second -
                       p1[prefmin[pos1 - 1]].first.first +
                       p1[pos1].first.first) - p1[pos1].first.first;
        }
        ans += p0[pos0].first;
        if(ans < bans) {
            bans = ans;
            pans = pos0 + 1;
        }
    }
    for(int i = 0; i < pans; i++)
        s[p0[i].second]++;
    int pans1 = (w - pans) / 2;
    for(int i = 0; i < pans1; i++)
        s[p1[i].second] = 2;
    if((w - pans) & 1) {
        if(!pans1 || p1[sufmin[pans1]].first.second <
           p1[prefmin[pans1 - 1]].first.second -
           p1[prefmin[pans1 - 1]].first.first + p1[pans1].first.first)
            s[p1[sufmin[pans1]].second] = 1;
        else {
            s[p1[prefmin[pans1 - 1]].second] = 1;
            s[p1[pans1].second] = 2;
        }
    }
    cout << bans << '\n';
    for(int i = 0; i < n; i++)
        cout << s[i];
    cout << '\n';
    return 0;
}