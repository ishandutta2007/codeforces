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
//#include <unordered_set> 
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair 
#define pb push_back
#define y1 botva
#define all(s) s.begin(), s.end() 
void solve();

#define NAME "changemeplease"
int main() {
#ifdef YA 
    //cerr << NAME << endl;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout); 
    clock_t start = clock();
#else 
    //freopen("input.txt", "r", stdin); 
    //freopen("output.txt", "w", stdout); 
#endif 

    int t = 1;
    //cin >> t;  
    for (int i = 1; i <= t; ++i) {
        //cout << "Case #" << i << ": ";
        solve();
    }
#ifdef YA 
    //cout << "\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif 
    return 0;
}

int n, m;
vector < int > c[4];

void printerr() {
    cout << "IMPOSSIBLE\n";
    exit(0);
}

//map <pair <int, int>, int > res;

bool rec(int l, int r) {
    if (l >= r) {
        return true;
    }
    
    /*if (res.find(mp(l, r)) != res.end()) {
        return res[mp(l, r)];
    }*/
    
    if (c[0][l] != -1 && c[1][l] >= r || c[2][l] != -1 && c[3][l] >= r) {
        return 0;
    }

    if (l + 1 == r) {
        return 1;
    }

    if (c[0][l] == -1) {
        return rec(l + 1, r);
    }

    int maxr = c[1][l];

    for (int i = l + 1; i < r && i <= maxr; ++i) {
        maxr = max(maxr, max(c[1][i], c[3][i]));
    }

    if (maxr >= r || c[2][l] != -1 && maxr >= c[2][l]) {
        return 0;
    }

    return rec(l + 1, maxr + 1) && rec(maxr + 1, r);
}

void print(int l, int r) {
    if (l >= r) {
        return ;
    }

    if (l + 1 == r) {
        printf("%d ", l + 1);
        return;
    }

    if (c[0][l] == -1) {
        printf("%d ", l + 1);
        print(l + 1, r);
        return;
    }

    int maxr = c[1][l];

    for (int i = l + 1; i < r && i <= maxr; ++i) {
        maxr = max(maxr, max(c[1][i], c[3][i]));
    }

    print(l + 1, maxr + 1);
    printf("%d ", l + 1);
    print(maxr + 1, r);
}

void solve() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < 4; ++i) {
        c[i].assign(n + 1, -1);
    }

    

    for (int i = 0; i < m; ++i) {

        pair <pair <int, int>, int> tmp;


        //cin >> tmp.first.first >> tmp.first.second;
        scanf("%d %d", &tmp.first.first, &tmp.first.second);
        
        char s;
        scanf(" %c ", &s);
        

        if (s == 'L') {
            tmp.second = 0;
            for (int t = 0; t < 3; ++t) {
                scanf(" %c ", &s);
            }
        }
        else {
            tmp.second = 1;
            for (int t = 0; t < 4; ++t) {
                scanf(" %c ", &s);
            }
        }

        --tmp.first.first;
        --tmp.first.second;
        if (tmp.first.first >= tmp.first.second) {
            printerr();
        }

        if (c[2 * tmp.second][tmp.first.first] == -1 || c[2 * tmp.second][tmp.first.first] > tmp.first.second) {
            c[2 * tmp.second][tmp.first.first] = tmp.first.second;
        }
        if (c[2 * tmp.second + 1][tmp.first.first] == -1 || c[2 * tmp.second + 1][tmp.first.first] < tmp.first.second) {
            c[2 * tmp.second + 1][tmp.first.first] = tmp.first.second;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (c[0][i] == -1 || c[2][i] == -1) {
            continue;
        }
        if (c[1][i] >= c[2][i]) {
            printerr();
        }
    }

    if (!rec(0, n)) {
        printerr();
    }

    print(0, n);
}