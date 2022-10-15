#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"#%d (%s) = ",__LINE__,#__VA_ARGS__),_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

const int iinf = 1e9+10;
const ll inf = 1ll<<60;
const ll mod = 1e9+87;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b,mo) % mo;
}

const int maxn = 1e5+5;

//int H[maxn];
struct chg{
    int h, i, v;
};
vector<chg> H[2][maxn]; // Hash value, position changed, to what
int oH[21][maxn];
bool ok[21][maxn], grey[21][maxn];
string s;
int n;
ll preH[maxn], pB[maxn], ipB[maxn];
int lc2[maxn][26], rc2[maxn][26];
const int B = 59;

map<int, ll> mp[maxn];
ll greyhere[maxn];
int lclose[maxn][2], rclose[maxn][2];
vector<int> vc[26];

inline int swp(ll oh, int df, int p) {
    oh+=pB[p]*df%mod;
    if (oh >=mod) oh -= mod;
    if (oh < 0) oh += mod;
    return oh;
}

ll totgrey = 0;
ll greyps[maxn];
int dunlike[maxn][26];

void build(){
    pB[0] = ipB[0] = 1;
    for (int i = 0; i<=n; ++i) {
        pB[i+1] = pB[i] * B % mod;
        ipB[i+1] = inv(pB[i+1]);
    }
    fill(vc, vc+26, vector<int>{-1,-1});
    for (int i = 0; i<n; ++i) {
        preH[i+1] = (preH[i] + pB[i] * ( s[i] - 'a' + 1)) % mod;
        oH[0][i] = (s[i] - 'a' + 1);
        ok[0][i] = grey[0][i] = 1;
        lclose[i][0] = vc[s[i]-'a'].back(), lclose[i][1] = vc[s[i]-'a'][SZ(vc[s[i]-'a'])-2];
        for (int j = 0; j<26; ++j)
            lc2[i][j] = vc[j].back();
        vc[s[i]-'a'] .pb( i );
    }
    fill(vc, vc+26, vector<int>{n,n});
    for (int i = n-1; i>=0; --i) {
        rclose[i][0] = vc[s[i]-'a'].back(), rclose[i][1] = vc[s[i]-'a'][SZ(vc[s[i]-'a'])-2];
        for (int j = 0; j<26; ++j)
            rc2[i][j] = vc[j].back();
        vc[s[i]-'a'] .pb( i );
    }
    bool dpat = 0;
    for (int gp  = 0; (1<<gp)*4-1 <= n; ++gp) {
        dpat ^= 1;
        for (int i = 0; i<n; ++i) H[dpat][i].clear();
        int GD = 1<<gp;
        int len = GD * 4 - 1;
        bug(gp, GD, len);
        for (int i = 0; i<n; ++i) {
            int l = i - (GD * 2-1), r = i + (GD * 2-1);
            int lc = i - GD, rc = i+GD;
            if (l >= 0 && r < n){
                bug(gp, i, lc, rc, l, r);
                ll haha = (preH[r+1] - preH[l]) * ipB[l] % mod; if (haha < 0) haha += mod;
                bug(haha);
                oH[gp+1][i] = haha;
                if (!ok[gp][lc] || !ok[gp][rc]) {
                    continue;
                }
//                if (len == 3) {
//                    if (s[i-1]==s[i] && s[i+1]==s[i]) {
//                        // not grey
//                        continue;
//                    }else{
//                        ok[gp+1][i] = 1;
//                        if (s[i-1] == s[i+1]) {
//                            grey[gp+1][i] = 1;
//                        }else{
//                            if (s[i+1] != s[i]) // changing s[i-1] is ok
//                                H[dpat][i].pb({swp(haha,s[i-1]-s[i],0), i-1, s[i-1]-'a'});
//                            if (s[i-1] != s[i]) // changing s[i-1] is ok
//                                H[dpat][i].pb({swp(haha,s[i-1]-s[i],2), i+1, s[i+1]-'a'});
//                        }
//                    }
//                }else{
//                if( lclose[i][0] >= l && rclose[i][0] <= r) continue;
                if (!grey[gp][lc] && !grey[gp][rc]) continue;
                if (grey[gp][lc] && grey[gp][rc]) {
                    bug("Heyo");
                    if (oH[gp][lc] == oH[gp][rc]) {bug("m");
                        if (lclose[i][0] < l && rclose[i][0] > r) {
                            ok[gp+1][i] = 1;
                            grey[gp+1][i] = 1;
                        }else {
                            bug("ono");
                            ok[gp+1][i] = 1;
                            for (char x = 'a'; x <= 'z'; ++x) {
                                if (lc2[i][x-'a'] < l && rc2[i][x-'a'] > r) {
                                    H[dpat][i].pb({swp(oH[gp+1][i], x-s[i], len/2), i, x});
                                }
                            }
                        }
                    }else{
                        // try replacing center of left with center of right
                        if (s[rc] != s[i] && rclose[i][0] > r && (lclose[i][0] < l || (s[i] == s[lc] && lclose[i][1] < l))){
                            int ss = swp(oH[gp][lc], s[rc]-s[lc], GD-1);
                            if (ss == oH[gp][rc]) {
                                H[dpat][i].pb({swp(oH[gp+1][i], s[rc]-s[lc], GD-1), lc, s[rc]});
                            }
                        }
                        //replace center of right with center of left
                        if (s[lc] != s[i] && lclose[i][0] <l && (rclose[i][0] > r || (s[i] == s[rc] && rclose[i][1] > r))){
                            int ss = swp(oH[gp][rc], s[lc]-s[rc], GD-1);
                            if (ss == oH[gp][lc]) {
                                H[dpat][i].pb({swp(oH[gp+1][i], s[lc]-s[rc], (len+1)/2 + GD-1), rc, s[lc]});
                            }
                        }
                    }
                }else{
                    bug("one is grey");
                    if (grey[gp][lc]) {
                        bug("L");
                        if (lclose[i][0] < l) {
                            // if left side is grey, and right can reflect left, I only need to check
                            // whether left will interfere with center of i
                            for(chg c : H[dpat^1][rc]) {
                                if (c.v == -1) {
                                    bug(c.h);
                                    c.h = swp(c.h, s[lc] - s[c.i], GD-1);
                                    bug(c.h, oH[gp][rc]);
                                    c.v = s[lc];
                                }
                                if (c.h == oH[gp][lc]) {
                                    ll nh = (c.h + (s[i] - 'a' + 1) * pB[len/2]%mod + c.h * pB[len/2+1]%mod) % mod;
                                    H[dpat][i].pb({nh, c.i, c.v});
                                }
                            }
                        }
                    }
                    else {
                        bug("right is imposter");
                        assert(grey[gp][rc]);
                        if (rclose[i][0] > r) {
                            for(chg c : H[dpat^1][lc]) {
                                if (c.v == -1) {
                                    c.h = swp(c.h, s[rc] - s[c.i], GD-1);
                                    c.v = s[rc];
                                }
                                if (c.h == oH[gp][rc]) {
                                    ll nh = (c.h + (s[i] - 'a' + 1) * pB[len/2]%mod + c.h * pB[len/2+1]%mod) % mod;
                                    H[dpat][i].pb({nh, c.i, c.v});
                                }
                            }
                        }
                    }
                }

                if (SZ(H[dpat][i]) || grey[gp+1][i]) {
                    ok[gp+1][i] = 1;
                    for (chg c : H[dpat][i]) {
                        bug(c.i, (char)c.v, len);
                        mp[c.i][c.v] += len * (ll)len;
                    }
                }
                if (grey[gp+1][i]) {
                    totgrey += len * (ll)len;
                    greyps[l] -= len * (ll)len;
                    greyps[i] += len * (ll)len;
                    greyps[i+1] -= len * (ll)len;
                    greyps[r+1] += len * (ll)len;
                    // stuff this can't accept
                    for (int j = 0; j<26; ++j) {
                        if (lc2[i][j] >= l || rc2[i][j] <= r) {
                            dunlike[i][j] -= len*(ll)len;
                            bug(i,j,len);
                        }
                    }
                }
            }
        }
    }
}

signed main(){
    IOS();
    cin>>s;
    n = s.length();
    totgrey = n;
    build();
    ll re = 0;

    for (int i = 0; i<n; ++i) {
        if (i) greyps[i] += greyps[i-1];
//        re = max(re, mp[i][-1] + greyps[i]);
//        bug(i, mp[i][-1], greyps[i]);
        for (auto & p : mp[i]) {
            assert(char(p.f) != s[i]);
//            if (p.f != -1){

                bug(i, (char)p.f, p.s, greyps[i]);
            re = max(re, p.s + greyps[i] /*+ mp[i][-1]*/ + dunlike[i][p.f-'a']);
//            }
        }
    }
    bug(totgrey);
    cout<<re+totgrey<<endl;

}

/*
aaacaba
*/