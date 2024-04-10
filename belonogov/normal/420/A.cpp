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

string s;

void read() {
    cin >> s;
    int n = s.length();
    bool flag = 1;
    for (int i = 0; i < n; i++) {
        int pos = n - 1 - i;
        if (s[i] == 'A') flag &= s[pos] == 'A';
        else if (s[i] == 'H') flag &= s[pos] == 'H';
        else if (s[i] == 'I') flag &= s[pos] == 'I';
        else if (s[i] == 'M') flag &= s[pos] == 'M';
        else if (s[i] == 'O') flag &= s[pos] == 'O';
        else if (s[i] == 'T') flag &= s[pos] == 'T';
        else if (s[i] == 'U') flag &= s[pos] == 'U';
        else if (s[i] == 'V') flag &= s[pos] == 'V';
        else if (s[i] == 'W') flag &= s[pos] == 'W';
        else if (s[i] == 'X') flag &= s[pos] == 'X';
        else if (s[i] == 'Y') flag &= s[pos] == 'Y';
        else
            flag = 0;
    }
    if (flag)
        puts("YES");
    else
        puts("NO");
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