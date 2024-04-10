#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
using namespace std;
const int R = 1 << 18;
int t[R*2];
int k = 0;
vector<bool> rev(19), sw(18);
vector<int> st(19);
void build(){
    for(int i = R-1; i > 0; --i)
        t[i] = t[i*2]+t[i*2+1];
}
void replace(int pos, int k){
    for(int k = 18; k > 0; --k)
        if(rev[k])
            pos = pos^(st[k]-1);
    for(int k = 17; k >= 0; --k)
        if(sw[k])
            pos = pos^st[k];
    pos += R;
    t[pos] = k;
    for(pos /= 2; pos > 0; pos /= 2)
        t[pos] = t[pos*2]+t[pos*2+1];
}
int sum(int ql, int qr, int node = 1, int nl = 0, int nr = R, int l = 18){
    if(ql <= nl && nr <= qr){
        int pr_nl = nl;
        for(int k = 18; k > l; --k)
            if(rev[k]){
                nl = nl^(st[k]-1);
                nr--;
                nr = nr^(st[k]-1);
                swap(nr, nl);
                nr++;
            }
        for(int k = 17; k >= l; --k)
            if(sw[k])
                nl = nl^st[k];
        node = node+(nl-pr_nl)/st[l];
        return t[node];
    }
    if(nr <= ql || qr <= nl)
        return 0;
    int nm = (nl+nr)/2;
    return sum(ql, qr, node*2, nl, nm, l-1)+sum(ql, qr, node*2+1, nm, nr, l-1);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    st[0] = 1;
    for(int i = 1; i < 19; ++i)
        st[i]= st[i-1]*2;
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < st[n]; ++i)
        cin >> t[i+R];
    build();
    while(q--){
        int t1;
        cin >> t1;
        if(t1 == 1){
            int x, k;
            cin >> x >> k;
            x--;
            replace(x, k);
        }else if(t1 == 2){
            int k;
            cin >> k;
            rev[k] = rev[k]^1;
        }else if(t1 == 3){
            int k;
            cin >> k;
            sw[k] = sw[k]^1;
        }else{
            int l, r;
            cin >> l >> r;
            l--;
            cout << sum(l, r) << '\n';
        }
    }
    return 0;
}