#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;

ll c[9];
int msk[71], msktopos[1<<9];

typedef array<ll, 70> Vec;
typedef array<Vec, 70> Mat;

#define REP(i,n) for(int i = 0; i<n; ++i)
const ll INF=0x3f3f3f3f3f3f3f3f;
int N=0;
void mul(Mat a, Mat b, Mat &c) {
    REP(i,N) REP(j,N) {
        c[i][j] = INF;
        REP(k,N) {
            c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
        }
    }
}

void mul(Vec a, Mat b, Vec &c) {
    fill(c.begin(), c.end(), INF);
    REP(i,N) {
        REP(j,N) {
            c[j] = min(c[j], a[i] + b[i][j]);
        }
    }
}

Mat TMpow[27];


signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int x,k,n,q; cin>>x>>k>>n>>q;
    for(int i = 1; i<=k; ++i) cin>>c[i];
    REP(m, (1<<k)) {
        if(__builtin_popcount(m) == x) {
            msk[N] = m; msktopos[m] = N; ++N;
        }
    }
    Mat TM;
    REP(i,N) REP(j,N) TM[i][j]=INF;
    REP(i,N) {
        if (msk[i] & 1) {
            for(int j = 1; j<=k; ++j) {
                int nw = (msk[i] >> 1) | (1<<(j-1));
                if (__builtin_popcount(nw) == x) {
                    TM[i][msktopos[nw]] = c[j];
                }
            }
        }else{
            TM[i][msktopos[msk[i]>>1]] = 0;
        }
    }
    TMpow[0] = TM;
    for(int i = 1; i<27; ++i) {
        mul(TMpow[i-1], TMpow[i-1], TMpow[i]);
    }
    Vec v;
    fill(v.begin(), v.end(), INF);
    v[msktopos[(1<<x)-1]] = 0;
    vector<pair<int, int> > que;
    ll add = 0;
    for(int i = 0; i<q; ++i) {
        int p, w; cin>>p>>w;
        if (p-1 >= n-x) {
            add += w;
        }else
            que.push_back({p-1,w});
    }
    que.push_back({n-x,0});
    sort(que.begin(), que.end());
    int prv = 0;
    for(auto &P : que) {
        int df = P.first - prv;
        for(int j = 0; j<27; ++j) {
            if(df & (1<<j)) {
                mul(v, TMpow[j], v);
//                cout<<(1<<j)<<endl;
            }
        }
        for(int i = 0; i<N; ++i) {
            if(msk[i] & (1)) {
                v[i] += P.second;
                if(v[i] > INF) v[i] = INF;
            }
        }
        prv = P.first;
    }
//    cout<<add<<endl;
    cout<<v[msktopos[(1<<x)-1]] + add<<endl;
}
/*
2 3 3 1
1 2 3
3 100
*/