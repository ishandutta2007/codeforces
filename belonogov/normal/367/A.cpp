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

string s;
int a[N];
int pref[3][N];

void read() {
    int n;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            pref[j][i + 1] = pref[j][i];
        //db(s[i] - 'x');
        pref[s[i] - 'x'][i + 1]++;
    }
    //for (int j = 0; j < 3; j++, cerr << endl)
        //for (int i = 0; i < n; i++)
            //cerr << pref[j][i] << " ";
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int l, r;
        scanf("%d%d", &l, &r); l--;
        vector < int > tmp;
        for (int j = 0; j < 3; j++) {
            tmp.pb(pref[j][r] - pref[j][l]);
        }
        sort(tmp.begin(), tmp.end());
        //db(tmp.size());
        //db(tmp[0]);
        //db(tmp[1]);
        //db(tmp[2]);
        if (tmp[0] + 1 >= tmp[2] || r - l <= 2)
            puts("YES");
        else
            puts("NO");
    }
    //for (int j = 0; j < 3; j++, cerr << endl)
        //for (int i = 0; i < n; i++)
            //cerr << pref[j][i] << " ";
    
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