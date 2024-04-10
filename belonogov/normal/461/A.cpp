#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>


using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back

#define epr(...) fprintf(stderr, __VA_ARGS__)
const int N = 1e6 + 10;
const int INF = 1e9;


int a[N];
long long p[N];
int n;
long long sum;

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void solve() {
    sort(a, a + n, greater < int > ());
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];
    sum = 0;
    //for (int i = 0; i <= n; i++)
        //cerr << p[i] << " ";
    //cerr << endl;
    for (int i = 0; i < n; i++)
        sum += p[i + 1];
    //cerr << sum << endl;
    sum += p[n];
    sum -= a[0];
}

void printAns() {
    printf("%lld\n", sum);
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