#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

#define int ll

const int maxn = 1e2+3;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

const int B = 1024+20;

ll cst[B]; // Cost for each mask
ll c2[B]; int i2[B];
ll pc[B]; pii pid[B];
int id[B];
int nf[B]; // Number of friends with this mask
int can[B];

int genmsk(vector<int> &a){
    int n = a.size();
    // debug(n);
    int re = 0;
    int j = 0;
    REP(i,10){
        re*=2;
        if (j<n&&(a[j]==i+1)){
            re++;
            j++; 
        }
    }
    return re;
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    fill(pc, pc+1024, inf);
    fill(cst, cst+1024, inf);fill(c2, c2+1024, inf);
    int n; cin>>n;
    int m; cin>>m;
    REP(i,n){
        int nl; cin>>nl;
        vector<int> a(nl); REP(j, nl) cin>>a[j];
        sort(ALL(a));
        int xx = genmsk(a);
        // debug(xx);
        nf[xx]++;
    }
    vector<pii> v;
    REP(i,m){
        ll nct; cin>>nct;
        int nt; cin>>nt;
        vector<int> a(nt); REP(j, nt) cin>>a[j];
        sort(ALL(a));
        int xx = genmsk(a); 
        if (cst[xx]>nct){
            if (cst[xx] > c2[xx]) {
                c2[xx] = cst[xx]; i2[xx] = id[xx];
            }
            cst[xx] = nct;
            id[xx] = i+1; // 1 - based
        }else{
            if (c2[xx]>nct){
                c2[xx ] = nct; i2[xx] = i+1;
            }
        }
    }
    REP(i,1024) REP(j,1024){
        if (i==j){
            if (id[j]&&id[j]){
                int nmsk = i | j;
                int mycost = cst[i] + c2[j];
                // debug(mycost);
                if (pc[nmsk] > mycost){
                    pc[nmsk] = mycost;
                    pid[nmsk] = {id[i],i2[j]};
                }
            }
        }
        else if (id[i] && id[j]){
            int nmsk = i | j;
            int mycost = cst[i] + cst[j];
            // debug(mycost);
            if (pc[nmsk] > mycost){
                pc[nmsk] = mycost;
                pid[nmsk] = {id[i],id[j]};
            }
        }
    }

    int mc = 0;
    
    REP(i, 1024){
        if (nf[i]){
            REP(j, 1024){
                if (((j|i) == j) && pc[j]!=inf){
                    can[j]++;
                    MXTO(mc, can[j]);
                }
            }
        }
    }
    int mcst = inf;
    pii ans = {0,0};
    REP(i, 1024){
        if (can[i]== mc){
            if (pc[i]<mcst){
                mcst = pc[i]; 
                ans = pid[i];
                // cout<<"UPD"<<endl;
            }
        }
    }
    cout<<ans.f<<' '<<ans.s<<endl;

}