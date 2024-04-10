#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1111;
const long long INF = 1e9 + 19;

int n, m;
char s[N][N];
int dist[3][N][N];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
}

bool check(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void solve() {
    memset(dist, 63, sizeof(dist));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (isdigit(s[i][j]))
                s[i][j]--;
    for (int color = 0; color < 3; color++) {
        deque < pair < int, int > > q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (s[i][j] == '0' + color) {
                    q.push_back(mp(i, j));
                    dist[color][i][j] = 0;
                } 

        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            int x = p.fr;
            int y = p.sc;
            for (int t = 0; t < 4; t++) {
                int x1 = x + dx[t];
                int y1 = y + dy[t];
                if (check(x1, y1) && s[x1][y1] != '#') {
                    int cost = (isdigit(s[x1][y1]))? 0: 1; 
                    if (dist[color][x1][y1] > dist[color][x][y] + cost) {
                        dist[color][x1][y1] = dist[color][x][y] + cost;
                        if (cost == 1)
                            q.push_back(mp(x1, y1));
                        else
                            q.push_front(mp(x1, y1));
                    }
                }
            }

        }
    }
     
      

    long long answer = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            long long sum = 0;
            if (s[i][j] == '.')
                sum = -2;
            for (int t = 0; t < 3; t++)
                sum += dist[t][i][j];
            //if (sum == 4) {
                //db2(i, j);
            //}
            answer = min(answer, sum); 
        }
    if (answer < INF)
        cout << answer << endl;
    else
        puts("-1");

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
        }
    }
    else {
        stress();
    }

    return 0;
}