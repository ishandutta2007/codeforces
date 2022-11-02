#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int maxk = 355;
int n, k;
int a[maxn];
struct bl{
    int cnt[maxn];
    vector<int> c;
    bl() {
        memset(cnt, 0, sizeof cnt);
    }
    void add(int x) {
        c.push_back(x);
        cnt[x]++;
    }
} b[maxk];
void build() {
    int ind = 1;
    for(int i = 0; i < maxk; i++) {
        for(int x: b[i].c) {
            a[ind++] = x;
            b[i].cnt[x] = 0;
        }
        b[i].c.clear();
    }
    for(int i = 1; i <= n; i++) {
        b[i/maxk].add(a[i]);
    }
}
int calc(int pos, int x) {
    int ans = 0;
    for(int i = 0; i < maxk; i++) {
        if(b[i].c.size() <= pos) {
            pos -= b[i].c.size();
            ans += b[i].cnt[x];
        } else {
            for(int j = 0; j < pos; j++) {
                ans += (b[i].c[j] == x);
            }
            break;
        }
    }
    return ans;
}
void shift(int l, int r) {
    if(l == r) return;
    int x;
    for(int i = 0; i < maxk; i++) {
        if(r > b[i].c.size()) {
            r -= b[i].c.size();
        } else {
            x = b[i].c[r-1];
            b[i].cnt[x]--;
            b[i].c.erase(b[i].c.begin()+r-1);
            break;
        }
    }
    //cout <<"x="<< x << "\n";
    for(int i = 0; i < maxk; i++) {
        if(l > b[i].c.size()) {
            l -= b[i].c.size();
        } else {
            b[i].c.insert(b[i].c.begin() + l - 1, x);
            b[i].cnt[x]++;
            break;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i / maxk].add(a[i]);
    }
    cin >> k;
    int lastans = 0;
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        l = (l + lastans - 1) % n + 1;
        r = (r + lastans - 1) % n + 1;
        if(l > r) swap(l, r);
        if(type == 1) {
            shift(l, r);
            ++cnt;
        } else {
            int t;
            cin >> t;
            t = (t + lastans - 1) % n + 1;
            lastans = calc(r, t) - calc(l - 1, t);
            cout << lastans << "\n";
        }
        //build();
        if(cnt >= maxk) {
            build();
            cnt = 0;
        }
    }
}