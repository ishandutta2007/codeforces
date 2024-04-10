#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define pr(x) { cerr << #x << " = " << x << endl; }
const int N = 1e5 + 10;
const int INF = 1e9;

int n, k;
pair < int, int > a[N];

void read() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i].fr);
        a[i].sc = i;
    }
}

void solve() {
    sort(a, a + n);
    vector < int > ans;
    for (int i = 0; i < n && k >= a[i].fr; i++) {
        ans.pb(a[i].sc);
        k -= a[i].fr;
    }
    printf("%d\n", (int)ans.size());
    for (auto x: ans)
        printf("%d ", x + 1);
    printf("\n");
}

void printAns() {

}

void stress() {

}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
#endif
    if (1) {
        while (true) {
            read();
            solve();
            printAns();
            return 0;
        }
    }
    else {
        stress();
    }

    return 0;
}