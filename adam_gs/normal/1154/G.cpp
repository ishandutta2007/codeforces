        #pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
    #pragma GCC option("arch=native","tune=native","no-zero-upper") 
    #pragma GCC target("avx2","popcnt","rdrnd","bmi2")
        #include<bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        typedef long double ld;
        #define rep(a, b) for(int a = 0; a < (b); ++a)
        #define pb push_back
        #define st first
        #define nd second
        #define all(a) a.begin(), a.end()
        #define lg(a) (31-__builtin_clz(a))
        const ll LIM=1e6+7, MAXA=1e7+7, INF=1e18+7;
        int cp[MAXA], mi[MAXA][2], jaki[MAXA][2], liczba, nr;
        vector<int>pi;
        vector<pair<int,int>>dzielniki;
        void znajdz(int x, int ind) {
                if(ind==dzielniki.size()) {
                        if(!mi[x][0]) {
                                mi[x][0]=liczba;
                                jaki[x][0]=nr;
                        } else if(liczba<=mi[x][0]) {
                                jaki[x][1]=jaki[x][0];
                                mi[x][1]=mi[x][0];
                                mi[x][0]=liczba;
                                jaki[x][0]=nr;
                        } else if(liczba<=mi[x][1] || !mi[x][1]) {
                                mi[x][1]=liczba;
                                jaki[x][1]=nr;
                        }
                        return;
                }
                for(int i=0; i<=dzielniki[ind].nd; ++i) {
                        znajdz(x, ind+1);
                        x*=dzielniki[ind].st;
                }
        }
        int main() {
                ios_base::sync_with_stdio(0); cin.tie(0);
                for(int i=2; i*i<=MAXA; ++i) {
                        if(cp[i]) continue;
                        pi.pb(i);
                        for(int j=2*i; j<MAXA; j+=i) cp[j]=1;
                }
                int n;
                cin >> n;
                rep(i, n) {
                        int a;
                        cin >> a;
                        nr=i;
                        liczba=a;
                        dzielniki.clear();
                        for(auto j : pi) {
                                if(!cp[a]) break;
                                if(j*j>a) break;
                                int l=0;
                                while(a%j==0) {
                                        a/=j;
                                        ++l;
                                }
                                if(l) dzielniki.pb({j, l});
                        }
                        if(a>1) {
                                dzielniki.pb({a, 1});
                        }
                        znajdz(1, 0);
                }
                ll ans=INF, p1, p2;
                for(int i=1; i<MAXA; ++i) {
                        if(!mi[i][1]) continue;
                        ll x=mi[i][0], y=mi[i][1];
                        if(ans>x*y/i) {
                                ans=x*y/i;
                                p1=jaki[i][0];
                                p2=jaki[i][1];
                        }
                }
                cout << min(p1, p2)+1 << " " << max(p1, p2)+1 << '\n';
        }