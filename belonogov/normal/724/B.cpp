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
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)a.size()

#define equal equalll
#define less lesss
const int N = 22;
const long long INF = 1e9 + 19;
typedef long long ll;

int n, m;
int a[N][N];

void read() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }

}

bool checkUp(vector<int> a) {
    for (int i = 0; i < (int)a.size(); i++)
        if (a[i] != i) return 0;
    return 1;
}

void solve() {
    for (int x = 0; x < m; x++)
        for (int y = x; y < m; y++) {
            //x = 1;
            //y = 2;
            bool flag = 1;
            for (int i = 0; i < n; i++) {
                bool inner = 0;
                vector<int> tmp;
                for (int j = 0; j < m; j++)
                    tmp.pb(a[i][j]);
                swap(tmp[x], tmp[y]);
                int cnt = 0;
                for (int j = 0; j < m; j++)
                    cnt += tmp[j] != j;
                assert(cnt != 1);
                if (cnt == 2 || cnt == 0) 
                    inner = 1;

                for (int t1 = 0; t1 < m && !inner; t1++)
                    for (int t2 = t1 + 1; t2 < m; t2++)  {
                        tmp.clear();
                        for (int j = 0; j < m; j++)
                            tmp.pb(a[i][j]);
                        swap(tmp[t1], tmp[t2]);
                        swap(tmp[x], tmp[y]);  
                        if (checkUp(tmp))
                            inner = 1;
                    }
                //db(inner);
                flag &= inner;
            }

            if (flag) {
                puts("YES");
                return;
            }
            //exit(0);
        }


    puts("NO");
}

void stress() {

}

int main(){
#ifdef MY_DEBUG
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