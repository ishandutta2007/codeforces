    #include <bits/stdc++.h>

    #define fi first
    #define se second
    #define p_b push_back
    #define pll pair<ll,ll>
    #define m_p make_pair
    #define all(x) x.begin(),x.end()
    #define ld long double

    using namespace std;
    typedef long long ll;
    const ll MAXN = 1123456;

    template <typename T>
    T sqr(T x){
        return x * x;
    }

    template <typename T>
    void vout(T s){
        cout << s << endl;
        exit(0);
    }

    ll bp(ll a,ll n){
        ll res = 1;
        while(n){
            if(n % 2)res *= a;
            a *= a;
            n >>= 1;
        }
        return res;
    }

    vector <pll> v[2];

    ll what(ll x, ll y){
        cout << x << " " << y << endl;
        string a;
        cin >> a;
        if(a == "black")return 1;
        return 0;
    }

    int main(){
        ios_base :: sync_with_stdio(0);
        cin.tie(0);
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);

        ll n;
        cin >> n;
        int wht = what(0, 0);
        v[wht].p_b({0, 0});
        if(n == 1){
            cout << "0 1 1 0" << endl;
            exit(0);
        }
        ll l = 1, r = 1e9;
        ll l1 = 1, r1 = 1e9;
        for(int i = 2; i <= n; i++){
            ll c = (l + r) >> 1, c1 = (l1 + r1) >> 1;
            int k = what(c, c1);
            if(k == wht){
                v[wht].p_b({c, c1});
                l = c;
                l1 = c1;
            }else{
                r = c, r1 = c1;
            }
        }
        ll mxx = 0, mxy = 0;
        if(v[wht].size() == 1){
            cout << "0 1 1 0" << endl;
            exit(0);
        }
        for(auto i : v[wht])if(i.fi > mxx){
            mxx = i.fi, mxy = i.se;
        }
        ll con = 1e9;
        cout << 0 << " " << mxy << " " << con << " " << mxy + 1 << endl;
        cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
        return 0;
    }