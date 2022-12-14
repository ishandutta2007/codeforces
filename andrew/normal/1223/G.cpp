#include <bits/stdc++.h>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define sset ordered_set
#define sqr(x) (x)*(x)
#define pw(x) (1ll << x)

using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN = 1123456;
const int N = 5e5;
const int inf = 1e9;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int pref[MAXN], cnt[MAXN];

struct Set{
    int a = -inf, b = -inf;

    void insert(ll x){
        if(b < x)b = x;
        if(a < b)swap(a, b);
    }

    bool empty(){
        return (a == -inf);
    }

    void clear(){
        a = -inf;
        b = -inf;
    }

    ll size(){
        return (a != -inf) + (b != -inf);
    }

};

Set st[MAXN], c, S;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll ans = 0;

    int n;

    cin >> n;

    vector <int> a(n + 1);

    int Mx = 0;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        Mx = max(Mx, a[i]);
        cnt[a[i]]++;
    }


    for(int i = 1; i <= N; i++){
        pref[i] = pref[i - 1] + cnt[i];
        for(int j = 0; j < min(2, cnt[i]); j++)c.insert(i);
        st[i] = c;
    }

    int le, ri, val;
    ll kol = 0, X = 0;

    for(ll y = 2; y <= N; y++){
        int l = 0, r = N;

        kol = 0;
        le = 0;

        while(le <= N){
            ri = min(N, le + (int)y - 1);
            kol += (le / y) * (pref[ri] - (le ? pref[le - 1] : 0));
            le += y;
        }

        r = min((ll)N, kol);

        while(l < r){
            int c = (l + r + 1) >> 1;
            if(c * 2 <= Mx){
                kol = 0, X = 0;
                le = 0;
                while(le <= N){
                    ri = min(N, le + (int)y - 1);
                    kol += (le / y) * (pref[ri] - (le ? pref[le - 1] : 0));
                    if(!st[ri].empty()){
                        val = st[ri].a;
                        if(val >= 2 * c)X = max(X, val % y);
                    }
                    le += y;
                }

                kol -= (2 * c) / y;

                if(X < (2 * c) % y)kol--;

                if(kol >= c){
                    l = c;
                    continue;
                }
            }

            S.clear();

            kol = -2 * (c / y);

            le = 0;
            while(le <= N){
                ri = min(N, le + (int)y - 1);
                kol += (le / y) * (pref[ri] - (le ? pref[le - 1] : 0));
                if(!st[ri].empty()){
                    val = st[ri].a;
                    if(val >= c && val >= le)S.insert(val % y);

                    if(st[ri].size() == 2){
                        val = st[ri].b;
                        if(val >= c && val >= le)S.insert(val % y);
                    }
                }
                le += y;
            }

            if(S.size() != 2){
                r = c - 1;
                continue;
            }

            if(S.a < c % y)kol--;
            if(S.b < c % y)kol--;

            if(kol >= c){
                l = c;
            }else r = c - 1;
        }

        if(l > 1){
            ans = max(ans, y * l);
        }
    }

    cout << ans << "\n";

    return 0;
}