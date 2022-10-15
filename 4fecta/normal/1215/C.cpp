#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n;
string a, b;

int main() {
    boost();

    cin >> n >> a >> b;
    vector<pii> ans;
    queue<int> q1;
    queue<int> q2;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'a' && b[i] == 'b') {
            q1.push(i);
        } else if (a[i] == 'b' && b[i] == 'a') {
            q2.push(i);
        }
    }
    int cnt = 0;
    while (q1.size() > 1) {
        cnt++;
        int f = q1.front();
        q1.pop();
        int s = q1.front();
        q1.pop();
        ans.push_back({f, s});
    }

    while (q2.size() > 1) {
        cnt++;
        int f = q2.front();
        q2.pop();
        int s = q2.front();
        q2.pop();
        ans.push_back({f, s});
    }

    if (!q1.size() && !q2.size()) {
        printf("%d\n", cnt);
        for (pii i : ans) {
            printf("%d %d\n", i.f + 1, i.s + 1);
        }
        return 0;
    }

    if (!q1.size() || !q2.size()) {
        printf("-1\n");
        return 0;
    }
    ans.push_back({q1.front(), q1.front()});
    ans.push_back({q1.front(), q2.front()});
    cnt += 2;
    printf("%d\n", cnt);
    for (pii i : ans) {
        printf("%d %d\n", i.f + 1, i.s + 1);
    }

    return 0;
}