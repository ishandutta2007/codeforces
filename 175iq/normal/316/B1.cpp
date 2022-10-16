#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 1005;

int p[N], to[N], n, x, cnt, pos, save;
bool ok, may[N];
vector<int> dif;

void dfs(int v) {
    cnt++;
    pos++;
    if (v == x) {
        ok = 1;
        save = pos;
    }
    if (to[v])
        dfs(to[v]);
}

int main() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i])
            to[ p[i] ] = i;
    }   

    for (int i = 1; i <= n; i++) {
        if (!p[i]) {
            cnt = 0;
            pos = 0;
            ok = 0;
            dfs(i);
            if (!ok)
                dif.pb(cnt);
        }
    }

    may[0] = 1;
    for (int i = 0; i < sz(dif); i++) {
        for (int j = N - 1; j >= 0; j--)
            if (may[j]) {
                if (j + dif[i] < N) 
                    may[ j + dif[i] ] = 1;
            }           
    }

    for (int j = 0; j + save < N; j++) {
        if (may[j])
            cout << j + save << endl;       
    }

    return 0;
}