#include <bits/stdc++.h>
#define int ll
#undef BALBIT
using namespace std;
#define ll long long
#define y1 zck_is_king
#define pii pair<ll, ll>
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
const ll mod = 1e9+7 ;


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



int brute(int n, int a, int b, bool la, bool lb) {
    vector<int> took(n, 0);
    int turn = 0;
    int left = n;
    if (a == b) {
        took[a] = 1;
//        if (left == n) bug(a, turn, la, lb);
        --left;
    }
    while (left > 1) {
//        bug(left);
        if (turn == 0) {
            do{
//                bug(a);
                if (la) --a;
                else ++a;
                if (a<0) {
                    la = 0; a = 1;
                }
                if (a >= n) {
                    la = 1; a=n-2;
                }
            }while (took[a]);
        }else{
            do{
//                    bug(b);
                if (lb) --b;
                else ++b;
                if (b<0) {
                    lb = 0; b = 1;
                }
                if (b >= n) {
                    lb = 1; b=n-2;
                }
            }while (took[b]);
        }
        turn ^= 1;
        if (a == b) {
            took[a] = 1;
//            if (left == n) bug(a, turn, la, lb);
            --left;
        }
    }
    REP(i,n) {
        if (!took[i]) return i;
    }
    return -1;
}

int smart(int n,int a, int b, bool la, bool lb){
    bool who = (a+b)%2; // if (a+b)%2 == who, then it's A's move
    if (a > b || (a == b && (la && !lb))) {
        swap(a,b); swap(la, lb);
        who ^= 1;
    }
    if (a != b) {
        if (la && !lb) {
            if (a < (n-1-b)) {
                b += a;
                a = 0;
                la = 0;
            }else{
                a -= (n-1-b);
                b = n-1;
                lb = 1;
            }
        }
        if (la && lb) {
            b -= a; a = 0;
            la = 0;
        }
        if (!la && !lb) {
            a += (n-1-b);
            b = n-1;
            lb = 1;
        }
    }
    if (a == b) {

    }else{
        assert(!la && lb);
        int pos = (a+b+((a+b)%2==who))/2;
        a = pos; b = pos;
    }
    bug(a);
    if (a == 0 || a == n-1) {
        bug("kill");
        return (n-1-a);
    }else if (la == lb) {
        if (la) return n-1;
        return 0;
    }else{
        bool toright = (a+b)%2 == who;
        bug(toright);

        if (toright ^ (1)) {
            // a's turn to move
            return 0;
        }else{
            return n-1;
        }
    }
}


signed main(){
    IOS();

    int t; cin>>t;
    while (t--) {
        int n;
        ll a, b;
        bool la, lb;
        string ass, bss;

        #ifndef BALBIT
        cin>>n;
        cin>>a>>b;
        cin>>ass>>bss;
        la = ass=="left";
        lb = bss=="left";
        #else
        n = 111;
        a = rand()%n; b = rand()%n;
        la = rand()%2; lb = rand()%2;
        #endif



//
//        int yar = brute(n,a,b,la,lb);
//        bug(yar);

        int yo = smart(n,a,b,la,lb);
        cout<<yo<<endl;
//        bug(yo);
//
//        if (yar != yo) {
//            bug(n,a,b,la,lb);
//            assert(0);
//        }

    }

}