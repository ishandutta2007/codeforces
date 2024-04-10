#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1e5 + 100;
int n;
string s[maxn];
int K = 500;
struct node{
    int L, R;
    string color[2];
    int is_locked[2];

    void set_seg(int l, int r) {
        L = l;
        R = r;
    }
    void calc() {
        color[0] = '-';
        color[1] = '-';
        int locked = 1;
        is_locked[0] = 0;
        is_locked[1] = 1;
        for(int i = L; i < R; i++) {
            if(s[i][0] == 'l') {
                is_locked[0] = 1;
                is_locked[1] = 1;
            } else if(s[i][0] == 'u') {
                is_locked[0] = 0;
                is_locked[1] = 0;
            } else {
                if(!is_locked[0]) color[0] = s[i];
                if(!is_locked[1]) color[1] = s[i];
            }
        }
    }
}b[maxn];

string get_ans() {
    int cur = 0;
    string color = "blue";
    for(int i = 0; i*K <= n; i++) {
        if(b[i].color[cur][0] != '-') {
            color = b[i].color[cur];
        }
        cur = b[i].is_locked[cur];
    }
    return color;
}
void solve() {
    cin >> n;
    s[0] = "blue";
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 0; i*K <= n; i++) {
        b[i].set_seg(i*K, min((i + 1) * K, n + 1));
        b[i].calc();
    }
    int t=0;
    //cin >> t;
    cout << get_ans() << "\n";
    for(int i = 0; i < t; i++) {
        int pos;
        string val;
        cin >> pos >> val;
        s[pos] = val;
        b[pos/K].calc();
        //cout << pos << " " << val << "\n";
        cout << get_ans() << "\n";
    }
}

int main() {
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d:\n", i);
        solve();
    }

    return 0;
}