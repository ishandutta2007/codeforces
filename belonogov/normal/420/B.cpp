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
const int N = 1e6;
const long long INF = 1e9 + 19;

struct event {
    int t, id;
    int type;
    event(int t, int id, int type): t(t), id(id), type(type) { }
};

int n, m;
vector < event > e;
int use[N];
int use2[N];

bool cmpT(event a, event b) {
    return a.t < b.t;
}

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        char ch;
        int v;
        scanf(" %c %d", &ch, &v); v--;
        assert(ch == '+' || ch == '-');
        e.pb(event(i, v, (ch == '+')? 1: -1));
    } 
     

    


}

void solve() {
    vector < int > answer;
    for (int i = 0; i < m; i++) {
        use[e[i].id] = 1;
    }
    for (int i = 0; i < n; i++)
        if (!use[i]) {
            answer.pb(i);
        }
    memset(use, 0, sizeof(use));
    for (int i = 0; i < m; i++) {
        if (use[e[i].id] == 0) {
            use[e[i].id] = (e[i].type == 1)? 2: 1;
        }
    }
    for (int i = 0; i < n; i++)
        use2[i] = use[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += use[i] == 1;
    }
    if (m > 0) {
        int last = -1;
        if (cnt == 0) {
            last = e[0].id;
        }
        else {
            last = -1;
            for (int i = 0; i < m; i++) {
                cnt += e[i].type;
                if (e[i].type == -1) {
                    if (cnt == 0) {
                        last = (use2[e[i].id] == 1)? e[i].id: -2;
                    }
                    use[e[i].id] = 2;
                }
            }
        }
        cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += use2[i] == 1;

        if (last >= 0) {
            for (int i = 0; i < m; i++) {
                if (cnt == 0) {
                    assert(e[i].type == 1);
                    if (last != e[i].id)
                        last = -2;
                }
                cnt += e[i].type;
                if (cnt == 0) {
                    assert(e[i].type == -1);
                    if (last != e[i].id)
                        last = -2;
                }
                if (e[i].id == last && e[i].type == -1 && cnt > 0)
                    last = -2;
            }
            if (last >= 0) 
                answer.pb(last);
        }
        else
            for (int i = 0; i < n; i++)
                if (use[i] == 1)
                    answer.pb(i);

        //db(last);
    }

    sort(answer.begin(), answer.end());
    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d ", x + 1);
    puts("");


}

void stress() {

}


int main(){
#ifdef DEBUG
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