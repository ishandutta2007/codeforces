#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e3 + 100, inf = 1e9 + 100;

int n, m, k;

bool a[maxn][maxn];

int sti, stj;

pair<int, int> que[maxn * maxn];

int cnt;

int bfs[maxn][maxn];

string answer;

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    if (k % 2 == 1){
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++){
        char x;
        cin >> x;
        if (x == 'X')
            sti = i, stj = j;
        else
        if (x == '*')
            a[i][j] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            bfs[i][j] = inf;
    bfs[sti][stj] = 0;
    cnt = 1;
    que[0] = make_pair(sti, stj);
    for (int i = 0; i < cnt; i++){
        int x = que[i].first, y = que[i].second;
        if (x > 0 && !a[x - 1][y] && bfs[x - 1][y] == inf)
            bfs[x - 1][y] = bfs[x][y] + 1, que[cnt] = make_pair(x - 1, y), cnt++;
        if (y > 0 && !a[x][y - 1] && bfs[x][y - 1] == inf)
            bfs[x][y - 1] = bfs[x][y] + 1, que[cnt] = make_pair(x, y - 1), cnt++;
        if (x < n - 1 && !a[x + 1][y] && bfs[x + 1][y] == inf)
            bfs[x + 1][y] = bfs[x][y] + 1, que[cnt] = make_pair(x + 1, y), cnt++;
        if (y < m - 1 && !a[x][y + 1] && bfs[x][y + 1] == inf)
            bfs[x][y + 1] = bfs[x][y] + 1, que[cnt] = make_pair(x, y + 1), cnt++;
    }
    int x = sti, y = stj;
    for (int i = 0; i < k / 2; i++){
        if (x < n - 1 && !a[x + 1][y]){
            answer.push_back('D');
            x++;
            continue;
        }
        if (y > 0 && !a[x][y - 1]){
            answer.push_back('L');
            y--;
            continue;
        }
        if (y < m - 1 && !a[x][y + 1]){
            answer.push_back('R');
            y++;
            continue;
        }
        if (x > 0 && !a[x - 1][y]){
            answer.push_back('U');
            x--;
            continue;
        }
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (int i = k / 2; i > 0; i--){
        if (x < n - 1 && bfs[x + 1][y] < i){
            answer.push_back('D');
            x++;
            continue;
        }
        if (y > 0 && bfs[x][y - 1] < i){
            answer.push_back('L');
            y--;
            continue;
        }
        if (y < m - 1 && bfs[x][y + 1] < i){
            answer.push_back('R');
            y++;
            continue;
        }
        if (x > 0 && bfs[x - 1][y] < i){
            answer.push_back('U');
            x--;
            continue;
        }
        cout << "IMPOSSIBLE";
        return 0;
    }
    cout << answer;
}