#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
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

ll f[MAXN], f1[MAXN], n;

ll updatef(ll x, ll val){
    for(int i = x; i <= n; i += i & -i)f[i] += val;
}

ll updatef1(ll x, ll val){
    for(int i = x; i <= n; i += i & -i)f1[i] += val;
}

ll getf(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += f[i];
    return res;
}

ll getf1(ll x){
    ll res = 0;
    for(int i = x; i > 0; i -= i & -i)res += f1[i];
    return res;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll m;
    cin >> n >> m;
    ll s = 0;
    vector <ll> a(n + 1);
    set <ll> st;

    ll mn = 1e18;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
        st.insert(i);
        updatef(i, a[i]);
        updatef1(i, 1);
        mn = min(mn, a[i]);
    }

    ll ans = 0;
    ll pos = 1;
    while(m >= mn){

        if(a[pos] > m){
            s -= a[pos];
            st.erase(pos);
            updatef(pos, -a[pos]);
            updatef1(pos, -1);
            pos = pos % n + 1;
            if(getf1(n) - getf1(pos - 1) == 0)pos = *st.begin();
            ll l = pos, r = n;
            while(l < r){
                ll c = (l + r) >> 1;
                if(!(getf1(c) - getf1(pos - 1)))l = c + 1; else r = c;
            }
            pos = l;
        }else
        if(m < s){
            if(getf(n) - getf(pos - 1) < m){
                m -= getf(n) - getf(pos - 1);
                ans += getf1(n) - getf1(pos - 1);
                pos = *st.begin();
                continue;
            }
            ll l = pos, r = n;
            while(l < r){
                ll c = (l + r) >> 1;
                if(c == l)c++;
                if(getf(c) - getf(pos - 1) > m)r = c - 1; else l = c;
            }
            ans += getf1(l) - getf1(pos - 1);
            m -= getf(l) - getf(pos - 1);
            pos = l % n + 1;

            if(getf1(n) - getf1(pos - 1) == 0)pos = *st.begin();
            l = pos, r = n;
            while(l < r){
                ll c = (l + r) >> 1;
                if(!(getf1(c) - getf1(pos - 1)))l = c + 1; else r = c;
            }
            pos = l;
        }else
        {
            ans += (m / s) * getf1(n);
            m %= s;
        }
    }
    cout << ans << "\n";
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}