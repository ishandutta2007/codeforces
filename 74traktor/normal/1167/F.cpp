#include <bits/stdc++.h>

using namespace std;

#define int long long
int b[500005];
int mod = 1e9 + 7;
int a[500005];
int c[500005];
int tree[2000000];
int tree1[2000000];
int psh[2000000];
int psh1[2000000];

inline void push(int i, int len){
    if (len == 1) tree[i] += psh[i], psh[i] = 0, tree[i] %= mod;
    else{
        psh[2 * i + 1] += psh[i];
        psh[2 * i + 2] += psh[i];
        psh[2 * i + 1] %= mod;
        psh[2 * i + 2] %= mod;
        psh[i] = 0;
    }
}

void upd(int i, int l, int r, int lq, int rq, int dx){
    //cout << l << " " << r << " " << lq << " " << rq << endl;
    //push(i, r - l);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq){
        psh[i] += dx;
        push(i, r - l);
        return;
    }
    int m = (r + l) / 2;
    upd(2 * i + 1, l, m, lq, rq, dx);
    upd(2 * i + 2, m, r, lq, rq, dx);
}

inline void push1(int i, int len){
    if (len == 1) tree1[i] += psh1[i], psh1[i] = 0, tree1[i] %= mod;
    else{
        psh1[2 * i + 1] += psh1[i];
        psh1[2 * i + 2] += psh1[i];
        psh1[i] = 0;
        psh1[2 * i + 1] %= mod;
        psh1[2 * i + 2] %= mod;
    }
}

void upd1(int i, int l, int r, int lq, int rq, int dx){
    //push1(i, r - l);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq){
        psh1[i] += dx;
        push1(i, r - l);
        return;
    }
    int m = (r + l) / 2;
    upd1(2 * i + 1, l, m, lq, rq, dx);
    upd1(2 * i + 2, m, r, lq, rq, dx);
}

int get_ans(int i, int l, int r, int lq){
    push(i, r - l);
    if (r - l == 1) return tree[i];
    int m = (r + l) / 2;
    if (lq < m) return get_ans(2 * i + 1, l, m, lq);
    else return get_ans(2 * i + 2, m, r, lq);
}

int get_ans1(int i, int l, int r, int lq){
    push1(i, r - l);
    if (r - l == 1) return tree1[i];
    int m = (r + l) / 2;
    if (lq < m) return get_ans1(2 * i + 1, l, m, lq);
    else return get_ans1(2 * i + 2, m, r, lq);
}

main(){
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        a[i] = b[i];
    }
    //cout << sum << endl;
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i){
        int lef = 1, righ = n + 1;
        while (righ - lef > 1){
            int mid = (righ + lef) / 2;
            if (b[mid] <= a[i]) lef = mid;
            else righ = mid;
        }
        c[i] = lef;
    }
    //for (int i = 1; i <= n; ++i) cout << c[i] << " ";
    //cout << endl;
    for (int i = 1; i <= n; ++i){
        ans += ((n - i + 1) * i) % mod * a[i], ans %= mod;
        ans += (a[i] * get_ans(0, 1, n + 1, c[i]) % mod * (n - i + 1)), ans %= mod;
        //cout << ans << '\n';
        ans += ((n - i + 1) * a[n - i + 1] % mod * get_ans1(0, 1, n + 1, c[n - i + 1])), ans %= mod;
        //cout << ans << " " << get_ans1(0, 1, n + 1, c[n - i + 1]) << '\n';
        upd(0, 1, n + 1, c[i], n + 1, i);
        upd1(0, 1, n + 1, c[n - i + 1], n + 1, i);
    }
    cout << ans << '\n';
    return 0;
}