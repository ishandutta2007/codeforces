#include <bits/stdc++.h>

using namespace std;

const int NMAX = 100000 + 5;

int N;
int b[NMAX];
int extend[NMAX];
vector <int> freq[NMAX];

int ans[NMAX];
vector <pair <int, int> > queries[NMAX];

void add(int aib[], int where, int val) {
    if (where == 0)
        return ;
    for (; where <= N; where += where & (-where))
        aib[where] += val;
}
int query(int aib[], int where) {
    int ans = 0;
    for (; where; where -= where & (-where))
        ans += aib[where];
    return ans;
}
int query(int aib[], int l, int r) {
    int ans = query(aib, r);
    if (l > 0)
        ans -= query(aib, l - 1);
    return ans;
}

int aib_colors[NMAX];
int aib_constraints[NMAX];

int main()
{
    ios_base :: sync_with_stdio(false);
    //freopen("data.in", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; ++ i)
        cin >> b[i];

    int M;
    cin >> M;
    for (int i = 1; i <= M; ++ i) {
        int l, r;
        cin >> l >> r;
        queries[r].push_back(make_pair(l, i));
    }

    for (int i = 1; i <= N; ++ i) {
        const int val = b[i];
        vector <int> &v = freq[val];
        v.push_back(i);

        if (v.size() <= 2)
            extend[i] = 0;
        else {
            const int dif = v[v.size() - 1] - v[v.size() - 2];
            if (dif == v[v.size() - 2] - v[v.size() - 3])
                extend[i] = extend[v[v.size() - 2]];
            else
                extend[i] = v[v.size() - 3];
        }

        if (v.size() > 1) {
            add(aib_colors, v[v.size() - 2], -1);
            add(aib_constraints, extend[v[v.size() - 2]], -1);
        }
        add(aib_colors, i, 1);
        add(aib_constraints, extend[i], 1);

        for (auto it: queries[i]) {
            const int l = it.first;
            const int r = i;
            const int pos = it.second;
            int &anss = ans[pos];

            anss = query(aib_colors, l, r);
            if (query(aib_constraints, l, r) == anss)
                ++ anss;
        }
    }

    for (int i = 1; i <= M; ++ i)
        cout << ans[i] << '\n';
    return 0;
}