#include <bits/stdc++.h>

using namespace std;

struct Node{
    int l, r, val;
    vector<int> lft, rht;
};

int M, N, Q, id = 0, cnt = 0, ans = 0;
Node seg[400005];
int mp[100005][12];
int vis[100005][12];
int clr[100005][12];
int par[20000005];
int lst[20000005];
int m[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<int> X, Y;

int getrt(int n){
    return par[n] = (par[n] == n ? n : getrt(par[n]));
}

void bfs(int lb, int rb, int r, int c){
    X.push(r), Y.push(c);
    clr[r][c] = id;
    vis[r][c] = cnt;
    while(X.size()){
        r = X.front(), c = Y.front();
        X.pop(), Y.pop();
        //cout << r << " " << c << endl;
        for(int k = 0; k<4; k++){
            int nr = m[k][0]+r, nc = m[k][1]+c;
            if(vis[nr][nc] != cnt && mp[nr][nc] == mp[r][c] && nr >= lb && nr <= rb){
                clr[nr][nc] = id;
                vis[nr][nc] = cnt;
                X.push(nr), Y.push(nc);
            }
        }
    }
}

void build(int l, int r, int idx){
    //cout << l << " " << r << " " << idx << endl;
    seg[idx].l = l, seg[idx].r = r;
    cnt++;
    for(int i = l; i<=r; i++){
        for(int j = 1; j<=M; j++){
            //cout << " " << i << " " << j << " " << vis[i][j] << endl;
            if(vis[i][j] != cnt){
                id++;
                //cout << id << endl;
                bfs(l, r, i, j);
                seg[idx].val++;
            }
        }
    }
    seg[idx].lft.push_back(0), seg[idx].rht.push_back(0);
    for(int i = 1; i<=M; i++){
        seg[idx].lft.push_back(clr[l][i]);
        seg[idx].rht.push_back(clr[r][i]);
    }
    if(l == r){
        return;
    }
    int mid = l+r>>1;
    build(l, mid, 2*idx);
    build(mid+1, r, 2*idx+1);
}

pair<int, int> query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r){
        ans += seg[idx].val;
        return {idx, idx};
    }
    int mid = seg[idx].l + seg[idx].r >> 1;
    if(r <= mid){
        return query(l, r, 2*idx);
    }
    else if(l > mid){
        return query(l, r, 2*idx+1);
    }
    else{
        auto lft = query(l, mid, 2*idx), rht = query(mid+1, r, 2*idx+1);
        for(int i = 1; i<=M; i++){
            if(lst[seg[lft.second].rht[i]] != cnt){
                lst[seg[lft.second].rht[i]] = cnt;
                par[seg[lft.second].rht[i]] = seg[lft.second].rht[i];
            }
            if(lst[seg[rht.first].lft[i]] != cnt){
                lst[seg[rht.first].lft[i]] = cnt;
                par[seg[rht.first].lft[i]] = seg[rht.first].lft[i];
            }
            if(mp[mid][i] == mp[mid+1][i]){
                if(getrt(seg[lft.second].rht[i]) != getrt(seg[rht.first].lft[i])){
                    par[getrt(seg[lft.second].rht[i])] = getrt(seg[rht.first].lft[i]);
                    ans--;
                }
            }
        }
        return {lft.first, rht.second};
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> M >> N >> Q;
    for(int j =1 ; j<=M; j++){
        for(int i = 1; i<=N; i++){
            cin >> mp[i][j];
        }
    }
    build(1, N, 1);
    while(Q--){
        int l, r;
        cin >> l >> r;
        cnt++;
        ans = 0;
        query(l, r, 1);
        cout << ans << "\n";
    }
}