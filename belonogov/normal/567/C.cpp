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

#define equal equalll
#define less lesss
const int N = 1e6;
const int INF = 1e9 + 19;

int n;
long long k;
int a[N];
int l[N];
int r[N];



void read() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    map < long long, int > q;
    for (int i = 0; i < n; i++) {
        if (a[i] % k == 0) {
            l[i] = q[a[i] / k];
        }  
        q[a[i]]++; 
    }
    q.clear();
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] % k == 0) {
            r[i] = q[a[i] * 1ll * k];
        }
        q[a[i]]++;
    }
    long long answer = 0;
    for (int i = 0; i < n; i++)
        answer += l[i] * 1ll * r[i];
    cout << answer << endl;
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