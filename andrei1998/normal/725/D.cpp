#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int NMAX = 300000 + 5;
typedef long long int lint;

struct Team {
    lint t, w;
    int name;

    friend bool operator<(const Team &a, const Team &b) {
        if (a.t != b.t)
            return a.t > b.t;
        else
            return a.name < b.name;
    }
} teams[NMAX];

int cnt;
lint sum;
set <pair <lint, int> > Set;

int main()
{
    //freopen("data.in", "r", stdin);
    ios_base :: sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; ++ i) {
        cin >> teams[i].t >> teams[i].w;
        teams[i].name = i;
    }

    teams[N + 1].t = 0;
    teams[N + 1].name = N + 1;
    ++ N;
    sort(teams + 1, teams + N + 1);

    int where = -1;
    for (int i = 1; i <= N; ++ i)
        if (teams[i].name == 1) {
            where = i;
            break;
        }
    int ans = where;

    for (int i = 1; i < where; ++ i)
        Set.insert(make_pair(teams[i].w - teams[i].t + 1, i));
    set <pair <lint, int> > :: iterator it = Set.begin();

    for (int i = where + 1; i <= N; ++ i) {
        lint allowed = teams[where].t - teams[i].t;

        while (it != Set.end() && sum + it -> first <= allowed) {
            sum += it -> first;
            ++ cnt;
            ++ it;
        }

        ans = min(ans, i - cnt - 1);

        pair <lint, int> aux = make_pair(teams[i].w - teams[i].t + 1, i);

        if (it == Set.end() || aux < *it) {
            Set.insert(aux);
            sum += aux.first;
            ++ cnt;

            while (it != Set.begin() && sum > allowed) {
                -- it;
                sum -= it -> first;
                -- cnt;
            }
        }
        else
            Set.insert(aux);
    }

    cout << ans << '\n';
    return 0;
}