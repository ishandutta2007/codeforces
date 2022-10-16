#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > events;

int main()
{
    ios_base :: sync_with_stdio(false);

    int N;
    cin >> N;

    while (N --) {
        int l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }

    sort(events.begin(), events.end());

    int cnt = 0;
    for (auto it: events) {
        cnt += it.second;
        if (cnt > 2) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}