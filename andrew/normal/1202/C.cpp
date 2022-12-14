#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

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
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
const ll MAXN = 1123456;
const ll N = 2e5;
mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> void vout(T s){cout << s << endl;exit(0);}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        ll n = s.size();
        vector <pll> a(n + 1);
        a[0] = {0, 0};
        ll lx, rx, ly, ry;
        lx = rx = ly = ry = 0;
        for(int i = 1; i <= n; i++){
            a[i] = a[i - 1];
            if(s[i - 1] == 'S'){
                a[i].fi--;
            }
            if(s[i - 1] == 'W'){
                a[i].fi++;
            }
            if(s[i - 1] == 'A'){
                a[i].se--;
            }
            if(s[i - 1] == 'D'){
                a[i].se++;
            }
            lx = min(lx, a[i].fi);
            rx = max(rx, a[i].fi);
            ly = min(ly, a[i].se);
            ry = max(ry, a[i].se);
        }

        vector <ll> MinXS(n + 1), MaxXS(n + 1), MinYS(n + 1), MaxYS(n + 1);

        for(int i = n; i > 0; i--){
            MinXS[i] = a[i].fi;
            MaxXS[i] = a[i].fi;
            MinYS[i] = a[i].se;
            MaxYS[i] = a[i].se;
            if(i < n){
                MinXS[i] = min(MinXS[i], MinXS[i + 1]);
                MinYS[i] = min(MinYS[i], MinYS[i + 1]);
                MaxXS[i] = max(MaxXS[i], MaxXS[i + 1]);
                MaxYS[i] = max(MaxYS[i], MaxYS[i + 1]);
            }
        }

        bool Fx, Fy;
        Fx = Fy = 0;

        bool MxFX, MnFX, MxFY, MnFY;
        MxFX = MnFX = MxFY = MnFY = 0;

        if(lx + 1 == rx)Fx = 1;
        if(ly + 1 == ry)Fy = 1;

        bool Cx, Cy;
        Cx = Cy = 0;

        if(!lx)MnFX = 1;
        if(!rx)MxFX = 1;
        if(!ly)MnFY = 1;
        if(!ry)MxFY = 1;

        for(int i = 1; i <= n; i++){

            if(s[i - 1] == 'S'){
                if(Fx || MnFX)continue;
                if(a[i].fi == lx){
                    if((rx != lx && i == n) || (i != n && MaxXS[i + 1] < rx)){
                        lx++;
                        Fx = 1;
                        Cx = 1;
                    }
                }
            }

            if(s[i - 1] == 'W'){
                if(Fx || MxFX)continue;
                if(a[i].fi == rx){
                    if((rx != lx && i == n) || (i != n && MinXS[i + 1] > lx)){
                        rx--;
                        Fx = 1;
                        Cx = 1;
                    }
                }
            }

            if(s[i - 1] == 'A'){
                if(Fy || MnFY)continue;
                if(a[i].se == ly){
                    if((ry != ly && i == n) || (i != n && MaxYS[i + 1] < ry)){
                        ly++;
                        Fy = 1;
                        Cy = 1;
                    }
                }
            }

            if(s[i - 1] == 'D'){
                if(Fy || MxFY)continue;
                if(a[i].se == ry){
                    if((ry != ly && i == n) || (i != n && MinYS[i + 1] > ly)){
                        ry--;
                        Fy = 1;
                        Cy = 1;
                    }
                }
            }

            if(a[i].fi >= rx)MxFX = 1;
            if(a[i].fi <= lx)MnFX = 1;
            if(a[i].se >= ry)MxFY = 1;
            if(a[i].se <= ly)MnFY = 1;

        }

        if(Cx && Cy){
            if((rx - lx + 1) * (ry - ly + 2) < (ry - ly + 1) * (rx - lx + 2)){
                ry++;
            }else rx++;
        }

        cout << (rx - lx + 1) * (ry - ly + 1) << "\n";

    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}