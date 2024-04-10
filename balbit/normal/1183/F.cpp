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


int f2(vector<int> &a, int A, int s2){
    int n = a.size();
    vector<int> b;
    FOR(i,s2,n){
        if (A%a[i]!=0){
            b.pb(a[i]);
        }
    }
    int m = b.size();
    if (m==0) return 0;
    int X = b[0];
    REP(i,m){
        if (X%b[i]!=0){
            return X+b[i];
        }
    }
    return X;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
     int q;
     cin>>q;
     for (int cnt = 1; cnt<=q; cnt++){
        int n; cin>>n;
        int re = 0;
        vector<int> a(n); REP(i,n) cin>>a[i];

        sort( a.begin(), a.end() , greater<int>());
        a.erase( unique( a.begin(), a.end() ), a.end() );
        n = a.size();
        if (n==1){
            cout<<a[0]<<'\n'; continue;
        }
        int A = a[0]; int B = a[1];
        if (A%B!=0){
            re = A+B;
            REP(i,n){
                if (A % a[i]!=0 && B%a[i]!=0) {
                    re+=a[i]; break;
                }
            }
            cout<<re<<'\n'; continue;
        }else{
            int df = A/B;
            re = A;
            if (df==2){
                MXTO(re, B + f2(a,B,1));
                MXTO(re, A+ f2(a,A,0));
                int KK = 0;
                REP(i,KK){
                    if (1+i<n){
                        MXTO(re, f2(a,a[1+i], 1+i));
                    }
                }
            }else{
                re = A + f2(a,A,0);
            }cout<<re<<'\n'; continue;
        }



     }
    
}