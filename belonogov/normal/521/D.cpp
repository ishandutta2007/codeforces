
#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e5 + 100;
const int INF = 1e9;

struct Frac {
    long long x, y, id;
    Frac(): x(0), y(1), id(-1) { }
    Frac(long long x, long long y, int id): x(x), y(y), id(id) { }
    bool operator < (const Frac & A) const {
        if (x / y != A.x / A.y) {
            return x / y < A.x / A.y;
        }
        long long x1 = x % y;
        long long Ax1 = A.x % A.y;
        return x1 * A.y < y * Ax1 || (x1 * A.y == y * Ax1 && id < A.id);
    }
};

int k, n, m;
int a[N];
Frac apply[N];
vector < Frac > e[N];
set < Frac > q;
int type[N];

bool cmpT(int a, int b) {
    return type[a] < type[b];
}

void read() {
    scanf("%d%d%d", &k, &n, &m);
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        int t, l, b;
        scanf("%d%d%d", &t, &l, &b); l--;
        type[i] = t;
        if (t == 1) {
            apply[l] = max(apply[l], Frac(b, 1, i));
        }
        else if (t == 2) {
            e[l].pb(Frac(b, 1, i));
        }
        else if (t == 3) {
            q.insert(Frac(b, 1, i));
        }
        else
            assert(false);
    }

    for (int i = 0; i < k; i++) {
        if (a[i] < apply[i].x) {
            e[i].pb(Frac(apply[i].x - a[i], 1, apply[i].id));
            }sort(e[i].begin(), e[i].end());
            long long val = a[i];;
            for (int j = (int)e[i].size() - 1; j >= 0; j--) {
                q.insert(Frac(val + e[i][j].x, val, e[i][j].id)); 
                val += e[i][j].x;
            }
       
    } 
    vector < int > answer;
    for (int i = 0; i < m && !q.empty(); i++) {
        auto it = q.end(); it--; 
        answer.pb(it->id);
        q.erase(it);
    }
    sort(answer.begin(), answer.end(), cmpT);
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", x + 1); 
    printf("\n");
}

void solve() {

}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}