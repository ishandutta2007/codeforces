#include <bits/stdc++.h>

using namespace std;

set<int> people;
set<pair<int, int>> friends;
int k;

void read() {
    int m;
    cin >> m >> k;
    for (int i = 0, x, y; i < m; ++i) {
        cin >> x >> y;
        people.insert(x);
        people.insert(y);
        friends.emplace(x, y);
        friends.emplace(y, x);
    }
}

bool isFriends(int x, int y) {
    return friends.find(make_pair(x, y)) != friends.end();
}

void kill() {
    for (auto x : people) {
        cout << x << ": ";

        set<int> xFriends, ans;
        for (auto y : people)
            if (isFriends(x, y))
                xFriends.insert(y);
        for (auto z : people) {
            int t = 0;
            if (isFriends(x, z) || x == z)
                continue;
            for (auto y : xFriends)
                if (isFriends(y, z))
                    ++t;
            if (t * 100 >= k * xFriends.size())
                ans.insert(z);
        }
        cout << ans.size() << " ";
        for (auto y : ans)
            cout << y << " ";
        cout << "\n";
    }
}

int main() {
    read();
    kill();
    return 0;
}