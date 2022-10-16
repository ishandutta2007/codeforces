#include <iostream>
#include <algorithm>
#include <set>
#include <utility>

#define lint long long int
using namespace std;

struct island {
    lint st, dr;
} islands[2 * 100005];

struct interv {
    lint st, dr;
    int pos;
} intervs[2 * 100005];

bool operator< (const interv &a, const interv &b) {
    return a.dr < b.dr;
}

set <pair <lint, int> > Set;

lint ans[2 * 100005];

int main()
{
    ios_base :: sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> islands[i].st >> islands[i].dr;

    for (int i = 1; i < n; i++)
        intervs[i].pos = i, intervs[i].st = islands[i + 1].st - islands[i].dr, intervs[i].dr = islands[i + 1].dr - islands[i].st;
    sort(intervs + 1, intervs + n);

    lint x;
    for (int i = 1; i <= m; i ++) {
        cin >> x;
        Set.insert(make_pair(x, i));
    }

    set <pair <lint, int> > :: iterator it;
    for (int i = 1; i < n; i++) {
        it = Set.lower_bound(make_pair(intervs[i].st, 0));

        if (it == Set.end() || it -> first > intervs[i].dr) {
            cout << "No\n";
            return 0;
        }

        ans[intervs[i].pos] = it -> second;
        Set.erase(it);
    }

    cout << "Yes\n";
    for (int i = 1; i < n; i++)
        cout << ans[i] << " \n"[i == (n - 1)];

    return 0;
}