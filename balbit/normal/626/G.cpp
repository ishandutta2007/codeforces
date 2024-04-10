#include <bits/stdc++.h>
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

const int maxn = 2e5+5;

int ene[maxn], val[maxn], tot[maxn];
//#define double long double
#define pdi pair<double, int>
priority_queue<pdi > want;
priority_queue<pdi, vector<pdi >, greater<pdi> > have;
//set<pdi> st;
int whome[maxn*10], lasttouch[maxn];
inline double GT(int x) {
    return val[x] * (ll)ene[x] / (double) (tot[x] * (ll)(tot[x] + 1));
}
inline double GT2(int x) {
    return val[x] * (ll)ene[x] / (double) (tot[x] * (ll)(tot[x] - 1));
}

int IT = 0;

signed main(){
    IOS();
    int n,T,q; cin>>n>>T>>q;
    REP(i,n) {
        cin>>val[i];
    }
    double re = 0;
    REP(i,n) {
        cin>>tot[i]; ene[i] = tot[i];
        whome[i] = i; lasttouch[i] = i;
        double dis = val[i] / (double)((tot[i]+1));
        //val[i] * ene[i] / (double)(tot[i] * (tot[i]+1))
        want.push({dis,i});
//        big.push({dis,i});
//        st.insert({dis,i});
    }
    IT = n;
    cout<<fixed<<setprecision(8);
    REP(nonono,q) {
        int tp; cin>>tp;
        int i; cin>>i; --i;
        ++IT;
        whome[IT] = i;
        lasttouch[i] = IT;

        if (tp == 1) {
            // add
            if (ene[i] != tot[i]) {
                bug("HIHI", re);
                re += (val[i]/(double)(ene[i]+1) - val[i]/(double)(tot[i]));
                re -= val[i] / (double)(ene[i]+1);
                ++T;
                bug("HIEFHIEFH", ene[i], val[i] / (double)(ene[i]+1));
                bug(re);
                --tot[i];
            }
            ++ene[i];
            ++ tot[i];
        }else{
            bug(tot[i], ene[i]);
            if (tot[i] != ene[i]) {
                re -= (val[i]/(double)ene[i] - val[i]/(double)(tot[i]));
            }
            --ene[i]; //-- tot[i];
//            if (ene[i] != tot[i]) {
            while (tot[i] > ene[i] * 2) {
//                assert(0);
                re -= GT2(i);
                --tot[i];
                ++T;
            }
            re += val[i] / (double)(ene[i]+1);
            --T;

//            }
        }
        bug(re, T);
        want.push({GT(i), IT});
        if (ene[i] != tot[i])
            have.push({GT2(i), IT});

        while (T > 0 && !want.empty()) {
            pdi P = want.top(); want.pop();
            int i = whome[P.s];
            if (lasttouch[i] == P.s && tot[i] + 1 <= ene[i] * 2) {
                re += P.f; --T;
                ++IT;
                whome[IT] = i; lasttouch[i] = IT;
                have.push({P.f, IT});
//                bug(P.f, IT);
                ++tot[i];
                assert(GT2(i) == P.f);
                want.push({GT(i), IT});
            }
        }
        bug(re);
        while (T < 0 && !have.empty()) {
            pdi P = have.top(); have.pop();
            int i = whome[P.s];
            if (lasttouch[i] == P.s) {
                bug(P.f, i);
                re -= P.f; ++T;
                ++IT;
                whome[IT] = i; lasttouch[i] = IT;
                want.push({P.f, IT});
                --tot[i];
                if (ene[i] != tot[i])
                    have.push({GT2(i), IT});
            }
        }
        while (1) {
            while (!have.empty() && lasttouch[whome[have.top().s]] != have.top().s) have.pop();
            while (!want.empty() && (lasttouch[whome[want.top().s]] != want.top().s || (tot[whome[want.top().s]]+1 > ene[whome[want.top().s]] * 2))) want.pop();
            if (!want.empty() && !have.empty()) {
                if (want.top().f > have.top().f) {
                    {
                        pdi P = want.top(); want.pop();
                        int i = whome[P.s];
                        re += P.f; //--T;
                        ++IT;
                        whome[IT] = i; lasttouch[i] = IT;
                        have.push({P.f, IT});
                        ++tot[i];
                        if (tot[i] > ene[i] * 2) {
                            bug(i, tot[i], ene[i]);
                            assert(0);
                        }
//                        bug(tot[i], )
                        assert(P.f == GT2(i));
                        want.push({GT(i), IT});
                    }
                    {
                        pdi P = have.top(); have.pop();
                        int i = whome[P.s];
                        re -= P.f; //++T;
                        ++IT;
                        whome[IT] = i; lasttouch[i] = IT;
                        want.push({P.f, IT});
                        --tot[i];
                        if (ene[i] != tot[i])
                            have.push({GT2(i), IT});
                    }
                }else break;
            }else break;
        }
        bug(re);
        bug(T);
//        cout<<"==========="<<endl;
//        REP(i,3) cout<<ene[i]<<' '<<tot[i]<<endl;
//        cout<<"==========="<<endl;
        cout<<re<<endl;
    }

}