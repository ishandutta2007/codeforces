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

ll nseq[maxn];
ll dp[maxn][maxn];
string s;
int n, m;

void upd(int at, int len){
    bool seen[26];
    fill (seen, seen+26, 0);
    if (len==1){
        dp[at][len]=1; return; 
    }
    FOR(i, at+1, n){
        int c = s[i]-'a';
        if (!seen[c]){
            dp[at][len] += dp[i][len-1];
        }
        seen[c]=1;
    }

}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
     cin>>n>>m;
     cin>>s;

     ll re = 0;
     ll tot = 1;
     bool ok = 0;
    FOR(len,1,n+1){
        bool seen[26];fill (seen, seen+26, 0);
        REP(i,n){
            upd(i, len);
            if (!seen[s[i]-'a']){
                seen[s[i]-'a']=1;
                nseq[len]+=dp[i][len];
            }
        }
        tot+=nseq[len];
        if (tot >= m) ok = 1;
    }
    nseq[0] = 1; 
    // debug(tot);
    if (!ok) GG();
    RREP(i,n+1){
        int have = nseq[i];
        ll cost = n-i;
        if (have>=m){
            re+= cost * m;
            break;
        }
        re+=cost*have;
        m-=have;
    }

    cout<<re<<endl;
    
}