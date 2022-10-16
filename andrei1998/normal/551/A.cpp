#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define out(x) cout << "x = " << x << endl;

using namespace std;

struct stud {
    int rat;
    int pos;
} v[2005];

bool operator< (const stud &a, const stud &b) {
    return a.rat > b.rat;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> v[i].rat;
        v[i].pos = i;
    }

    sort(v + 1, v + n + 1);

    int ans[2005];

    int current = 1;
    ans[v[1].pos] = current;

    for (int i = 2; i <= n; i++) {
        if (v[i].rat != v[i - 1].rat)
            current = i;

        ans[v[i].pos] = current;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " \n"[i == n];
    return 0;
}