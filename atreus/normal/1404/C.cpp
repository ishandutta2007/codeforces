#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxn = 3e5 + 10;

vector<int> seg[4*maxn];
int n, a[maxn];
int fen[maxn];

int get(int id, int L, int R, int l, int r, int x){
    if (r <= L or R <= l)
        return x;
    if (l <= L and R <= r){
        int idx = upper_bound(seg[id].begin(), seg[id].end(), x) - seg[id].begin();
        return x + idx;
    }
    int mid = (L + R) >> 1;
    x = get(2*id+0, L, mid, l, r, x);
    return get(2*id+1, mid, R, l, r, x);
}

void add(int idx, int val){
    for (idx; idx < maxn; idx += idx & -idx)
        fen[idx] += val;
}

void build(int id, int L, int R){
    if (L+1 == R){
        if (a[L] <= L)
            seg[id].push_back(L-a[L]);
        else
            seg[id].push_back(n+1);
        return;
    }
    int mid = (L + R) >> 1;
    build(2*id+0, L, mid);
    build(2*id+1, mid, R);
    int Zero = 0;
    for (int j = L; j < R; j++){
        if (a[j] > j){
            add(n, +1);
            seg[id].push_back(n);
            continue;
        }
        else{
            if (Zero >= j-a[j]){
                seg[id].push_back(0);
                Zero ++;
                continue;
            }
            int now = 0, untilNow = Zero;
            for (int i = 18; i >= 0; i--){
                if (now + (1 << i) >= maxn || now+(1<<i)+fen[now+(1<<i)]+untilNow >= j-a[j])
                    continue;
                now += (1 << i);
                untilNow += fen[now];
            }
            now ++;
            seg[id].push_back(now);
            add(now, +1);
        }
    }
    for (auto it : seg[id])
        if (it != 0)
            add(it, -1);
    sort(seg[id].begin(),seg[id].end());
}

int main(){
    ios_base::sync_with_stdio(false);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n+1);
    while (q --){
        int x, y;
        cin >> x >> y;
        int l = x+1, r = n-y+1;
        cout << get(1, 1, n+1, l, r, 0) << endl;
    }
}