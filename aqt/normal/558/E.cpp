#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, lzy;
    int fre[26];
};

Node seg[400005];
int N, Q;
string s;
int temp[26];

void pu(int idx){
    for(int i = 0; i<26; i++){
        seg[idx].fre[i] = seg[2*idx].fre[i] + seg[2*idx+1].fre[i];
    }
}

void pd(int idx){
    for(int i = 0; i<26; i++){
        seg[2*idx].fre[i] = seg[2*idx+1].fre[i] = 0;
    }
    seg[2*idx].fre[seg[idx].lzy] = seg[2*idx].r - seg[2*idx].l + 1;
    seg[2*idx+1].fre[seg[idx].lzy] = seg[2*idx+1].r - seg[2*idx+1].l + 1;
    seg[2*idx].lzy = seg[2*idx+1].lzy = seg[idx].lzy;
    seg[idx].lzy = -1;
}

void build(int l, int r, int idx){
    seg[idx].l = l;
    seg[idx].r = r;
    seg[idx].lzy = -1;
    if(l == r){
        seg[idx].fre[s[l-1]-'a']++;
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
    pu(idx);
}

void upd(int l, int r, int v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        for(int i =0; i<26; i++){
            seg[idx].fre[i] = 0;
        }
        seg[idx].fre[v] = seg[idx].r - seg[idx].l + 1;
        seg[idx].lzy = v;
        return;
    }
    if(seg[idx].lzy != -1){
        pd(idx);
    }
    int mid = seg[idx].l+seg[idx].r>>1;
    if(r <= mid){
        upd(l, r, v, 2*idx);
    }
    else if(l > mid){
        upd(l, r, v, 2*idx+1);
    }
    else{
        upd(l, mid, v, 2*idx);
        upd(mid+1, r, v, 2*idx+1);
    }
    pu(idx);
}

int query(int l, int r, int v, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        return seg[idx].fre[v];
    }
    if(seg[idx].lzy != -1){
        pd(idx);
    }
    int mid = seg[idx].l+seg[idx].r>>1;
    if(r <= mid){
        return query(l, r, v, 2*idx);
    }
    else if(l > mid){
        return query(l, r, v, 2*idx+1);
    }
    else{
        return query(l, mid, v, 2*idx) + query(mid+1, r, v, 2*idx+1);
    }
}

void traverse(int idx){
    if(seg[idx].l == seg[idx].r){
        for(int i = 0; i<26; i++){
            if(seg[idx].fre[i]){
                cout << (char) (i+'a');
                return;
            }
        }
    }
    if(seg[idx].lzy != -1){
        pd(idx);
    }
    traverse(2*idx);
    traverse(2*idx+1);
}

int main(){
    cin >> N >> Q >> s;
    build(1, N, 1);
    while(Q--){
        int l, r, k;
        cin >> l >> r >> k;
        for(int c = 0; c<26; c++){
            temp[c] = query(l, r, c, 1);
        }
        int crnt = l;
        if(k){
            for(int c = 0; c<26; c++){
                if(temp[c]){
                    upd(crnt, crnt+temp[c]-1, c, 1);
                    crnt += temp[c];
                }
            }
        }
        else{
            for(int c = 25; c>=0; c--){
                if(temp[c]){
                    upd(crnt, crnt+temp[c]-1, c, 1);
                    crnt += temp[c];
                }
            }
        }
    }
    traverse(1);
}