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

int n, k;
char s[N];
vector < int > b;

void read() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);

}

int f(int ll, int rr, int pos) {
    assert(ll <= pos && pos <= rr);
    return max(b[pos] - b[ll], b[rr] - b[pos]);
}

void solve() {
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            b.pb(i);
    int answer = INF;
    k++;
    for (int i = 0; i + k <= (int)b.size(); i++) {
        int l = i;  
        int r = i + k - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (b[mid] - b[i] < b[i + k - 1] - b[mid])
                l = mid;
            else
                r = mid;
        }
        answer = min(answer, min(f(i, i + k - 1, l), f(i, i + k - 1, r)));
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