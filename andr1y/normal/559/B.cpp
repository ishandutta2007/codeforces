//password1488
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
typedef pair<ull, ull> pull;
const ll N = 2e5+228;
const ll P = 29;
const ll M = 1e9+14881489;
string s[2];
ll n;
pull p[N*2];
pull hs[2][N];
ll pk[2][26][N];
inline pull gh(ll q, ll l, ll r, ll to) __attribute__((always_inline));
inline pull gh(ll q, ll l, ll r, ll to){
    pull hh = hs[q][r];
    if(l){
        hh.x -= hs[q][l-1].x;
        hh.y += M-hs[q][l-1].y;
        hh.y %= M;
    }
    hh.x *= p[to-l].x;
    hh.y *= p[to-l].y;
    hh.y %= M;
    return hh;
}
inline bool qq(ll s1, ll s2, ll sz) __attribute__((always_inline));
inline bool qq(ll s1, ll s2, ll sz){
    bool ok = 1;
    for(ll i = 0;i<26 && ok;i++){
        ok = ok && pk[0][i][s1+sz-1]-(s1?pk[0][i][s1-1]:0)==pk[1][i][s2+sz-1]-(s2?pk[1][i][s2-1]:0);
    }
    return ok;
}
bool is_equal(ll s1, ll s2, ll sz){
    pull h1 = gh(0, s1, s1+sz-1, n), h2 = gh(1, s2, s2+sz-1, n);
    if(h1==h2) return true;
    if(sz&1) return false;
    return (qq(s1, s2, sz>>1)&&qq(s1+(sz>>1), s2+(sz>>1), sz>>1)&&is_equal(s1, s2, sz>>1)&&is_equal(s1+(sz>>1), s2+(sz>>1), sz>>1))
        || (qq(s1, s2+(sz>>1), sz>>1)&&qq(s1+(sz>>1), s2, sz>>1)&&is_equal(s1, s2+(sz>>1), sz>>1)&&is_equal(s1+(sz>>1), s2, sz>>1));
}
signed main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	p[0] = {1, 1};
	for(ll i =1 ;i<2*N;i++){
	    p[i].x = p[i-1].x*P;
	    p[i].y = p[i-1].y*P;
	    p[i].y %= M;
	}
    cin >> s[0] >> s[1];
	n = s[0].length();
    hs[0][0] = {s[0][0]-'a'+1, s[0][0]-'a'+1};
    hs[1][0] = {s[1][0]-'a'+1, s[1][0]-'a'+1};
    for(ll i = 1;i<n;i++){
        for(ll q = 0;q<2;q++){
            hs[q][i].x = hs[q][i-1].x + (s[q][i]-'a'+1)*p[i].x;
            hs[q][i].y = hs[q][i-1].y + (s[q][i]-'a'+1)*p[i].y;
            hs[q][i].y %= M;
        }
    }
    for (int q = 0; q < 2; ++q) {
        for (int i = 0; i < 26; ++i) {
            pk[q][i][0] = (s[q][0]-'a'==i?1:0);
            for (int j = 0; j < n; ++j) {
                pk[q][i][j] = pk[q][i][j-1]+(s[q][j]-'a'==i?1:0);
            }
        }
    }
    bool ok  = qq(0, 0, n);
    if(ok) ok = is_equal(0, 0, n);
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}