#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 1024

int n, i, j, k;
string s1, s2;
vector< pair< pair<string, char>, int> > v, rez, dif;
vector< char > aux;

string ans[maxN];
map< string, bool > M;

int cnt;
vector<int> list[maxN];
int l[maxN], r[maxN];
bool us[maxN];
int ss;

bool pairUp(int node) {
    if (us[node]) return false;
    us[node] = true;

    for (auto to : list[node]) {
        if (!r[to]) {
            //ss++;
            l[node] = to;
            r[to] = node;
            return true;
        }
    }

    for (auto to : list[node]) {
        if (pairUp(r[to])) {
            //ss++;
            l[node] = to;
            r[to] = node;
            return true;
        }
    }

    return false;
}

void solve(int p1, int p2) {
    int i;

    cnt = p2 - p1 + 1;
    for (i = 1; i <= max(33, cnt); i++) list[i].clear(), l[i] = r[i] = 0;
    for (i = p1; i <= p2; i++) {
        string aux = dif[i].first.first;
        if (M[aux] == 0)
            list[i - p1 + 1].pb(aux[2] - 'A' + 1);

        aux[2] = dif[i].first.second;
        if (M[aux] == 0)
            list[i - p1 + 1].pb(aux[2] - 'A' + 1);
    }

    bool ok = true;
    ss = 0;

    while (ok) {
        ok = false;
        for (i = 1; i <= cnt; i++) us[i] = false;

        for (i = 1; i <= cnt; i++)
            if (!l[i])
                ok |= pairUp(i);
    }

    for (i = 1; i <= cnt; i++)
        if (l[i])
            ss++;

    if (ss == cnt) {
        for (i = p1; i <= p2; i++)
            ans[ dif[i].second ] += 'A' + l[i - p1 + 1] - 1;
    } else {
        cout << "NO";
        exit(0);
    }
}

int main()
{
    //freopen("test.in","r",stdin);

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> s1 >> s2;
        s1.resize(3);
        v.pb(mp(mp(s1, s2[0]), i));
        ans[i] = s1[0];
        ans[i] += s1[1];
    }

    rez = v;

    sort(v.begin(), v.end());
    for (i = 0; i < v.size(); i = j) {
        aux.clear();
        for (j = i; j < v.size(); j++) {
            if (v[j].first.first != v[i].first.first) break;
            aux.pb(v[j].first.second);
        }

        sort(aux.begin(), aux.end());
        int sz1 = aux.size();

        aux.resize(unique(aux.begin(), aux.end()) - aux.begin());
        if (sz1 != aux.size()) {
            cout << "NO";
            return 0;
        }

        if (sz1 > 1) {
            for (k = i; k < j; k++) {
                ans[ v[k].second ] = ans[ v[k].second ] + v[k].first.second;
                if (M[ans[ v[k].second ]]) {
                    cout << "NO";
                    return 0;
                }

                M[ans[ v[k].second ]] = true;
            }
        } else {
            dif.pb(v[i]);
        }
    }

    for (i = 0; i < dif.size(); i = j) {
        for (j = i; j < dif.size(); j++)
            if (dif[i].first.first[0] != dif[j].first.first[0] || dif[i].first.first[1] != dif[j].first.first[1])
                break;

        solve(i, j - 1);
    }

    cout << "YES\n";
    for (i = 1; i <= n; i++)
        cout << ans[i] << '\n';


    return 0;
}