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

int n,  k;
ll l;
int a[1001000];
ll t[1001000];
int b[1001000];
map < int, int > mm;
ll val[1001000];
ll sum (int r)
{
    ll result = 0;
    for (; r >= 0; r = (r & (r+1)) - 1)
        result += t[r];
    result %= mod;
    return result;
}

void inc (int i, ll delta)
{
    for (; i < n; i = (i | (i+1))){
        t[i] += delta;
        t[i] %= mod;
    }
}

ll sum (int l, int r)
{
    if( l == 0) return sum(r);
    return sum (r) - sum (l-1);
}

void init ()
{
    for(int i = 0; i < n; i++)
        t[i] = 0;
}
int main () {
    #ifdef LOCAL
    freopen ("a.in", "r", stdin);
    freopen ("a.out", "w", stdout);
    #endif
    cin >> n >> l >> k;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    int tt = unique(b, b + n) - b;
    for(int i = 0; i < tt; i++){
        mm[b[i]] = i;
    }
    for(int i = 0; i < n; i++)
        a[i] = mm[a[i]];

    ll answer = 0;
    for(int i = 0; i < n; i++){
        val[i] = 1;
        if( i <l){
            answer += ((l - i + n - 1)/n) % mod * 1ll * val[i]% mod;
            answer %= mod;
        }
    }
    
    for(int i = 1; i < k; i++){
        init();
        for(int j = 0; j < n; j++){
            inc(a[j], val[j]);
        }
        for(int j = 0; j < n; j++){
            val[j] = sum(a[j]);
        }
        for(int j = 0; j < n; j++){
            if( j + i * n < l){
                answer += ((l - j - i * n + n - 1)/n) % mod * 1ll * val[j] % mod;
                answer %= mod;
            }
        }
    }
    cout << answer << endl;

    #ifdef LOCAL
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}