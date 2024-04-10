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
const int N = 3333;
const long long INF = 1e9 + 19;


vector < int > zfun(string s) {
    vector < int > z(s.size()); 
    int l = 0, r = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (r > i) 
            z[i] = min(z[i - l], r - i);
        for (; i + z[i] < n && s[i + z[i]] == s[z[i]]; z[i]++);
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

string s, t;
int data[N * 2][N];


void read() {
    cin >> s >> t; 
    vector < pair < int, int > > answer;  

    string sr = s;
    reverse(sr.begin(), sr.end());
    int n = s.size();
    int m = t.size();
    for (int i = 0; i < n; i++) {
        auto g = zfun(s.substr(i, n - i) + '#' + t); 
        for (int j = 0; j < m; j++)
            data[i][j] = g[n - i + 1 + j];           
        g = zfun(sr.substr(i, n - i) + '#' + t); 
        for (int j = 0; j < m; j++)
            data[i + n][j] = g[n - i + 1 + j];           
    }
    //for (int i = 0; i < n * 2; i++, cerr << endl)
        //for (int j = 0; j < m; j++)
            //cerr << data[i][j] << " ";
    int cur = 0;
    for (; cur < (int)t.size();) {
        int step = 0;
        int where = -1;
        for (int i = 0; i < n * 2; i++) {
            if (data[i][cur] > step) {
                step = data[i][cur];
                where = i;
            }
        }
        if (step > 0) {
            int l = where % n;
            int r = l + step - 1; 
            if (where >= n) {
                //swap(l, r);
                l = n - 1 - l;
                r = n - 1 - r;
            }
            answer.pb(mp(l, r));
            cur += step;
        }
        else {
            puts("-1");
            return;
        }

    }
    

    printf("%d\n", (int)answer.size());
    for (auto x: answer)
        printf("%d %d\n", x.fr + 1, x.sc + 1);
}

void solve() {

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