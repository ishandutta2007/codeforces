#pragma comment (linker, "/STACK:128000000")
#include <iostream> 
#include <cstdio> 
#include <fstream>
#include <functional>
#include <set> 
#include <map> 
#include <vector> 
#include <queue> 
#include <stack> 
#include <cmath> 
#include <algorithm> 
#include <cstring> 
#include <bitset> 
#include <ctime> 
#include <sstream>
#include <stack> 
#include <cassert> 
#include <list> 
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

//int timer = 0;
#define FILENAME ""

int main() {
    string s = FILENAME;
#ifdef YA
    //assert(!s.empty());
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //cerr<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout); 
    cin.tie(0);
#endif
    cout.sync_with_stdio(0);
    cout.precision(10);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--) {
        //++timer;
        solve();
    }
#ifdef YA
    cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
    return 0;
}

const int inf = 2000000000;

int n, m, k, q;

const int treesz = 131072;
int rmq[2 * treesz + 100];

int getmax(int l, int r, int i, int L, int R) {
    if (l >= R || L >= r) {
        return -inf;
    }
    if (l <= L && R <= r) {
        return rmq[i];
    }
    int m = (L + R) / 2;
    return max(getmax(l, r, 2 * i, L, m), getmax(l, r, 2 * i + 1, m, R));
}

void init() {
    for (int i = 0; i <= 2 * treesz; ++i) {
        rmq[i] = inf;
    }
}

void upd(int pos, int val) {
    int j = pos + treesz;
    rmq[j] = val;

    while (j > 1) {
        j /= 2;
        rmq[j] = max(rmq[2 * j], rmq[2 * j + 1]);   
    }

}


struct query {
    pi x;
    pi y;
    int id;
    query(){}
};

bool compqx(const query& a, const query& b) {
    return a.y.first < b.y.first;   
}

bool compqy(const query& a, const query& b) {
    return a.x.first < b.x.first;   
}

bool compx(const pi& a, const pi& b) {
    return a.first < b.first;
}

bool compy(const pi& a, const pi& b) {
    return a.second < b.second;
}

vector <query> qs;
vector <int> anses;

void print() {
    for (int x: anses) {
        if (x == 0) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}

void solve() {
    cin >> n >> m >> k >> q;
    
    vector <pi> a(k);

    for (int i = 0; i < k; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    
    qs.resize(q);
    anses.resize(q, 0);
    for (int i = 0; i < q; ++i) {
        cin >> qs[i].x.first >> qs[i].y.first >> qs[i].x.second >> qs[i].y.second;
        qs[i].id = i;
    }

    //X
    
    sort(a.begin(), a.end(), compy);
    init();
    sort(qs.begin(), qs.end(), compqx);

    int pa = a.size() - 1;
    int pq = qs.size() - 1;

    for (int cury = m; cury >= 1; --cury) {
        while (pa >= 0 && a[pa].second == cury) {
            upd(a[pa].first, cury);
            --pa;
        }
        while (pq >= 0 && qs[pq].y.first == cury) {
            int tmp = getmax(qs[pq].x.first, qs[pq].x.second + 1, 1, 0, treesz);
            if (tmp <= qs[pq].y.second) {
                anses[qs[pq].id] = 1;
            }
            --pq;
        }
    }


    //Y
    sort(a.begin(), a.end(), compx);
    init();
    sort(qs.begin(), qs.end(), compqy);

    pa = a.size() - 1;
    pq = qs.size() - 1;

    for (int curx = n; curx >= 1; --curx) {
        while (pa >= 0 && a[pa].first == curx) {
            upd(a[pa].second, curx);
            --pa;
        }
        while (pq >= 0 && qs[pq].x.first == curx) {
            int tmp = getmax(qs[pq].y.first, qs[pq].y.second + 1, 1, 0, treesz);
            if (tmp <= qs[pq].x.second) {
                anses[qs[pq].id] = 1;
            }
            --pq;
        }
    }


    print();
}