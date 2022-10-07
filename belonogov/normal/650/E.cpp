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
const int N = 5e5 + 10;
const long long INF = 1e9 + 19;


#include <cstdio>
#include <algorithm>

/** Interface */

template <class T = int> inline T readInt();            
inline double readDouble();
inline int readUInt();           
inline int readChar();           
inline void readWord( char *s ); 
inline bool readLine( char *s ); // do not save '\n'
inline bool isEof();
inline int peekChar();
inline bool seekEof();

template <class T> inline void writeInt( T x, int len );
template <class T> inline void writeUInt( T x, int len );
template <class T> inline void writeInt( T x ) { writeInt(x, -1); };
template <class T> inline void writeUInt( T x ) { writeUInt(x, -1); };
inline void writeChar( int x ); 
inline void writeWord( const char *s );
inline void writeDouble( double x, int len = 0 );
inline void flush();

/** Read */

static const int buf_size = 1e7; 

inline int readUInt() {
  int c = getchar(), x = 0;
  while ('0' <= c && c <= '9')
    x = x * 10 + c - '0', c = getchar();
  return x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
  if (write_pos == buf_size)
    fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
  write_buf[write_pos++] = x;
}

inline void flush() {
  if (write_pos)
    fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
}

template <class T> 
inline void writeInt( T x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;

  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

template <class T> 
inline void writeUInt( T x, int output_len ) {
  char s[24];
  int n = 0;
  while (x || !n)
    s[n++] = '0' + x % 10, x /= 10;
  while (n < output_len)
    s[n++] = '0';
  while (n--)
    writeChar(s[n]);
}

inline void writeWord( const char *s ) {
  while (*s)
    writeChar(*s++);
}

inline void writeDouble( double x, int output_len ) {
  if (x < 0)
    writeChar('-'), x = -x;
  int t = (int)x;
  writeUInt(t), x -= t;
  writeChar('.');
  for (int i = output_len - 1; i > 0; i--) {
    x *= 10;
    t = std::min(9, (int)x);
    writeChar('0' + t), x -= t;
  }
  x *= 10;
  t = std::min(9, (int)(x + 0.5));
  writeChar('0' + t);
}


int n;
set < int > e[N];
vector < pair < int, int > > g[N];
int p[N];
set < pair < int, int > > needDel;
vector < pair < pair < int, int >, pair < int, int > > > answer;
bool fin[N];
vector < pair < int, int > > e1;
vector < pair < int, int > > e2;




void read() {
    //scanf("%d", &n);
    n = readUInt();
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        //scanf("%d%d", &v, &u);
        v = readUInt();
        u = readUInt();
        v--; u--;
        e1.pb(mp(v, u));
    }
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        //scanf("%d%d", &v, &u);
        v = readUInt();
        u = readUInt();
        v--; u--;
        e2.pb(mp(v, u));
    }
}

int getId(int v) {
    return (p[v] == v)? v: p[v] = getId(p[v]);
}


void merge(int v, int u) {
    //db("start");
    v = getId(v);
    u = getId(u);
    //if (v == u) return;
    assert(v != u);
    if (g[v].size() < g[u].size())
       swap(g[v], g[u]); 
    for (;!g[u].empty(); g[u].pop_back()) {
        //db(g[u].size());
        g[v].pb(g[u].back());  
    }
    p[u] = v;
    //db("fin");
}

void dfs(int v, int p) {
    //db2(v, p);
    for (auto it = e[v].begin(); it != e[v].end();) {
        int u = *it;
        if (u == p || fin[u]) {
            it++;
            continue;
        }
        dfs(u, v);
        //db(v);
        int vv = v;
        int uu = u;
        if (vv > uu) swap(vv, uu);
        if (needDel.count(mp(vv, uu)) == 1) {
            //db("here");
            it++;
            e[v].erase(u);
            e[u].erase(v);
            int top = getId(u);
            assert(top == u);
            bool flag = 0;
            //db2(g[top].size(), top);
            for (int i = (int)g[top].size() - 1; i >= 0; i--) {
                //db(i);
                int x = g[top][i].fr;
                int y = g[top][i].sc;
                //db2(x, y);
                auto tmp = g[top].back();
                g[top].pop_back();
                x = getId(x);
                y = getId(y);
                //db2(x, y);
                if (x != y) {
                    answer.pb(mp(mp(v, u), tmp));
                    flag = 1;   
                    if (x != top) 
                        swap(x, y);
                    //db2(x, y);
                    assert(x == top);
                    if (fin[y]) {
                        merge(y, x);
                    }
                    else {
                        e[y].insert(x);
                        e[x].insert(y);
                    }
                    break;
                }
            }
            assert(flag);
        }
        else {
            it++;
        }
    }
    for (auto u: e[v]) {
        if (u == p) continue;
        assert(fin[u]);
        merge(v, u);
    } 
    fin[v] = 1;
}

void solve() {
    for (auto x: e1) {
        int v = x.fr;
        int u = x.sc;
        if (v > u) swap(v, u);
        needDel.insert(mp(v, u));

        e[v].insert(u);
        e[u].insert(v);
    }
    for (auto x: e2) {
        int v = x.fr;
        int u = x.sc;
        if (v > u) swap(v, u);
        needDel.erase(mp(v, u));
        g[v].pb(mp(v, u));
        g[u].pb(mp(v, u));
    }

    for (int i = 0; i < n; i++)
        p[i] = i;
    dfs(0, -1);

}



//int n;
//set < int > e[N];
//vector < pair < int, int > > g[N];
//int p[N];
//set < pair < int, int > > needDel;
//vector < pair < pair < int, int >, pair < int, int > > > answer;
//bool fin[N];
//vector < pair < int, int > > e1;
//vector < pair < int, int > > e2;


void printTest() {
    printf("%d\n", n);
    for (auto x: e1)
        printf("%d %d\n", x.fr + 1, x.sc + 1);
    for (auto x: e2)
        printf("%d %d\n", x.fr + 1, x.sc + 1);
}

void stress() {
    for (int tt = 0; ; tt++) {
        db(tt);
        e1.clear();
        e2.clear();
        n = 100;
        for (int i = 0; i < n; i++)
            e[i].clear();
        for (int i = 0; i < n; i++)
            g[i].clear();
        
        needDel.clear();
        answer.clear();
        for (int i = 0; i < n; i++)
            fin[i] = 0;
        
        for (int i = 1; i < n; i++) {
            int v = rand() % i;
            int u = rand() % i;
            e1.pb(mp(i, v));
            e2.pb(mp(u, i));
        }
        //printTest();
        solve();
        //db(answer.size());
    }
}

void printAns() {
    //printf("%d\n", (int)answer.size());
    writeInt(answer.size());
    writeChar('\n');
    for (auto x: answer) {
        //printf("%d %d %d %d\n", x.fr.fr + 1, x.fr.sc + 1, x.sc.fr + 1, x.sc.sc + 1);
        writeInt(x.fr.fr + 1);
        writeChar(' ');
        writeInt(x.fr.sc + 1);
        writeChar(' ');
        writeInt(x.sc.fr + 1);
        writeChar(' ');
        writeInt(x.sc.sc + 1);
        writeChar('\n');
    }
    flush();
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("test.txt", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    //writeDouble(1e10, 10);
    //writeDouble(1e9, 10);
    //flush();
    //return 0;
    if (1) {
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
            //cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
        }
    }
    else {
        stress();
    }

    return 0;
}