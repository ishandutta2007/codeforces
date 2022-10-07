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

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = 1e6 + 10;
const int INF = 1e9;


int n;
pair < int, int > b[N];
set < int > q;
map < int, int > w; 
vector < int > c; // pos val
vector < pair < int, int > > d;
int data[N];
long long ans = 0;


void read() {
    scanf("%d", &n); 
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &b[i].fr, &b[i].sc);
        q.insert(b[i].fr);
        q.insert(b[i].sc); 
    }
}

void merge(int l, int r) {
    if (r - l <= 1) return;
    merge(l, (l + r) / 2);
    merge((l + r) / 2, r);
    int curL = l;
    int curR = (l + r) / 2;
    for (int i = l; i < r; i++) {
        if (curR == r || (curL < (l + r) / 2 && c[curL] < c[curR])) {
            data[i] = c[curL];
            curL++;
        }
        else {
            ans += ((l + r) / 2 - curL);
            data[i] = c[curR];
            curR++;
        }
    }
    for (int i = l; i < r; i++)
        c[i] = data[i];
}

void solve() {
    for (auto x: q) {
        w[x] = x;
    }
    for (int i = 0; i < n; i++) {
        int p1 = w[b[i].fr];
        int p2 = w[b[i].sc];
        w[b[i].fr] = p2;
        w[b[i].sc] = p1;
    }
    for (auto pr: w)
        c.pb(pr.sc); 
    merge(0, c.size());

    for (auto pr: w)
        d.pb(pr);

    map < int, int > valPos; 
    for (int i = 0; i < (int)c.size(); i++)
        valPos[d[i].fr] = i;
    
    for (int i = 0; i < (int)c.size(); i++) {
        int pos = d[i].fr;
        int val = d[i].sc;
        if (val > pos) {
            int left = valPos[val] - i;
            assert(left >= 1);
            ans += val - pos - left;
        }
        if (val < pos) {
            int left = i - valPos[val]; 
            assert(left >= 1);
            ans += pos - val - left;
        }
    }
    cout << ans << endl;

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