#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

const int maxn = 5e3;

#define pair laafla

int n, m, t;
int p[maxn];
int a[maxn], b[maxn], pair[maxn];
int taken[maxn];

void read_move() {
    int x;
    cin >> x;
    taken[x] = true;
}

void write_move(int x) {
    cout << x << endl;
    taken[x] = true;
}

void make_move() {
    for(int i = 1; i <= 2 * n; i++) {
        if(pair[i] != 0 && taken[pair[i]] && !taken[i]) {
            write_move(i);
            return;
        }
    }
    int paired = 0;
    for(int i = 1; i <= 2 * n; i++) {
        if(pair[i] != 0 && !taken[i]) {
            if(paired == 0 || p[i] > p[paired]) {
                paired = i;
            }
        }
    }
    if(paired) {
        write_move(paired);
        return;
    }
    int just_max = 0;
    for(int i = 1; i <= 2 * n; i++) {
        if(!taken[i]) {
            if(just_max == 0 || p[i] > p[just_max]) {
                just_max = i;
            }
        }
    }
    assert(just_max);
    write_move(just_max);
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        pair[a[i]] = b[i];
        pair[b[i]] = a[i];
    }
    
    int t;
    cin >> t;
    int gg = 2 * n;
    while(gg) {
        if(t == 2) {
            read_move();
            make_move();
        } else {
            make_move();
            read_move();
        }
        gg -= 2;
    }
    return 0;
}