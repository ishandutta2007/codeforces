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

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; 
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()
#define pw(n) (1ll << (n))

#define equal equalll
#define less lesss
const int N = 3333;
const long long INF = 1e9 + 19;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int n, m;
int a[N];
int aa[N];
int c[N];
char ans[N][N];
bool use[N];

void read() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        aa[i] = a[i];
}

void solve() {
    int Z = 0;
    for (int i = 0; i < n; i++) {
        Z += a[i];
    }
    if (m - n > 0) {
        int sum = m * (m - 1) - Z;
        int t = sum / (m - n);
        int rem = sum % (m - n);
        for (int i = n; i < m; i++) {
            a[i] = t;
            if (i - n < rem)
                a[i]++;
        }

    }
    //for (int t = 0; t < m; t++)
        //cerr << a[t] << " ";
    //cerr << endl;

    for (int i = 0; i < m; i++) {
        a[i] -= (m - 1);
    }
    int ss = 0;
    for (int i = 0; i < m; i++)
        ss += a[i];
    //db(ss);



    for (int i = 0; i < m; i++) {
        //cerr << endl;
        //for (int t = 0; t < m; t++)
            //cerr << a[t] << " ";
        //cerr << endl;
        //for (int t = 0; t < m; t++)
            //cerr << use[t] << " ";
        //cerr << endl;

        int mx = -1;
        for (int j = 0; j < m; j++) 
            if (!use[j] && (mx == -1 || abs(a[j]) > abs(a[mx]))) {
                mx = j;
            }
        assert(mx != -1);
        vector<pair<int,int>> other;
        for (int j = 0; j < m; j++) {
            if (!use[j] && j != mx)
                other.pb(mp(a[j], j));
        }
        sort(all(other));

         
        for (int j = 0; j < (int)other.size(); j++) {
            if (((int)other.size() - j - 1) + (a[mx] - 1) >= 0) {
                a[mx]--;
                a[other[j].S]++;
                ans[mx][other[j].S] = 'W';
                ans[other[j].S][mx] = 'L';
            }
            else if (((int)other.size() - j - 1) + a[mx] >= 0) {
                ans[mx][other[j].S] = 'D';
                ans[other[j].S][mx] = 'D';

            }
            else {
                a[mx]++;
                a[other[j].S]--;
                ans[mx][other[j].S] = 'L';
                ans[other[j].S][mx] = 'W';
            }
        }
        use[mx] = 1;
    }

    for (int i = 0; i < m; i++) 
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == 'W')
                c[i] += 2;
            if (ans[i][j] == 'D')
                c[i] += 1;
        }
    for (int i = 0; i < m; i++)
        ans[i][i] = 'X';
    sort(c, c + m);
    reverse(c, c + m);
    //for (int i = 0; i < m; i++)
        //printf("%s\n", ans[i]);

    //for (int i = 0; i < n; i++)
        //db2(c[i], aa[i]);

    bool ok = 1;
    for (int i = 0; i < n; i++)
        ok &= c[i] == aa[i];

    if (ok) {
        puts("yes");
        for (int i = 0; i < m; i++)
            printf("%s\n", ans[i]);
    }
    else {
        puts("no");
    }



}

void stress() {

}

int main(){
#ifdef HOME 
    freopen("in", "r", stdin);
#endif
    if (1) {
        read();
        solve();
    }
    else {
        stress();
    }

    return 0;
}