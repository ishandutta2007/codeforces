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
const int N = 1e5 + 10;
const long long INF = 1e9 + 19;

int n, m;
int a[N];
vector < int > where[N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }
}

void solve() {
    int cur = 0;
    for (int i = 0; i < m; i++) {
        if (cur == 0 || a[cur - 1] != a[i])
            a[cur++] = a[i];
    }
    m = cur;

    long long sum = 0;
    for (int i = 0; i < m - 1; i++)
        sum += abs(a[i] - a[i + 1]); 
    for (int i = 0; i < m; i++)
        where[a[i]].pb(i);
    long long answer = sum;

    for (int t = 0; t < n; t++) {
        if (where[t].empty()) continue;
        //db(t);
        
        vector < int > neighbor;
        for (auto x: where[t])
            for (int shift = -1; shift <= 1; shift += 2) {
                int pos = x + shift;
                if (0 <= pos && pos < m)
                    neighbor.pb(a[pos]);
            }
        sort(neighbor.begin(), neighbor.end());
        int r = neighbor[neighbor.size() / 2];
        long long oldSum = 0;  
        long long newSum = 0; 
        //for (auto x: neighbor)
            //cerr << x << " ";
        //cerr << endl;
        for (auto x: neighbor) {
            oldSum += abs(t - x);
            newSum += abs(r - x);
        }
        assert(newSum <= oldSum);
        //db2(newSum, oldSum);
        answer = min(answer, sum - oldSum + newSum);
    }
    

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