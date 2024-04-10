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
const int N = 155;
const long long INF = 1e9 + 19;
const int M = 1e5 + 10;


int n, m, k;
char s[N][N];
bitset < N > b[N];
bitset < N > lab[N];
bitset < N > dlab[N];
char t[M];


void read() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    scanf("%s", t);
}

void solve() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (s[i][j] != '#')
                lab[i][j] = 1;
            else
                dlab[i][j] = 1;

    for (int i = 0; i < n; i++)
        b[i] = lab[i];

    int fx = -1, fy = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'E') {
                fx = i;
                fy = j;
            }
    assert(fx != -1 && fy != -1);


    for (int i = 0; i <= k; i++) {
        //cerr << "============\n";
        //db(i);
        //for (int x = 0; x < n; x++, cerr << endl)
            //for (int y = 0; y < m; y++)
                //cerr << b[x][y] << " ";
        //cerr << endl;


        int cnt = 0;
        for (int j = 0; cnt < 2 && j < n; j++) {
            //db(j);
            int x = b[j].any();
            if (x > 0) {
                //db("here");
                for (int t = 0; t < m && cnt < 2; t++)
                    cnt += b[j][t];
            }
        }

        assert(cnt > 0);
        if (cnt == 1) {
            int x = -1, y = -1; 
            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                    if (b[i][j]) {
                        x = i;
                        y = j;
                    }   
            //db2(x, y);
            for (; ;i++) {
                if (x == fx && y == fy) {
                    printf("%d\n", i);
                    return;
                }
                if (i < k) {
                    if (t[i] == 'L')
                        if (s[x][y - 1] != '#')
                            y--;
                    if (t[i] == 'R')
                        if (s[x][y + 1] != '#')
                            y++;
                    if (t[i] == 'U')
                        if (s[x - 1][y] != '#')
                            x--;
                    if (t[i] == 'D')
                        if (s[x + 1][y] != '#')
                            x++;
                }
                else
                    break;
            }
            puts("-1");

            return; 
        }
        if (i == k) break;
        if (t[i] == 'R') 
            for (int j = 0; j < n; j++)
                b[j] = ((b[j] << 1) & lab[j]) | (((b[j] << 1) & dlab[j]) >> 1);

        if (t[i] == 'L')
            for (int j = 0; j < n; j++)
                b[j] = ((b[j] >> 1) & lab[j]) | (((b[j] >> 1) & dlab[j]) << 1);
                //b[j] = (b[j] >> 1) & lab[j];
        if (t[i] == 'D') {
            for (int j = n - 2; j > 0; j--)
                b[j] = (b[j - 1] & lab[j]) | (b[j] & dlab[j + 1]);
        }
        if (t[i] == 'U') {
            for (int j = 1; j + 1 < n; j++)
                b[j] = (b[j + 1] & lab[j]) | (b[j] & dlab[j - 1]);
        }

    } 

    puts("-1");

}

void stress() {

}


int main(){
#ifdef DEBUG
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