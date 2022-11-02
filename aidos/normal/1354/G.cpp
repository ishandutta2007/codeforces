#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;

int n, k;
void out(vector<int> a) {
    for(int i = 0; i < a.size(); i++) {
        if(i) cout << " ";
        cout << a[i] + 1;
    }
    cout << endl;
}
int ask(vector<int> a, vector<int> b) {
    cout << "? " << a.size() << " "<<b.size() << endl;
    out(a);
    out(b);
    string res;
    cin >> res;
    if(res == "WASTED") exit(0);
    if(res == "FIRST")  return 1;
    if(res == "SECOND") return -1;
    return 0;
}
void solve() {
    cin >> n >> k;
    n = min(n, max(2 * k, n - k + 1));
    vector<int> pos;
    int iter = 0;
    int st = rand() % n;
    while(iter < 30) {
        int cur = rand() % n;
        if(st == cur) continue;
        int val = ask({st}, {cur});
        if(val == -1) st = cur;
        iter++;
    }
    for(int i = 0; i < n; i++) {
        if(i != st) pos.push_back(i);
    }
    vector<int> bad;
    bad.push_back(st);
    while(pos.size() > 1) {
        int x = 1;
        while(x < bad.size() && x * 2 < pos.size()) x *= 2;
        vector<int> a, b;
        for(int i = 0; i < x; i++) {
            a.push_back(bad[i]);
            b.push_back(pos[i]);
        }
        int res = ask(a, b);
        if(res == 0) {
            for(int i = 0; i < x; i++) {
                bad.push_back(pos[0]);
                pos.erase(pos.begin());
            }
        } else {
            while(pos.size() > x) pos.pop_back();
        }
    }
    cout << "! " << pos[0]+1 << endl;
}

int main() {
    srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}