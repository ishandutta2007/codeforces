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
#include <random>
#include <functional>

using namespace std;

#define F first
#define S second
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << ": "; for (auto& xxxx: a) cerr << xxxx << " "; cerr << endl;
#define forn(i, n) for (int i = 0; i < (n); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))
#define equal equalll
#define less lesss

typedef double dbl;
typedef long long ll;
const int N = 3e5;
const int INF = 1.01e9;
typedef vector<int> vi;

struct Ans {
    int res[3][3];
};

struct Event {
    int type, t, l, r, x, y, id;
};

int fen[N];

void add(int pos, int val) {
    for (; pos + 1 < N; pos |= (pos + 1))
        fen[pos + 1] += val;
}

int get(int r) {
    int sum = 0; 
    for (; r > 0; r &= (r - 1)) {
        sum += fen[r];
    }
    return sum;
}

int get(int l, int r) {
    return get(r) - get(l);
}

int main(){
#ifdef HOME 
    assert(freopen("in", "r", stdin));
#endif
    int n, q;
    scanf("%d%d", &n, &q);
    vector<int> perm(n);
    vector<Event> event;
    forn(i, n) {
        scanf("%d", &perm[i]); perm[i]--;
        event.pb({1, i, perm[i], -1, -1, -1, -1});
    }
     
    vector<Ans> ans(q);
    forn(i, q) {
        int l, r, d, u;
        scanf("%d%d%d%d", &l, &d, &r, &u); l--; d--;
        event.pb({2, l, 0, d, 0, 0, i});
        event.pb({2, l, d, u, 1, 0, i});
        event.pb({2, l, u, n, 2, 0, i});
        event.pb({2, r, 0, d, 0, 1, i});
        event.pb({2, r, d, u, 1, 1, i});
        event.pb({2, r, u, n, 2, 1, i});
        event.pb({2, n, 0, d, 0, 2, i});
        event.pb({2, n, d, u, 1, 2, i});
        event.pb({2, n, u, n, 2, 2, i});
    }   

    sort(all(event), [](Event A, Event B) {
            return A.t < B.t || (A.t == B.t && A.type > B.type);
            });
    for(auto E: event) {
        if (E.type == 1) {
            add(E.l, 1);
        }
        else {
            ans[E.id].res[E.x][E.y] = get(E.l, E.r);
        }
    }

    forn(i, q) {
        auto& a = ans[i].res;
        forn(j, 3) {
            a[j][2] -= a[j][1];
            a[j][1] -= a[j][0];
        }
        ll answer = a[1][1] *  1ll * (a[1][1] - 1) / 2;
        forn(x, 3) {
            forn(y, 3) {
                forn(xx, 3) {
                    forn(yy, 3) {
                        if (xx > x || (xx == x && yy > y)) {
                            if (min(x, xx) <= 1 && max(x, xx) >= 1 && min(y, yy) <= 1 && max(y, yy) >= 1) {
                                answer += a[x][y] * 1ll * a[xx][yy];
                            }
                        }
                    }
                }
            }
        }
        cout << answer << "\n";
    }

    
    
#ifdef HOME 
    epr("time = %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC));
#endif
    return 0;
}