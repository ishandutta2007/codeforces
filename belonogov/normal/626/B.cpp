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
const int N = -1;
const long long INF = 1e9 + 19;

int n;
string s;
vector < pair < int, int > > cnt;
bool can[3];

void read() {
    scanf("%d", &n);
    cin >> s;
    cnt.resize(3);
    for (int i = 0; i < 3; i++)
        cnt[i].sc = i;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B')
            cnt[0].fr++;
        else if (s[i] == 'G')
            cnt[1].fr++;
        else if (s[i] == 'R')
            cnt[2].fr++;
        else
            assert(false);
    }

}



void solve() {
    sort(cnt.begin(), cnt.end());
    reverse(cnt.begin(), cnt.end());
    if (cnt[1].fr == 0) {
        can[cnt[0].sc] = 1;
        return;
    }
    if (cnt[2].fr > 0) {
        for (int i = 0; i < 3; i++)
            can[i] = 1;
        return;
    }
    //for (int i = 0; i < 3; i++)
        //db2(cnt[i].fr, cnt[i].sc);

    if (cnt[1].fr == 1) {
        for (int i = 0; i < 3; i++)
            can[i] = 1;
        can[cnt[0].sc] = 0;
        if (cnt[0].fr == 1) {
            can[cnt[1].sc] = 0;
        }
        return; 
    }
    assert(cnt[0].fr >= 2 && cnt[1].fr >= 2);
    for (int i = 0; i < 3; i++)
        can[i] = 1;
}

void printAns() {
    if (can[0]) printf("B");
    if (can[1]) printf("G");
    if (can[2]) printf("R");
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