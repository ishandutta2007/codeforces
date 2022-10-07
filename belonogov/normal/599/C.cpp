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

int n;
int a[N];
int mx[N];
int mn[N];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    mx[0] = a[0];
    for (int i = 1; i < n; i++)
        mx[i] = max(mx[i - 1], a[i]);
    mn[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        mn[i] = min(mn[i + 1], a[i]);
    sort(a, a + n);
    int cnt = 1;
    for (int i = 0; i < n - 1; i++) {       
        if (mx[i] == a[i] && mn[i + 1] >= a[i]) cnt++;
    }   
    cout << cnt << endl;


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
        int k = 1;
        for (int tt = 0; tt < k; tt++) {
            read();
            solve();
            printAns();
        }
    }
    else {
        stress();
    }

    return 0;
}