#include <bits/stdc++.h>

using namespace std;

char u[205];
char v[205];

void solve() {
    scanf("%s",u);
    scanf("%s",v);
    char u_seq[205];
    char v_seq[205];
    int cur_u = 0;
    int cur_v = 0;
    int u_l = strlen(u);
    int v_l = strlen(v);
    int u_b = 0;
    int v_b = 0;
    for (int i=0;i<u_l;i++) {
        if (u[i] == 'B') {
            u_b = 1-u_b;
        } else {
            if (cur_u > 0 && u_seq[cur_u-1] == u[i]) {
                cur_u--;
            } else {
                u_seq[cur_u] = u[i];
                cur_u++;
            }
        }
    }
    for (int i=0;i<v_l;i++) {
        if (v[i] == 'B') {
            v_b = 1-v_b;
        } else {
            if (cur_v > 0 && v_seq[cur_v-1] == v[i]) {
                cur_v--;
            } else {
                v_seq[cur_v] = v[i];
                cur_v++;
            }
        }
    }
    if (u_b == v_b && cur_u == cur_v && (cur_u == 0 || u_seq[0] == v_seq[0])) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++) {
        solve();
    }
}