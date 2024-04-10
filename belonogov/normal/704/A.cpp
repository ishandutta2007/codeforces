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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n, q;
int c[N];
int lastT[N];
vector < int > st; 

void read() {
    scanf("%d%d", &n, &q);
    int answer = 0;
    int cur = 0;
    memset(lastT, -1, sizeof(lastT));
    for (int i = 0; i < q; i++)  {
        int type, val;
        scanf("%d%d", &type, &val);
        if (type == 1) {
            st.pb(val);
            c[val]++;
            answer++;
        }
        if (type == 2) {
            answer -= c[val];
            c[val] = 0;
            lastT[val] = st.size();
        }
        if (type == 3) {
            for (; cur < val; cur++)  {
                int id = st[cur];
                //db2(cur, lastT[id]);
                if (cur >= lastT[id]) {
                    c[id]--;
                    answer--;
                }
            }

        }
        printf("%d\n", answer);
    }

}

void solve() {

}

void stress() {

}


int main(){
#ifdef MY_DEBUG
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