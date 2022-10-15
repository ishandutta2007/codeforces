#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
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
#define REP(i,n) for (int i = 0; i<n; ++i)
#define RREP(i,n) for (int i = n-1; i>=0; --i)
#define REP1(i,n) for (int i = 1; i<=n; ++i)
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
//const ll mod = 1e9+7 ;


void GG(){cout<<"0\n"; exit(0);}

ll mpow(ll a, ll n, ll mo){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = (__int128)re*a %mo;
        a = (__int128)a*a %mo;
        n>>=1;
    }
    return re;
}

ll pw(ll a, ll n) {
    if (a==1) return 1;
    __int128 re = 1;
    for (int j = 0; j<n; ++j) {
        re *= a;
        if (re > 1e18) {
            return 1000'000'000'000'000'000ll+1;
        }
    }
    return (ll)(re);
}

//ll inv (ll b, ll mo = mod){
//    if (b==1) return b;
//    return (mo-mo/b) * inv(mo%b,mo) % mo;
//}

const int maxn = 1e5+5;

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool np[maxn];

bool MillerRabin(u64 n) { // returns true if n is prime, else returns false.
    if (n<maxn) return !np[n];

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
//    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}


vector<int> here[maxn];
unordered_map<ll, int> where;
vector<ll> primes;
ll arr[maxn];
vector<int> need[maxn];
bool done[maxn];

int nthRoot(int A, int N)
{
    // intially guessing a random number between
    // 0 and 9
    double xPre = 2;

    //  smaller eps, denotes more accuracy
    double eps = 1e-3;

    // initializing difference between two
    // roots by INT_MAX
    double delX = INT_MAX;

    //  xK denotes current value of x
    double xK;

    //  loop untill we reach desired accuracy
    while (delX > eps)
    {
        //  calculating current value from previous
        // value by newton's method
        xK = ((N - 1.0) * xPre +
              (double)A/pow(xPre, N-1)) / (double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }

    return round(xK);
}

map<ll, ll> dat;


signed main(){
    IOS();
//    ll hi = (2e5+3)*(2e5+3)*(2e5+3);
//    bug(hi);
//    return 0;
//    ll hi = round(sqrt(529679786637038884ll));
//    bug(hi);
//    bug(hi*hi);
//    bug(529679786637038884ll);
//    bug((hi+1) * (hi+1));

//    return 0;
    clock_t t = clock();
    np[1] = 1;
    for (int i = 2; i<maxn; ++i) {
        if (!np[i]) {
            for (int j = i+i; j<maxn; j+=i) {
                np[j] = 1;
            }
            for (__int128 hi = i; hi<=1e18; hi *= i) {
                dat[(ll)(hi)] = i;
            }
        }
    }
    int n,k; cin>>n>>k;
    if (k == 1) {
        cout<<0<<endl; return 0;
    }
    ll mxd = 0;
    REP(i,n) {
        cin>>arr[i];
//        if (arr[0] == 529679786637038884ll) {
//        cout<<(clock()-t)/(double)CLOCKS_PER_SEC<<endl; return 0;
//    }
        ll daprime = 0;
        if (dat.count(arr[i])) {
            daprime = dat[arr[i]];
        }else{
            if (MillerRabin(arr[i])) {
                daprime = arr[i];
            }else{

                for (int J = 3; J>1; --J) {
//                    ll lR = 0, rR = J==3?1e6+1:1e9+1;
//                    while (lR != rR) {
//                        ll mid = (lR + rR)/2;
//                        if (pw(mid,J) < arr[i]) {
//                            lR = mid+1;
//                        }else{
//                            rR = mid;
//                        }
//                    }
                    ll hi = (J==3?roundl(cbrt(arr[i])):roundl(sqrt(arr[i])));
                    while (pw(hi,J) > arr[i]) -- hi;
                    int cnt = 0;
                    while (pw(hi+1,J) <= arr[i]){
                        ++hi; ++cnt;
                        if (cnt > 2) {
                            cout<<"WOT\n";
                            cout<<hi<<' '<<pw(hi+1,J)<<' '<<arr[i]<<endl; return 0;
                        }
                    }
//                    ll try2 = abs( - lR);
//                    if (try2 > 10000000) {
//                        cout<<"HIHI "<<try2<<' '<<J<<' '<<arr[i]<<' '<<lR<<' '<<(J==3?roundl(cbrt(arr[i])):roundl(sqrt(arr[i])))<<endl;
//
//                        return 0;
//                    }
//                    mxd = max(mxd, try2);
                    if (pw(hi,J) == arr[i]) {
                        if (MillerRabin(hi)) {
                            daprime = hi; break;
                        }
                    }
                }
            }
            dat[arr[i]] = daprime;
            bug(arr[i], i, daprime);
        }
        if (daprime) {
            done[i] = 1;
            if (!where.count(daprime)) {
                where[daprime] = SZ(primes);
                primes.pb(daprime);
            }
        }
        if (done[i]) {
            here[where[daprime]].pb(arr[i]);
        }else{
//            bug(i, arr[i], MillerRabin(arr[i]));
//            if (MillerRabin(arr[i])) {
//                where[arr[i]] = SZ(primes);
//                primes.pb(arr[i]);
//                here[where[arr[i]]].pb(arr[i]);
//            }
        }
        if ((clock()-t) > CLOCKS_PER_SEC * 0.5) {
            assert(0);
        }
    }
//    if (arr[0] == 529679786637038884ll) {
//        cout<<"Max diff: "<<mxd<<endl;
//        return 0;
////        cout<<(clock()-t)/(double)CLOCKS_PER_SEC<<endl; return 0;
//    }
    vector<int> whoto;
    REP(i,n) {
        if (!done[i]) {
            ll X = arr[i];
            vector<int> tmp;
            REP(j, SZ(primes)) {
                if (X % primes[j] == 0) {
                    tmp.pb(j);
                    while(X % primes[j]==0) X/=primes[j];

                }
            }
            if (X != 1) continue;
            if (SZ(tmp) == 1) {
//                assert(0);
                here[tmp[0]].pb(arr[i]);
            }else{
                need[i] = tmp;
//                whoto.pb({i, tmp});
            }
        }
    }

    if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
        cout<<"OOH MAN "<<__LINE__<<endl; return 0;
    }

    REP(i,n) {
        if (SZ(need[i])) {
            bool bad = 0;
            for (int j : need[i]) {
                if (SZ(here[j]) <= 1) {
                    bad = 1;
                }
            }
            if (!bad) {
                whoto.pb(i);
            }
        }
    }
    int nofp = 0;
    int mx = SZ(whoto);
    bool more = 0;
    vector<int> primeid;
    REP(j,SZ(primes)){
        if (SZ(here[j] ) >= 2 ){
            nofp++;
            mx += SZ(here[j]);
            bug(j, primes[j], SZ(here[j]));
            primeid.pb(j);
            if (SZ(here[j]) > 2) more = 1;

        }
    }

    sort(ALL(primeid), [&](int i,int j){return SZ(here[i]) > SZ(here[j]);}); // descending number of times it is used
    sort(ALL(whoto), [&](int a, int b){return SZ(need[a]) < SZ(need[b]);}); // ascending size of set
    bug(mx);
    if (mx < k) {
        cout<<"0"<<endl; return 0;
    }
//    bug(more^SZ(whoto) % 2, k%2);
//    bug(more, SZ(whoto), k%2);
    if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
        cout<<"OOH MAN "<<__LINE__<<endl; return 0;
    }
    if (more || k%2==0 ){
        bug("Hmmm");
        while (mx > k && SZ(whoto)) {
            whoto.pop_back(); -- mx;
            if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
                cout<<"OOH MAN "<<__LINE__<<endl; return 0;
            }
        }
        for (int rar = SZ(primeid)-1; rar>=0; --rar) {
            int it = primeid[rar];
            while (mx > k) {
                if (SZ(here[it]) == 2 ) {
                    if (mx-2>=k) {
                        mx -= 2;
                        here[it].pop_back();
                        here[it].pop_back();
                    }
                    break;
                }else{
                    mx--;
                    here[it].pop_back();
                }
                if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
                    cout<<"OOH MAN "<<__LINE__<<endl; return 0;
                }
            }
        }

        assert(mx == k);
    }else{
        bug("Hey");
        if (SZ(whoto) == 0) {
            cout<<"0"<<endl; return 0;
        }
        while (mx > k && SZ(whoto) > 1) {
            whoto.pop_back(); -- mx;
            if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
                cout<<"OOH MAN "<<__LINE__<<endl; return 0;
            }
        }
        for (int rar = SZ(primeid)-1; rar>=0; --rar) {
            int it = primeid[rar];
            bool ok = 1;
            for (int x : need[whoto[0]]) {
                if (x == it) {
                    ok = 0; break;
                }
                if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
                    cout<<"AWW MAN"<<endl; return 0;
                }
            }
            if (ok==0) continue;
            if (mx-2 >= k ) {
//                if (SZ(here[it]) == 2 ) {
//                    if (mx-2>=k) {
                assert(SZ(here[it]) == 2);
                        mx -= 2;
                        here[it].pop_back();
                        here[it].pop_back();
//                    }
//                    break;
//                }else{
//                    assert(0);

            }
            if ((clock()-t) > CLOCKS_PER_SEC * 0.7) {
                cout<<"AWW MAN"<<endl; return 0;
            }
        }
        if (mx != k) {
            cout<<"0"<<endl; return 0;
        }
    }
    for(auto & x : whoto) {
        cout<<arr[x]<<' ';
    }
    for (auto & ii : primeid) {
        for (int x : here[ii]) {
            cout<<x<<' ';
        }
    }
}

/*
7 6
4 4 3 3 5 5 6
*/