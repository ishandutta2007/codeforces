#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define SZ(x) (int) ((x).size())
#define ALL(x) (x).begin(),(x).end()
#define pb push_back

#ifdef BALBIT
#define bug(...) cerr<<"#"<<__LINE__<<": "<<#__VA_ARGS__<<": ", _do(__VA_ARGS__)
template<typename T> void _do(T&&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T&&x, S&&...y){cerr<<x<<", "; _do(y...);}
#define IOS()
#else
#define bug(...)
#define IOS() ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n'
#endif // BALBIT
#define f first
#define s second

const int maxn = 3e5+2;

struct pt{
    int x,y;
    pt operator - (pt oth) {
        return {x-oth.x, y-oth.y};
    }
    ll operator ^ (pt oth) {
        return x * oth.y - y*oth.x;
    }
};



signed main(){
    IOS();
    int n; cin>>n;
    vector<pt> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i].x>>v[i].y;
    }
    auto cmp = [&] (pt a, pt b) {
        int o1 = (a.y>0 || (a.y==0 && a.x>0));
        int o2 = (b.y>0 || (b.y==0 && b.x>0));
        if (o1==o2) {
            return (a^b)>0;
        }else{
            return o1>o2;
        }
    };
    ll re = 0;
    for (int i = 0;i<n; ++i) {
        vector<pt> tmp;
        bug(v[i].x, v[i].y);
        for (int j = 0; j<n;++j){
            if (i!=j) tmp.pb(v[j]-v[i]);
        }
        sort(ALL(tmp), cmp);
        for (pt & p : tmp) {
            bug(p.x, p.y);
        }
        int k = 0;
        auto f = [&](int x){return x>=SZ(tmp)?x-SZ(tmp):x;};
        int rev = 0;
        for (int j = 0, cnt = 0; cnt < SZ(tmp); j = f(j+1), ++cnt) {
            rev++;
            while (f(k+1) !=j && ( (tmp[j] ^ tmp[f(k+1)]) > 0)) k = f(k+1);
            int A = k - j;
            if (A<0) A += SZ(tmp);
            A = f(A);
            int B = SZ(tmp) - A - 1;
            bug(j,k,A,B);
//            bug(v[f(k+1)].x, v[f(k+1)].y);
            re += (A) * (ll)(A-1) / 2 * (ll) (B) * (ll)(B-1) / 2;
            if (A== 2 && B == 2) {
                bug(tmp[j].x, tmp[j].y);
                bug(tmp[k].x, tmp[k].y);
            }
        }
        assert(rev == SZ(tmp));
    }
    cout<<re/2<<endl;
}