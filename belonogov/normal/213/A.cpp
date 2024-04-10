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
const int N = 222;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;


int n;
int c[N];
vector<int> e[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        c[i]--;
    }
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int v;
            scanf("%d", &v); v--;
            e[i].pb(v);
        }
    }
}

void solve() {
    int answer = INF;
    for (int st = 0; st < 3; st++) {
        int cntDone = 0;
        int res = 0;
        vector<int> done(n);
        int curD = st;
        for (;; ) {
            for(;;) {
                bool flag = 0;
                for (int i = 0; i < n; i++) {
                    if (c[i] == curD && done[i] == 0) {
                        bool ff = 1;
                        for (auto v: e[i])
                            ff &= done[v];
                        if (ff) {
                            done[i] = 1;
                            flag = 1;
                            cntDone++;
                        }
                    }
                }
                if (!flag)
                    break;
            }
            curD = (curD + 1) % 3;
            if (cntDone == n) 
                break;
            res++;
        }
        res += n;
        answer = min(res, answer);

    }
    cout << answer << endl;
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