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
#define all(a) (a).begin(), (a).end()

#define equal equalll
#define less lesss
const int N = 1e3;
const long long INF = 1e9 + 19;

int n, m;
vector < int > e[N];
char s[N];
int a[N][N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d%d", &v, &u); v--; u--;
        e[v].pb(u);
        e[u].pb(v);
        a[v][u] = 1;
        a[u][v] = 1;
    }

}

void solve() {
    for (int i = 0; i < n; i++) {
        e[i].pb(i);
        a[i][i] = 1;
    }
    //for (int i = 0; i < n; i++)
        //db(e[i].size());
    //for (int i = 0; i < n; i++)
        //cerr << s[i] << " ";
    //cerr << endl;


    for (int i = 0; i < n; i++) {
        if ((int)e[i].size() == n) {
            //db(i);
            s[i] = 'b';
        }
    } 
    //for (int i = 0; i < n; i++)
        //db(e[i].size());
    //for (int i = 0; i < n; i++)
        //cerr << s[i] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'b') {
            s[i] = 'a';
            for (auto u: e[i])
                if (s[u] != 'b')
                    s[u] = 'a';
            for (int j = 0; j < n; j++)
                if (s[j] != 'a' && s[j] != 'b')
                    s[j] = 'c';

            break;
        }
    }
    
    bool flag = 1;
     
    //cerr << s << endl;
    //for (int i = 0; i < n; i++, cerr << endl)
        //for (int j = 0; j < n; j++)
            //cerr << a[i][j] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            flag &= (abs(s[i] - s[j]) <= 1) == a[i][j];
        }

    if (flag) {
        puts("Yes");
        printf("%s\n", s);
    }
    else {
        puts("No");
    }
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