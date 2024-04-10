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
#define left lefttt
#define right righttt
const int N = 5e5 + 10;
const long long INF = 1e9 + 19;
const int MOD = 1e9 + 7;

int n, h, w;
char s[N];

void read() {
    scanf("%d%d%d", &n, &h, &w);
    scanf("%s", s);
}

int left;
int right;
int up;
int down;

bool isOk() {
    return left < right && up < down;
}




void upd(long long & a, long long b) {
    a = (a + b) % MOD;
}

void solve() {
    long long answer = 0;
    right = w;
    down = h;
    for (int i = 0; i < n; i++) {
        if (!isOk()) break;
        //db2(i, n);

        if (s[i] == 'U') {
            up--;
            down--;
            if (up == -1) {
                up = 0;
                upd(answer, (right - left) * 1ll * i);
            }
        }
        if (s[i] == 'D') {
            up++;
            down++;
            if (down == h + 1) {
                down = h;
                upd(answer, (right - left) * 1ll * i);
            } 
        }
        if (s[i] == 'L') {
            left--;
            right--;
            if (left == -1) {
                left = 0;
                upd(answer, (down - up) * 1ll * i);
            }
        }
        if (s[i] == 'R') {
            left++;
            right++;
            if (right == w + 1) {
                right = w;
                upd(answer, (down - up) * 1ll * i);
            }
        }
    }
    //db("after");
    //db(answer);
    if (isOk()) {
        vector < pair < int, int > > event;  // time type;
        int _left = left;
        int _right = right;
        int _up = up;
        int _down = down;

        for (int i = 0; i < n; i++) {

            if (s[i] == 'U') {
                up--;
                down--;
                if (up == -1) {
                    up = 0;
                    event.pb(mp(i, 0));
                }
            }
            if (s[i] == 'D') {
                up++;
                down++;
                if (down == h + 1) {
                    down = h;
                    event.pb(mp(i, 1));
                } 
            }
            if (s[i] == 'L') {
                left--;
                right--;
                if (left == -1) {
                    left = 0;
                    event.pb(mp(i, 2));
                }
            }
            if (s[i] == 'R') {
                left++;
                right++;
                if (right == w + 1) {
                    right = w;
                    event.pb(mp(i, 3));
                }
            }            
        } 
        //db(event.size());
        if (event.empty()) {
            puts("-1");
            return;
        }
        left = _left;
        right = _right;
        up = _up;
        down = _down;

        long long len = n;
        for (;isOk(); ) {
            //db("here");
            
            for (int i = 0; i < (int)event.size() && isOk(); i++) {
                if (event[i].sc <= 1) {
                    up++;
                    upd(answer, (right - left) * 1ll * (len + event[i].fr));
                } 
                else {
                    left++;
                    upd(answer, (down - up) * 1ll * (len + event[i].fr));
                }
            }
            len = (len + n) % MOD;
        }
    } 
    upd(answer, w * 1ll * h);
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