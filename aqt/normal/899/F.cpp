#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, sz;
    int fre[62];
};

Node seg[700005];
int N, Q;
char ans[200005];

int getidx(char c){
    if(c >= 'a' && c <= 'z'){
        return (int) (c-'a');
    }
    else if(c >= 'A' && c <= 'Z'){
        return (int) (c-'A')+26;
    }
    else{
        return (int) (c-'0') + 52;
    }
}

void build(int l, int r, int idx){
    seg[idx].l = l, seg[idx].r = r;
    seg[idx].sz = r-l+1;
    if(l == r){
        seg[idx].fre[getidx(ans[l])]++;
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    for(int k = 0; k<62; k++){
        seg[idx].fre[k] += seg[2*idx].fre[k] + seg[2*idx+1].fre[k];
    }
}

void query(int l, int r, int p, int idx){
    if(!seg[idx].fre[p]){
        return;
    }
    if(seg[idx].l == seg[idx].r){
        ans[seg[idx].l] = ' ';
        seg[idx].fre[p] = 0;
        seg[idx].sz = 0;
        return;
    }
    int mid = seg[2*idx].sz;
    if(r <= mid){
        query(l, r, p, 2*idx);
    }
    else if(l > mid){
        query(l-mid, r-mid, p, 2*idx+1);
    }
    else{
        query(l, mid, p, 2*idx);
        query(1, r-mid, p, 2*idx+1);
    }
    seg[idx].fre[p] = seg[2*idx].fre[p] + seg[2*idx+1].fre[p];
    seg[idx].sz = seg[2*idx].sz + seg[2*idx+1].sz;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> ans[i];
    }
    build(1, N, 1);
    while(Q--){
        int l, r;
        char c;
        cin >> l >> r >> c;
        int p = getidx(c);
        query(l, r, p, 1);
    }
    for(int i = 1; i<=N; i++){
        if(ans[i] != ' '){
            cout << ans[i];
        }
    }
    cout << "\n";
}