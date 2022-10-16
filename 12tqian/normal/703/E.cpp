#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define vi vector<int>
#define f first
#define s second

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)

static vector<ll> divisors;
static vector<ll> primes;
static vector<ll> a;
static unordered_map<ll, ll> drank;

static pair<ll, ll> dp[1005][7000];
static pair<ll, ll> prev1[1005][7000];
static ll useful[1005];

void fast_io(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
}
void io(string taskname){
    string fin = taskname + ".in";
    string fout = taskname + ".out";
    const char* FIN = fin.c_str();
    const char* FOUT = fout.c_str();
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    fast_io();
}
void primeFactor(ll n){
    int times = 0;
    while (n%2 == 0){
        if(times == 0){
            primes.eb(2);
            times += 1;
        }
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i+2){
        times = 0;
        while (n%i == 0)
        {
            if(times == 0){
                primes.eb(i);
                times += 1;
            }
            n = n/i;
        }
    }
    if (n > 2){
        primes.eb(n);
    }
}
ll gcd(ll x, ll y){
    ll ans = 1;
    for(ll p : primes){
        while(x %p == 0 &&  y%p == 0){
            ans *= p;
            x/= p;
            y/=p;
        }
    }
    return ans;
}
ll adding(ll x, ll y, ll k){
    ll a = k/x;
    return __gcd(a, y) *x;
}

int main(){
    fast_io();
    ll n, k;
    cin >> n >> k;
   // primeFactor(k);
    ll mn = 1000000000005;
    int idx;
    f0r(i, n){
        ll d;
        cin >> d;
        useful[i] = __gcd(d, k);
        a.eb(d);
        if(mn>d){
            mn = d;
            idx =i;
        }
    }
    if(k == 1){
        cout << 1 << endl;
        cout << idx + 1 << endl;
        return 0;
    }
    for(ll i = 1; i<= sqrt(k); i++){
        if(k%i == 0){
            divisors.eb(i);
        }
        if(i != sqrt(k)&& k%i == 0){
            divisors.eb(k/i);
        }
        else{
            continue;
        }
    }
    sort(divisors.begin(), divisors.end());
    for(int i = 0; i<n;i++){
        for(int j = 0; j<divisors.size(); j++){
            dp[i][j] = mp(1005, 1);
        }
    }
    f0r (i, divisors.size()) {
        drank[divisors[i]] = i;
    }
    for(int i = 0; i<n; i++){
        if(i == 0){
            ll newD = __gcd(k, useful[i]);
            dp[0][drank[newD]] = mp(1, a[i]);
            prev1[0][drank[newD]] = mp(1, -1);
            continue;
        }
        for(int x = 0; x<divisors.size(); x++){
            if(x == 0){
                pair<ll, ll> previous1 = dp[i][x];
                dp[i][x] = min(dp[i][x], dp[i-1][x]);
                if(previous1 != dp[i][x]){
                    prev1[i][x] = mp(-1, x);
                }
                pair<ll, ll> previous = mp(1, a[i]);
                dp[i][drank[useful[i]]] = min(previous, dp[i][drank[useful[i]]]);
                prev1[i][drank[useful[i]]] = mp(1, x);
            }
            else{

                pair<ll, ll> previous1 = dp[i][x];
                dp[i][x] = min(dp[i][x], dp[i-1][x]);
                if(previous1!= dp[i][x]){
                    prev1[i][x] = mp(-1, x);
                }
                ll newD = adding(divisors[x], useful[i], k);

                pair<ll, ll> previous = dp[i][drank[newD]];
                dp[i][drank[newD]] = min(dp[i][drank[newD]], mp(dp[i-1][x].f+ 1, dp[i-1][x].s + a[i]));
                if(previous!= dp[i][drank[newD]]){
                    prev1[i][drank[newD]] = mp(1, x);
                }
            }
        }
    }
    pair<ll, ll> ans = mp (1005, 0);
    ans = min(ans, dp[n-1][divisors.size() -1]);
    vector<ll> fin;
    ll curn = n-1;
    ll curx = divisors.size() - 1;
    while(curx!= -1){
        if(prev1[curn][curx].f == 1){
            fin.eb(curn);
        }
        if(prev1[curn][curx].s == -1 ){
            break;
        }
        curx = prev1[curn][curx].s;
        curn  = curn -  1;
        if(curn == -1){
            break;
        }
    }
    if(ans.f == 1005){
        cout << -1;
        return 0;
    }
    cout << ans.f << endl;
   // sort(fin.begin(), fin.end());
    for(int i = 0; i<ans.f; i++){
        cout << fin[i] +1<< " ";
    }
    return 0;
}