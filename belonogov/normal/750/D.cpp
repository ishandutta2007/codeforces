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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 400;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int SHIFT = 200;
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct State {
    int x, y, dir;
    bool operator < (State A) const {
        return x < A.x || (x == A.x && (y < A.y || (y == A.y && dir < A.dir)));
    }
};

int n;
int t[N];
bool use[N][N];



void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
}

void solve() {
    set<State> q;
    q.insert({0, 0, 0});    

    //use[SHIFT][SHIFT] = 1;
    for (int i = 0; i < n; i++) {
        set<State> w;
        for (auto s: q) {
            int x = s.x;
            int y = s.y;
            for (int j = 0; j < t[i]; j++) {
                x += dx[s.dir];
                y += dy[s.dir];
                use[SHIFT + x][y + SHIFT] = 1;
            }
            w.insert({x, y, (s.dir + 1) % 8});
            w.insert({x, y, (s.dir + 7) % 8});
        }
        q = w;
    } 


    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res += use[i][j];
    cout << res << endl;
}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}