#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

int step(int cnt) {
    for(char c = 'a'; c <= 'h'; ++c) {
        int kek = c-'a';
        if (kek&1) for(int i = 6; i >= 1; --i, --cnt){
            if (!cnt) return i+1;
            cout << c << i << ' ';
        } else for(int i = 2; i <= 7; ++i, --cnt) {
            if (!cnt) return i-1;
            cout << c << i << ' ';
        }
        int cur = kek&1 ? 1 : 7;
        if (!cnt) return cur;
        cout << char(c+1) << cur << ' ';
        --cnt;
    }
}

int step1(int cnt) {
    for(char c = 'a'; c <= 'h'; ++c) {
        int kek = c-'a';
        if (kek&1) for(int i = 7; i >= 1; --i, --cnt){
            if (!cnt) return i+1;
            cout << c << i << ' ';
        } else for(int i = 2; i <= 8; ++i, --cnt) {
            if (!cnt) return i-1;
            cout << c << i << ' ';
        }
        int cur = kek&1 ? 1 : 8;
        if (!cnt) return cur;
        cout << char(c+1) << cur << ' ';
        --cnt;
    }
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef HOME
    freopen("in.txt", "r", stdin);
#endif // HOME
    int n; cin >> n;
    cout << "a1 ";
    if (n <= 50) {
        int fin = step(n-2);
        cout << "h" << fin << ' ' << "h8";
    } else if (n <= 56) {
        step1(47);
        cout << "g1 h1 ";
        int left = n-49 - 1;
        for(int i = 2; i < 2+left; ++i) cout << "h" << i << ' ';
        cout << "h8";
    } else if (n < 63) {
        step1(54);
        cout << "h7 h1 ";
        int left = n-56 - 1;
        for(int i = 2; i < 2+left; ++i) cout << "h" << i << ' ';
        cout << "h8";
    } else {
        step1(47);
        cout << "h1 g1 g2 h2 h3 g3 g4 h4 h5 g5 g6 h6 h7 g7 g8 h8";
    }
}