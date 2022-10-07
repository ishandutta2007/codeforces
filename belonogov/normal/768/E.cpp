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
const int N = -1;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;





map<pair<int,set<int>>, int> q;

int calc(int x, set<int> proh) {
    if (q.count(mp(x, proh)) == 0) {
        vector<int> a(x + 1);
        for (int i = 1; i <= x; i++) {
            if (proh.count(i) == 0) {
                auto p2 = proh;
                p2.insert(i);
                a[calc(x - i, p2)] = 1;
            } 
        }
        int cur = 0;
        for (; a[cur];)  {
            cur++;
            assert(cur < (int)a.size());
        }
        q[mp(x, proh)] = cur;
    }
    return q[mp(x, proh)];
}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    //int G = 60;
    vector<int> f =  {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};

    /*for (int i = 0; i <= G; i++) {
        db(i);
        f[i] = calc(i, set<int>());
    }     
    cerr << "{";
    for (int i = 0; i <= G; i++) {
        cerr << f[i];
        if (i != G) {
            cerr << ", ";
        }
    }
    cerr << "}";


    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;*/
    
    //db(f.size());
    int n;
    scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        res ^= f[x];
    }
    if (res == 0)
        puts("YES");
    else
        puts("NO");
    return 0;
}