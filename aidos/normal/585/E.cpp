#include <bits/stdc++.h>
using namespace std;


#define pb push_back
#define ll long long
#define mp make_pair
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define all(s) s.begin(), s.end()
#define sz(s) (int) s.size()
#define vi vector < int >

const int inf = (1ll << 31) - 1;
const int mod = (int) 1e9 + 7;


int n;
int a[500500];
map < int, int > m;
bitset < 10101010 > is_prime;
vector < int > li;
vector < int > cur, pr_li[500500];
int max_pr[10101001];

int cn[10101001];
short d[10101001];
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    
    for(int i = 2; i < 10000; i++){
        if(!is_prime[i]) 
            for(int j = i*i; j < 10101001; j+=i)
                is_prime[j] = 1;
    }

    for(int i = 2; i < 900; i++){
        cn[i] = 1;
        if(!is_prime[i]) li.pb(i);
    }
    
    for(int i = 900; i< 10101001; i++){
        cn[i] = 1;
        if(!is_prime[i]) {
            for(int j = i; j < 10101001; j+=i)
                max_pr[j] = i;
        }
    }
    scanf("%d", &n);
    ll cnt = 0;
    for(int i =0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n; i++){
        int cc = a[i];
        vector < int > &cur = pr_li[i];
        for(int j = 0; j < li.size() && cc > 1; j++){
            if( cc % li[j] == 0){
                cur.pb( li[j] );
                while(cc % li[j] == 0) cc/= li[j];
            }
        }
        if( cc > 1){
            if(max_pr[cc] * 1ll * max_pr[cc] == cc || max_pr[cc] == cc){
                cur.pb( max_pr[cc]);
            }
            else{
                cur.pb( max_pr[cc]);
                cur.pb( cc/max_pr[cc]);
            }
        }
        int len = cur.size(); 
        for(int mask = 1; mask <(1<<len); mask++){
            int num = 1;
            int ok = -1;
            for(int j = 0; j < len; j++){
                if(mask & ( 1<<j)){
                    ok *= -1;
                    num *= cur[j];
                }
            }
            d[num] = ok;
            cn[num] = (cn[num] * 2) % mod;
        }
    }
    for(int i = 0; i < 10101001; i++){
        cnt += d[i] * 1ll * (cn[i] - 1) % mod;
        cnt %= mod;
    }
    ll ans = 0;
    int tt = 500000003;
    for(int i = 0; i < n; i++){
        vector < int > &cur = pr_li[i];
        int len = cur.size(); 
        ll cntx = 0;
        for(int mask = 1; mask <(1<<len); mask++){
            int num = 1;
            int ok = -1;
            for(int j = 0; j < len; j++){
                if(mask & ( 1<<j)){
                    ok *= -1;
                    num *= cur[j];
                }
            }
            
            cntx += (cn[num] - 1 + mod)% mod * ok;
            if(cntx >= mod) cntx-=mod;
            else if( cntx < 0) cntx += mod;
        }
        ans += (cnt - cntx + mod) % mod;
        ans %= mod;
    }
    ans += mod;
    ans %= mod;
    cout << ans << endl;


    




    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}