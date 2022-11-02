#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
typedef long long ll;
int n, q;
struct node{
    node * l, * r;
    int sum;
    node() {
        l = nullptr;
        r = nullptr;
        sum = 0;
    }
    node(node * l, node * r):l(l), r(r){
        sum = l->sum + r->sum;
    }
    node(int x) {
        sum = x;
        l = nullptr;
        r = nullptr;
    }
};

node * t[maxn];
int a[maxn];

node *upd(node *pNode, int l, int r, int pos, int val) {
    if(l == r) {
        return new node(val);
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) {
        return new node(upd(pNode->l, l, mid, pos, val), pNode->r);
    }
    return new node(pNode->l, upd(pNode->r, mid+1, r, pos, val));
}


node *build(int l, int r) {
    if(l == r) {
        return new node();
    }
    int mid = (l + r) >> 1;
    return new node(build(l, mid), build(mid+1, r));
}

int findKth(node *pNode, int tl, int tr, int k) {
    if(tl == tr) {
        return tl;
    }
    int mid = (tl + tr)/2;
    if(pNode->r->sum >= k) {
        return findKth(pNode->r, mid+1, tr, k);
    }
    return findKth(pNode->l, tl, mid, k - pNode->r->sum);
}
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    t[0] = build(0, n);
    map<int, int> last;
    for(int i = 1; i <= n; i++) {
        if(last[a[i]] > 0) {
            node * cur = upd(t[i-1], 0, n, last[a[i]], 0);
            t[i] = upd(cur, 0, n, i, 1);
        } else {
            t[i] = upd(t[i-1], 0, n, i, 1);
        }
        last[a[i]] = i;
    }
    for(int k = 1; k <= n; k++) {
        int pos = n;
        int cnt = 0;
        while(pos > 0) {
            int d = k + 1;
            pos = findKth(t[pos], 0, n, d);
            cnt++;
        }
        cout << cnt << " ";
    }
}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
}