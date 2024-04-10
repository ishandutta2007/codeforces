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

int n, t;
char s[N];
int mxH = 0; 
int cntS = 0;

void read() {
    scanf("%d%d", &n, &t);
    scanf("%s", s);
}

bool check(int k) {
    int pos = -1;
    int house = 0;
    for (int i = 0; i < n; i++)
        house += s[i] == 'H';

    if (cntS + k < house) return 0;

    int need = house - k;
    if (need < 0) return 1;
    for (int i = 0; need > 0; i++) {
        assert(i < n);
        if (s[i] == 'S') {
            need--;
            if (need == 0)
                pos = i;
        }
    }
    //db2(need, pos);

    int target = max(mxH, pos);
    if (t < target) return 0;
    
    int energy = t;
    int sum = k;
    
    int deb = -1;
    int cntDeb = 0;
    energy++;
    for (int i = 0; i <= target; i++) {
        energy--;
        if (energy < 0) return 0;
        //cerr << "i sum cntDeb: " << i << " " << sum << " " << cntDeb << endl;
        if (s[i] == 'H') {
            if (sum > 0) {
                sum--;
            }
            else {
                if (deb == -1) {
                    deb = i;
                    //cerr << "energy target i: " << energy << " " << target << " " << i << endl;
                    if (energy >= (target - i) * 2)
                        return 1;
                }
                cntDeb++;
            }
        }
        if (s[i] == 'S') {
            sum++;
            if (deb != -1 && cntDeb <= sum) {
                sum -= cntDeb;
                energy -= (i - deb) * 2;
                cntDeb = 0;
                deb = -1;
            }
        }
    }
    //db2(sum, cntDeb);
    return energy >= 0;
}

void solve() {
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') 
            mxH = i;
        cntS += s[i] == 'S';
    }
    t--;
    if (mxH > t) {
        puts("-1");
        return;
    }
    //db(check(3));
    //return;

    int l = -1;
    int r = n;
    while (r - l > 1) {
        if (check((l + r) / 2))
            r = (l + r) / 2;
        else
            l = (l + r) / 2;
    }
    printf("%d\n", r);

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