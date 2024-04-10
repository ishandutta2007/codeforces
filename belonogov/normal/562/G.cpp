#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define fr first
#define sc second
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";

const int N = 1e6;
const int INF = 1e9 + 19;

struct Event {
    int a, b, c;
    int id;
    bool flag;
    void read() {
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
        c--;
    }
};


int n;
Event data[N];
int cnt[N];
int cur;


void read() {
    scanf("%d", &n);
    for (int i = 0; i < 4 * n; i++) {
        data[i].read();
        data[i].id = i;
        data[i].flag = 0;
    }
}

void solve() {

    //for (;;) {

    for (int i = 0; i < n; i++)
        cnt[i] = 4;

    cur = n * 4;
    vector < int > answer;
    for (;cur > 0;) {
        //db(cur);
        for (int i = 0; i < cur; i++) {
            int cntB = cnt[data[i].b];
            int cntC = cnt[data[i].c];
            cntB++;
            cntC++;
            cntB -= data[i].a == data[i].b;
            cntC -= data[i].a == data[i].c;

            cntB += data[i].b == data[i].c; 
            cntC += data[i].b == data[i].c; 
            if (cntB <= 9 && cntC <= 9) {
                data[i].flag = 1;
                cnt[data[i].a]--;
                cnt[data[i].b]++;
                cnt[data[i].c]++;
                answer.pb(data[i].id);
            }
        }
        int ncur = 0;
        for (int i = 0; i < cur; i++)
            if (data[i].flag == 0)
                data[ncur++] = data[i];
        assert(ncur < cur);
        cur = ncur;
        random_shuffle(data, data + cur);
    }

    printf("YES\n");
    for (auto x: answer)
        printf("%d ", x + 1);
    printf("\n");
    //}

}

void stress() {

}


int main() {
#ifdef DEBUG
    freopen("in", "r", stdin);
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