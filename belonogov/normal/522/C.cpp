#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define getTime() cerr << (clock() * 1.0 / CLOCKS_PER_SEC) << endl
#define equal equalll
#define less lesss
const int N = 1e6 + 100;
const int INF = 1e9;

int m, k;
int t[N];
int r[N];
vector < int > a;


void read() {
    scanf("%d%d", &m, &k);
    a.assign(k, 0);
    for (int i = 0; i < k; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m - 1; i++)
        scanf("%d%d", &t[i], &r[i]);    
}

void solve() {
    int D = -1;    
    for (int i = 0; i < m - 1; i++)
        t[i]--;
    for (int i = 0; i < m - 1; i++)
        if (r[i] == 1) {
            D = i;
            break;
        }
    auto b = a;
    int cntRejD = 0;
    for (int i = 0; i < D; i++) {
        if (t[i] != -1)
            b[t[i]]--; 
        else
            cntRejD++;
    }
    auto c = a;
    int cntRejM = 0;
    for (int i = 0; i < m - 1; i++) {
        if (t[i] != -1)
            c[t[i]]--;
        else
            cntRejM++;
    }
    if (D == -1) {
        for (int i = 0; i < k; i++)
            if (cntRejM >= c[i])
                printf("Y");
            else
                printf("N");
        return;
    }
    vector < char > use(k);
    for (int i = D; i < m - 1; i++) {
        if (t[i] != -1) {
            use[t[i]] = 1;
        } 
    } 
    int best = -1;
    for (int i = 0; i < k; i++) {
        if (use[i]) continue;
        if (best == -1 || b[i] < b[best])
            best = i;
    }
    assert(best != -1);
    for (int i = 0; i < k; i++) {
        if (!use[i] && b[i] <= cntRejD)
            printf("Y");
        else {
            if (c[i] <= cntRejM - b[best])
                printf("Y");
            else
                printf("N");
        }
    }
}

void printAns() {

}

void genTest() {
    //k = 5;
    //m = 5;
    //int sum = m + 2; 
    //for (int i = 0; i < k; i++) {

    //}
}

void stress() {
    for (int t = 0; t < 10; t++) {
        cerr << "test id: " << t << endl;
        genTest();
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        int t;
        scanf("%d", &t);
        for (int i = 0; i < t; i++) {
            read();
            solve();
            printAns();
            printf("\n");
        }
    }
    else {
        stress();
    }

    return 0;
}