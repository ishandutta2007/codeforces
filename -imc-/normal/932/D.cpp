#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

const int maxN = 400500, logMaxN = 19;
int go[logMaxN][maxN], extGo[logMaxN][maxN];
li weightMax[logMaxN][maxN], weightSum[logMaxN][maxN];
li w[maxN];
int d[maxN];

void addVertex(int v, int parent) {
    //cout << "add " << v << " " << parent << " weight " << w[v] << endl;
    go[0][v] = parent;
    weightMax[0][v] = w[v];
    
    for (int log = 1; log < logMaxN; ++log) {
        go[log][v] = go[log - 1][go[log - 1][v]];
        weightMax[log][v] = max(weightMax[log - 1][v], weightMax[log - 1][go[log - 1][v]]);
    }
    
    int cur = go[0][v];
    for (int log = logMaxN - 1; log >= 0; --log) {
        if (weightMax[log][cur] < w[v]) {
            cur = go[log][cur];
        }
    }
    //cur = go[0][cur];
    //cout << "determined " << cur << endl;
    assert(cur < v && (cur == 0 || w[cur] >= w[v]));
    
    extGo[0][v] = cur;
    d[v] = d[extGo[0][v]] + 1;
    weightSum[0][v] = w[v];
    
    for (int log = 1; log < logMaxN; ++log) {
        extGo[log][v] = extGo[log - 1][extGo[log - 1][v]];
        weightSum[log][v] = weightSum[log - 1][v] + weightSum[log - 1][extGo[log - 1][v]];
    }
    
}

int query(int v, li X) {
    int orig_v = v;
#if 0
    cout << "query " << v << " " << X << endl;
    int exp = 0;
    
    li sum = 0;
    while (sum + w[v] <= X) {
        sum += w[v];
        ++exp;
        
        li now = w[v];
        v = go[0][v];
        while (v && w[v] < now) {
            v = go[0][v];
        }
        if (!v) break;
    }
    
    cout << "answer " << exp << endl;
#endif
    v = orig_v;
    
    li cur = 0;
    int ans = 0;
    for (int log = logMaxN - 1; log >= 0; --log) {
        if (!v) break;
        
        //cout << "try " << cur + weightSum[log][v] << "\n";
        if (cur + weightSum[log][v] <= X) {
            //cout << "success: go " << extGo[log][v] << " ans += " << d[v] - d[extGo[log][v]] << endl;
            cur += weightSum[log][v];
            int old_d = d[v];
            v = extGo[log][v];
            ans += old_d - d[v];
        }
    }
    
    //cout << "got: " << ans << endl;
    //assert(ans == exp);
    
    return ans;
}

void solve(bool __attribute__((unused)) read) {
    int nq;
    //read = false;
    if (read)
        cin >> nq;
    else {
        nq = 400000;
    }
    
    li last = 0;
    addVertex(1, 0);
    int cnt = 2;
    
    for (int queryId = 0; queryId < nq; ++queryId) {
        int type;
        li p, q;
        if (read)
            cin >> type >> p >> q;
        else {
            type = rand() % 2 + 1;
        }
        
        if (type == 1) {
            li R = p ^ last, W = q ^ last;
            if (!read) {
                R = rand() % (cnt - 1) + 1;
                W = rand() % 10;
            }
            assert(R < cnt);
            
            // add vertex, parent is R, weight is W
            w[cnt] = W;
            int v = cnt;
            ++cnt;
            
            addVertex(v, R);
        }
        else {
            li R = p ^ last, X = q ^ last;
            if (!read) {
                R = rand() % (cnt - 1) + 1;
                X = rand() % 100500;
            }
            assert(R < cnt);
            
            int v = R;
            // query from v
            
            last = query(v, X);
            cout << last << "\n";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}