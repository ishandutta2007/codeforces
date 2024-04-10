#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int a[maxn];

struct node{
    int maxSuf, maxPref, maxVal;
    int minSuf, minPref, minVal;
    int minL, minR;
    int maxL, maxR;
    int minSufPos;
    int maxSufPos;
    int minPrefPos;
    int maxPrefPos;
    int sum;
    node() {
        maxSuf=0, maxPref=0, maxVal=0;
        minSuf=0, minPref=0, minVal=0;
    }
};
node t[4*maxn];
int rev[4 * maxn];
void changeNode(int v) {
    swap(t[v].maxSuf, t[v].minSuf);
    swap(t[v].maxPref, t[v].minPref);
    swap(t[v].maxVal, t[v].minVal);
    swap(t[v].minPrefPos, t[v].maxPrefPos);
    swap(t[v].minSufPos, t[v].maxSufPos);
    swap(t[v].minL, t[v].maxL);
    swap(t[v].minR, t[v].maxR);
    t[v].maxSuf *= -1;
    t[v].minSuf *= -1;
    t[v].maxPref *= -1;
    t[v].minPref *= -1;
    t[v].maxVal *= -1;
    t[v].minVal *= -1;
    t[v].sum *= -1;
    rev[v] ^= 1;
}
node createNode(int val, int pos) {
    node res;
    res.sum = val;
    res.minPrefPos = res.maxPrefPos = res.minSufPos = res.maxSufPos = -1;
    res.minL = res.minR = res.maxL = res.maxR = -1;
    if(val > 0) {
        res.maxPref=res.maxSuf=res.maxVal = val;
        res.maxPrefPos = res.maxSufPos = res.maxL = res.maxR = pos;
    }
    else if(val < 0) {
        res.minPref = res.minSuf = res.minVal = val;
        res.minPrefPos = res.minSufPos = res.minL=res.minR = pos;
    }
    return res;
}
node merge(node a, node b) {
    node res = a;
    res.sum = a.sum + b.sum;

    if(b.maxVal > res.maxVal) {
        res.maxVal = b.maxVal;
        res.maxL = b.maxL;
        res.maxR = b.maxR;
    }
    if(a.maxSuf + b.maxPref > res.maxVal) {
        res.maxVal = a.maxSuf + b.maxPref;
        res.maxL = a.maxSufPos;
        res.maxR = b.maxPrefPos;
    }
    if(b.minVal < res.minVal) {
        res.minVal = b.minVal;
        res.minL = b.minL;
        res.minR = b.minR;
    }

    if(a.minSuf + b.minPref < res.minVal) {
        res.minVal = a.minSuf + b.minPref;
        res.minL = a.minSufPos;
        res.minR = b.minPrefPos;
    }
    res.maxSuf = b.maxSuf;
    res.maxSufPos = b.maxSufPos;
    if(res.maxSuf < b.sum + a.maxSuf) {
        res.maxSuf = b.sum + a.maxSuf;
        res.maxSufPos = a.maxSufPos;
    }
    res.minSuf = b.minSuf;
    res.minSufPos = b.minSufPos;
    if(res.minSuf > a.minSuf + b.sum) {
        res.minSuf = b.sum + a.minSuf;
        res.minSufPos = a.minSufPos;
    }
    if(res.maxPref < a.sum + b.maxPref) {
        res.maxPref = b.maxPref + a.sum;
        res.maxPrefPos = b.maxPrefPos;
    }
    if(res.minPref > a.sum + b.minPref) {
        res.minPref = a.sum + b.minPref;
        res.minPrefPos = b.minPrefPos;
    }
    return res;
}
void push(int v, int l, int r) {
    if(l == r) return;
    if(!rev[v]) return;
    rev[v] ^= 1;
    changeNode(v*2);
    changeNode(v*2+1);
}
void build(int v, int l, int r) {
    if(l == r) {
        t[v] = createNode(a[l], l);
    }else {
        int mid = (l + r)/2;
        build(v * 2, l, mid);
        build(v*2+1, mid+1, r);
        t[v] = merge(t[v * 2], t[v*2+1]);
    }
}
void upd(int v, int l, int r, int pos, int val) {
    push(v, l, r);
    if(l == r) {
        t[v] = createNode(val, l);
    } else {
        int mid = (l + r)/2;
        if(pos <= mid) upd(v * 2, l, mid, pos, val);
        else upd(v * 2 + 1, mid + 1, r, pos, val);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
}

void upd2(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(tr < l || r < tl)
        return;
    if(l <= tl && tr <= r) {
        changeNode(v);
        return;
    }
    int mid = (tl + tr)/2;
    upd2(v * 2, tl, mid, l, r);
    upd2(v * 2 + 1, mid + 1, tr, l, r);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if(l <= tl && tr <= r) return t[v];
    int mid = (tl + tr)/2;
    if(r <= mid) return get(v*2, tl, mid, l, r);
    if(mid < l) return get(v * 2 + 1, mid+1, tr, l, r);
    return merge(get(v*2, tl, mid, l, r), get(v * 2 + 1, mid+1, tr, l, r));
}
vector <pii> d;
int calc(int l, int r, int k) {
    d.clear();
    int ans = 0;
    for(int i = 0; i < k; i++) {
        node a = get(1, 0, n-1, l, r);
        if(a.maxVal <= 0) break;
        ans += a.maxVal;
        upd2(1, 0, n-1, a.maxL, a.maxR);
        d.push_back({a.maxL, a.maxR});
    }
    for(int i = d.size()-1; i >= 0; i--) {
        upd2(1, 0, n-1, d[i].first, d[i].second);
    }
    return ans;
}
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n-1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int type;
        cin>>type;
        if(type == 0) {
            int pos, val;
            cin >> pos >> val;
            upd(1, 0, n-1, pos-1, val);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << calc(l-1, r-1, k) << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}