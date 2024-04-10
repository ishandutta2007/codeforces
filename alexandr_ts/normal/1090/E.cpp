#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 10;


bool desk[N][N];
bool rez[N][N];

int dx[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int dy[] = {-2, 2, 1, -1, -2, 2, -1, 1};

int dist[N][N];
pair<int, int> par[N][N];

void bfs(int x, int y) {
    frab(i, 1, 9)
        frab(j, 1, 9)
            dist[i][j] = INF;
    dist[x][y] = 0;
    queue <pair<int, int> > q;
    q.push({x, y});
    while (q.size()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int x1 = dx[i] + t.first;
            int y1 = dy[i] + t.second;
            if (x1 < 1 || x1 > 8 || y1 < 1 || y1 > 8) continue;
            if (dist[x1][y1] == INF) {
                dist[x1][y1] = dist[t.first][t.second] + 1;
                par[x1][y1] = t;
                q.push({x1, y1});
            }
        }
    }
}

void check(vector<pair<pair<int, int>, pair<int, int> > > answer, vector<pair<int, int> > input) {
    vector<vector<int> > d(9, vector<int>(9, 0));
    for (auto t: input)
        d[t.first][t.second] = true;
    for (auto t: answer) {
        assert(d[t.fi.fi][t.fi.se]);
        assert(!d[t.se.fi][t.se.se]);
        swap(d[t.fi.fi][t.fi.se], d[t.se.fi][t.se.se]);
    }
    vector<int> v;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            v.pb(d[i][j]);
//     for (int i = 1; i <= 8; i++)
//        for (int j = 1; j <= 8; j++)
//            cout << d[i][j] << (j == 8 ? "\n" : "");
    for (int i = 0; i + 1 < v.size(); i++)
        assert(v[i] >= v[i + 1]);
    assert(accumulate(v.begin(), v.end(), 0) == input.size());
}

int main() {

//    freopen("a.in", "w", stdout);
//    for (char a = 'a'; a <= 'h'; a++)
//        for (int i= 1; i <= 8; i++)
//            cout << a << i << endl;
//    return 0;
//    ios_base::sync_with_stdio(false);


    //freopen("a.in", "r", stdin);
    int n;
    cin >> n;
    string s;
    vector<pair<int, int> > input;
    fr(i, n) {
        cin >> s;
        //cout << s << endl;
        desk[s[1] - '0'][s[0] - 'a' + 1] = 1;
        input.push_back({s[1] - '0', s[0] - 'a' + 1});
    }

    for (int i = 1; i <= (n + 7) / 8; i++)
        for (int j = 1; j <= (i == (n + 7) / 8 ? (n - 1) % 8 + 1 : 8); j++)
            rez[i][j] = true;

//    for (int i = 1; i <= 8; i++)
//        for (int j = 1; j <= 8; j++)
//            cout << desk[i][j] << (j == 8 ? "\n" : "");

    vector<pair<pair<int, int>, pair<int, int> > > answer;

    frab(i, 1, 9) {
        frab(j, 1, 9) {
            if (desk[i][j] || !rez[i][j]) continue;
            int x = -1, y = -1;
            frab(i1, 1, 9)
                if (x == -1)
                    frab(j1, 1, 9)
                        if (!rez[i1][j1] && desk[i1][j1]) {
                            x = i1, y = j1;
                            break;
                        }
            assert(x != -1);
            bfs(x, y);
            vector<pair<int, int> > seq = {{i, j}};
            int curx = i, cury = j;
            while (curx != x || cury != y) {
                auto t = par[curx][cury];
                curx = t.first;
                cury = t.second;
                //cout << "curs " << curx << " " << cury << endl;
                seq.push_back({curx, cury});
            }

//            for (auto x: seq)
//                cout << x.first << " " << x.second << endl;
//            cout << endl;

            vector<bool> horse(seq.size(), false);
            for (int i = 0; i + 1 < seq.size(); ++i)
                if (!i || desk[seq[i].first][seq[i].second])
                    horse[i] = true;
            for (int i = 0; i < seq.size(); i++) {
                if (desk[seq[i].first][seq[i].second]) {
                    vector<pair<int, int> > miniAns = {seq[i]};
                    int curi = i;
                    do {
                        curi--;
                        miniAns.push_back(seq[curi]);
                    } while (!horse[curi]);
                    for (int i = 0; i + 1 < miniAns.size(); i++) {
                        answer.push_back({miniAns[i], miniAns[i + 1]});
                    }
                }
            }
            desk[x][y] = 0;
            desk[i][j] = 1;
        }
    }

    cout << answer.size() << endl;
    assert(answer.size() < 1500);
    for (auto step: answer) {
        cout << (char)(step.first.second + 'a' - 1) << step.first.first << "-" <<
                (char)(step.second.second + 'a' - 1) << step.second.first << endl;
    }

    check(answer, input);


}