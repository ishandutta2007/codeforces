#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define last PAUNSVOKNO

int n, a[200000], st[200000][18], lg[200001], last[30];
ll ret;

inline int get(int l, int r) {
    int z = lg[r - l + 1];
    return max(st[l][z], st[r - (1 << z) + 1][z]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], st[i][0] = a[i];
    for(int j = 1; j < 18; j++)
        for(int i = 0; i < n; i++)
            if(i + (1 << j) <= n)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
    memset(last, -1, sizeof(last));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 30; j++)
            if(a[i] & (1 << j))
                last[j] = i;
        vector<int> pos(1, -1);
        for(int j = 0; j < 30; j++)
            if(last[j] != -1)
                pos.push_back(last[j]);
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        int xr = 0;
        for(int j = pos.size() - 1; j != 0; j--) {
            for(int k = 0; k < 30; k++)
                if(last[k] == pos[j])
                    xr |= (1 << k);
            int bl = pos[j - 1] + 1, br = pos[j];
            if(get(br, i) >= xr) continue;
            while(bl < br) {
                int bm = (bl + br) / 2;
                if(get(bm, i) >= xr) bl = bm + 1;
                else br = bm;
            }
            ret += pos[j] - bl + 1;
        }
    }
    cout << ret;
}