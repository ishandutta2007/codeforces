#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rll(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int R = 1 << 21;
int t[R*2], t2[R*2], t3[R*2];
int kth(int k, int node = 1, int nl = 0, int nr = R){
    if(nl == nr-1)
        return nl;
    int nm = (nl+nr)/2;
    if(t[node*2] >= k)
        return kth(k, node*2, nl, nm);
    return kth(k-t[node*2], node*2+1, nm, nr);
}
void update(int pos, int add, int t1, int val){
    pos += R;
    t[pos] += add;
    t2[pos] += val;
    t3[pos] += t1;
    for(pos /= 2; pos > 0; pos /= 2)
        t[pos] = t[pos*2]+t[pos*2+1], t2[pos] = t2[pos*2]+t2[pos*2+1], t3[pos] = t3[pos*2]+t3[pos*2+1];
}
int sum(int ql, int qr, int node = 1, int nl = 0, int nr = R){
    if(ql <= nl && nr <= qr)
        return t2[node];
    if(qr <= nl || nr <= ql)
        return 0;
    int nm = (nl+nr)/2;
    return sum(ql, qr, node*2, nl, nm) + sum(ql, qr, node*2+1, nm, nr);
}
int cnt(int ql, int qr, int node = 1, int nl = 0, int nr = R){
    if(ql <= nl && nr <= qr)
        return t3[node];
    if(qr <= nl || nr <= ql)
        return 0;
    int nm = (nl+nr)/2;
    return cnt(ql, qr, node*2, nl, nm) + cnt(ql, qr, node*2+1, nm, nr);
}
vector<int> c;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> q(n);
    for(int i = 0; i < n; ++i){
        cin >> q[i].first >> q[i].second;
        c.pb(abs(q[i].second));
    }
    sort(c.begin(), c.end());
    c.resize(unique(c.begin(), c.end())-c.begin());
    for(int i = 0; i < n; ++i){
        int a = 1;
        if(q[i].s < 0)
            a = -1;
        int t1 = q[i].f;
        update(lower_bound(all(c), abs(q[i].s))-c.begin(), a, t1*a, q[i].s);
        int k = t3[1];
        if(k == 0)
            cout << t2[1] << '\n';
        else{
            int b = kth(t[1]-k+1);
            if(cnt(b, R) != k)
                cout << t2[1]+sum(b, R) << '\n';
            else{
                if(t3[1] == t[1])
                    cout << t2[1]+sum(b+1, R) << '\n';
                else
                    cout << t2[1]+sum(b+1, R)+c[kth(t[1]-k)] << '\n';
            }
        }
    }
    return 0;
}