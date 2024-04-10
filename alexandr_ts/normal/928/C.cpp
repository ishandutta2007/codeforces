#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <ld, ld> pl;

const int N = 1e3 + 10;
const ld EPS = 1e-9;
const ll INF = 1e9 + 10;

char s1[20];
int v[N];
string s[N];
int num[N];
vector <pair <string, int> > tmp[N];
bool take[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    int v1;
    map <pair <string, int>, int> m1;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        while (s[i] == "" || !isalpha(s[i][0]))
            cin >> s[i];
        cin >> v[i];
        m1[{s[i], v[i]}] = i;
        int m, x;
        cin >> m;
        string temp1;
        for (int j = 0; j < m; j++) {
            cin >> temp1 >> x;
            tmp[i].pb({temp1, x});
        }
    }

    set <tuple<int, int, int> > q;
    q.insert(make_tuple(0, -v[0], 0));
    set <string> usedNames;

    while (q.size()) {
        int v = get<2>(*q.begin());
        int dist = get<0>(*q.begin());
        q.erase(q.begin());
        used[v] = true;
        if (!usedNames.count(s[v])) {
            take[v] = true;
            usedNames.insert(s[v]);
            for (auto t: tmp[v]) {
                int x = m1[t];
                if (!used[x] && !usedNames.count(t.first))
                    q.insert(make_tuple(dist + 1, -t.second, x));
            }
        }
    }

    vector <pair <string, int> > ans;

    for (int i = 1; i < n; i++)
        if (take[i])
            ans.pb({s[i], v[i]});

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto t: ans)
        cout << t.first << " " << t.second << endl;



}