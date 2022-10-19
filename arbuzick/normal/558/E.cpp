#include <bits/stdc++.h>
#define int long long
using namespace std;
const int R = 1 << 17;
int t[R*2][26], fl[R*2];
void push(int node, int nl, int nr){
    if(fl[node] == 1){
        int nm = (nl+nr)/2;
        int s = nm-nl;
        for(int i = 0; i < 26; ++i){
            t[node*2][i] = min(s, t[node][i]);
            s -= t[node*2][i];
            t[node*2+1][i] = t[node][i]-t[node*2][i];
        }
        fl[node*2] = fl[node*2+1] = 1;
        fl[node] = 0;
    }
    if(fl[node] == -1){
        int nm = (nl+nr)/2;
        int s = nm-nl;
        for(int i = 25; i >= 0; --i){
            t[node*2][i] = min(s, t[node][i]);
            s -= t[node*2][i];
            t[node*2+1][i] = t[node][i]-t[node*2][i];
        }
        fl[node*2] = fl[node*2+1] = -1;
        fl[node] = 0;
    }
}
vector<int> get(int ql, int qr, int node = 1, int nl = 0, int nr = R){
    vector<int> r(26);
    if(ql <= nl && nr <= qr){
        for(int i = 0; i < 26; ++i)
            r[i] = t[node][i];
        return r;
    }
    if(qr <= nl || nr <= ql)
        return r;
    push(node, nl, nr);
    int nm = (nl+nr)/2;
    r = get(ql, qr, node*2, nl, nm);
    vector<int> r2 = get(ql, qr, node*2+1, nm, nr);
    for(int i = 0; i < 26; ++i)
        r[i] += r2[i];
    return r;
}
void sort1(int ql, int qr, int t1, vector<int> r, int node = 1, int nl = 0, int nr = R){
    int k = 0;
    for(int i = 0; i < 26; ++i)
        k += r[i];
    //if(k > max(0LL, min(nr, qr)-max(nl, ql)))
      //  cout << ql << ' ' << qr << ' ' << k << ' ' << nl << ' ' << nr << '\n';
    if(ql <= nl && nr <= qr){
        fl[node] = t1;
        for(int i = 0; i < 26; ++i)
            t[node][i] = r[i];
        return;
    }
    if(qr <= nl || nr <= ql)
        return;
    push(node, nl, nr);
    int nm = (nl+nr)/2;
    vector<int> r1(26), r2(26);
    int s = max(0LL, min(nm, qr)-max(ql, nl));
    //cout << node << ' ' << s << ' ' << k << '\n';
    if(t1 == 1){
        for(int i = 0; i < 26; ++i){
            r1[i] = min(s, r[i]);
            s -= r1[i];
            r2[i] = r[i]-r1[i];
        }
    }else{
        for(int i = 25; i >= 0; --i){
            r1[i] = min(s, r[i]);
            s -= r1[i];
            r2[i] = r[i]-r1[i];
        }
    }
    //if(s > 0)
      //  cout << min(nm, qr)-ql << ' ' << ql << ' ' << qr << ' ' << k << ' ' << nl << ' ' << nr << ' ' << s << ' ' << nm << '\n';
    sort1(ql, qr, t1, r1, node*2, nl, nm);
    sort1(ql, qr, t1, r2, node*2+1, nm, nr);
    for(int j = 0; j < 26; ++j)
        t[node][j] = t[node*2][j]+t[node*2+1][j];
}
void build(){
    for(int i = R-1; i > 0; --i)
        for(int j = 0; j < 26; ++j)
            t[i][j] = t[i*2][j]+t[i*2+1][j];
}
void ans(int node = 1, int nl = 0, int nr = R){
    if(nl == nr-1)
        return;
    push(node, nl, nr);
    int nm = (nl+nr)/2;
    ans(node*2, nl, nm);
    ans(node*2+1, nm, nr);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 0; i < n; ++i)
        t[i+R][s[i]-'a']++;
    build();
    while(q--){
        int i, j, k;
        cin >> i >> j >> k;
        i--;
        if(k == 0)
            k = -1;
        vector<int> r = get(i, j);
        sort1(i, j, k, r);
    }
    ans();
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 26; ++j)
            if(t[i+R][j])
                cout << char(j+'a');
    return 0;
}