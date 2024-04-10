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
const int N = 1e6 + 10;
const long long INF = 1e9 + 19;

int n, p;
pair < int, int > a[N];
map < pair < int, int >, int > q;
int cnt[N];

void read() {
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].fr, &a[i].sc); a[i].fr--; a[i].sc--;
        if (a[i].fr > a[i].sc) swap(a[i].fr, a[i].sc);
    }
}

void solve() {
    long long answer = 0; 
    for (int i = 0; i < n; i++) {
        cnt[a[i].fr]++;
        cnt[a[i].sc]++;
    }
    for (int i = 0; i < n; i++)
        q[a[i]]++;
    
    sort(cnt, cnt + n);
    reverse(cnt, cnt + n);

    int cur = n - 1;
    for (int i = 0; i < n; i++) {
        for (; cur >= 0 && cnt[i] + cnt[cur] < p; cur--);
        if (cur <= i) break;
        answer += cur - i;
    }

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        cnt[a[i].fr]++;
        cnt[a[i].sc]++;
    }
    for (auto x: q) {
        int v = x.fr.fr;
        int u = x.fr.sc;
        int c = x.sc;
        if (cnt[v] + cnt[u] >= p)
            answer--;
        if (cnt[v] + cnt[u] - c >= p)
            answer++;
    }
    


    cout << answer << endl;

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