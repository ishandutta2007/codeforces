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


int n;
pair < int, int > a[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].fr, &a[i].sc);

}

void solve() {
    long long answer = 0;
    for (int tt = 0; tt < 2; tt++) {
        sort(a, a + n);
        for (int i = 0; i < n; ) {
            int j = i;
            for (; i < n && a[i].fr == a[j].fr; i++);
            int t = i - j; 
            answer += t * 1ll * (t - 1) / 2;
        }
        for (int i = 0; i < n; i++)
            swap(a[i].fr, a[i].sc);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ) {
        int j = i;
        for (; i < n && a[i] == a[j]; i++);
        int t = i - j; 
        answer -= t * 1ll * (t - 1) / 2;
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