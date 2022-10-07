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
const int N = 4;
const long long INF = 1e9 + 19;

struct pnt {
    int x, y, id; 
    pnt () { }
    pnt (int x, int y, int id): x(x), y(y), id(id) { }
    pnt (int x, int y): x(x), y(y) { }
};

pnt p[N];
int n = 4;

void read() {
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].id = i;
    }

}

int answer;
pnt res[N];

int g[4][2] = {
    {0, 0 },
    {1, 0 },
    {0, 1 },
    {1, 1 }
};

int type[N];

int dist(pnt A, pnt B) {
    if (A.x == B.x)
        return abs(A.y - B.y);
    if (A.y == B.y)
        return abs(A.x - B.x);

    return INF;
}


void solve() {
    answer = INF;

    for (int tt = 0; tt < 2; tt++) {
        sort(p, p + n, [](pnt A, pnt B) { return A.y < B.y || (A.y == B.y && A.x < B.x); });

        //for (int i = 0; i < n; i++)
            //db2(p[i].x, p[i].y);

        if (p[0].y == p[1].y && p[2].y == p[3].y && p[0].y != p[2].y) {
            //db("here");
            int h = p[2].y - p[0].y;
            int l = -1; 
            int r = INF;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                int ll = -INF; 
                int rr = INF;
                ll = max(ll, p[0].x - mid);
                rr = min(rr, p[0].x + mid);

                ll = max(ll, p[2].x - mid);
                rr = min(rr, p[2].x + mid);
                
                ll = max(ll, p[1].x - mid - h);
                rr = min(rr, p[1].x + mid - h);

                ll = max(ll, p[3].x - mid - h);
                rr = min(rr, p[3].x + mid - h);

                if (ll <= rr)
                    r = mid;
                else
                    l = mid;
            }
            //db2(l, r);
            assert(r < INF);
            int ll = -INF;
            int rr = INF;

            ll = max(ll, p[0].x - r);
            rr = min(rr, p[0].x + r);

            ll = max(ll, p[2].x - r);
            rr = min(rr, p[2].x + r);
            
            ll = max(ll, p[1].x - r - h);
            rr = min(rr, p[1].x + r - h);

            ll = max(ll, p[3].x - r - h);
            rr = min(rr, p[3].x + r - h);

            assert(ll <= rr);
            
            vector < pnt > tmp;            
            tmp.pb(pnt(ll, p[0].y)); 
            tmp.pb(pnt(ll + h, p[0].y)); 
            tmp.pb(pnt(ll, p[2].y)); 
            tmp.pb(pnt(ll + h, p[2].y)); 

            //db2(answer, r);
            if (answer > r) {
                answer = r;
                for (int i = 0; i < n; i++)
                    res[p[i].id] = tmp[i];
                if (tt)
                    for (int i = 0; i < n; i++)
                        swap(res[i].x, res[i].y);
            }
        }

        for (int i = 0; i < n; i++)
            swap(p[i].x, p[i].y);
    }

    //db(answer);

    sort(p, p + n, [](pnt A, pnt B) { return A.id < B.id; });
    
    


    for (int mask = 1; mask < (1 << n) - 1; mask++) {
        for (int i = 0; i < n; i++)
            type[i] = ((mask >> i) & 1);
        int x = INF;
        int y = INF;          
        int r = INF;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (type[i] == type[j]) {
                    if (type[i] == 0) {
                        if (p[i].x != p[j].x)
                            r = abs(p[i].x - p[j].x);
                    }
                    else {
                        if (p[i].y != p[j].y)
                            r = abs(p[i].y - p[j].y);
                    }
                }
            }
            for (int i = 0; i < n; i++)
                if (type[i] == 0)
                    x = p[i].x;
                else
                    y = p[i].y;

            if (r == INF) continue;

            for (int dx = 0; dx <= 1; dx++)
                for (int dy = 0; dy <= 1; dy++) {
                    int xx = x + r * dx;
                    int yy = y + r * dy;
                    
                    vector < int > perm;
                    for (int i = 0; i < n; i++)
                        perm.pb(i);
                    for (int it = 0; it < 24; it++) {
                        int mx = 0;   
                        vector < pnt > tmp;
                        tmp.pb(pnt(xx, yy));
                        tmp.pb(pnt(xx - r, yy));
                        tmp.pb(pnt(xx, yy - r));
                        tmp.pb(pnt(xx - r, yy - r));
                        for (int i = 0; i < n; i++)
                            mx = max(mx, dist(tmp[i], p[perm[i]]));

                        //for (int i = 0; i < 4; i++)
                            //rev[perm[i]] = i;
                    
                        if (mx < answer) {
                            answer = mx; 
                            for (int i = 0; i < n; i++)
                                res[perm[i]] = tmp[i];
                        } 

                        next_permutation(perm.begin(), perm.end());
                    }

                     
                }




        }

    }



    if (answer == INF) {
        puts("-1");
    }
    else {
        printf("%d\n", answer);
        for (int i = 0; i < 4; i++)
            printf("%d %d\n", res[i].x, res[i].y);
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
        int k;
        scanf("%d", &k);
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