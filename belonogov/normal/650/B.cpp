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

int n, a, b, t;
char s[N];
int need[N];
int sum[N];

void read() {
    scanf("%d%d%d%d", &n, &a, &b, &t);
    scanf("%s", s);
}

void solve() {
    int answer = 0;
    for (int tt = 0; tt < 2; tt++) {
        int T = t;
        for (int i = 0; i < n; i++)
            need[i] = s[i] == 'w';        
        T--;
        if (need[0]) T -= b; 
        if (T < 0) continue;
        
        for (int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + a + 1 + need[i] * b;
        }
         
        for (int j = 0; j < n; j++) {
            int pos = upper_bound(sum, sum + n, T - a * j) - sum - 1;
            if (pos == -1)
                pos = 0;
            assert(pos >= 0);
            answer = max(1 + pos + j, answer);
            T -= a;            
            T--;
            T -= need[n - 1 - j] * b;
            if (T < 0) 
                break;
        } 
        reverse(s + 1, s + n);
    }

    printf("%d\n", min(n, answer));
    


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