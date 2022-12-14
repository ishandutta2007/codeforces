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

ll pd[MAXN];
vector<ll> pod[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    vector <ll> a(n + 1);
    set <ll> s;
    ll sc = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(a[i]);
        pd[a[i]]++;
        if(pd[a[i]] > 1)s.erase(a[i]);
        if(pd[a[i]] > 2)sc = 1;
    }
    ll kek = s.size();
    vector <char> ans(n + 1);
    ll s1 = kek / 2, s2 = kek - kek / 2;
    if(s1 == s2){
        ll kol = 0;
        for(int i = 1; i <= n; i++)if(pd[a[i]] == 1){
            if(kol == 0)ans[i] = 'A'; else ans[i] = 'B';
            kol = 1 - kol;
        }else{
            ans[i] = 'B';
        }
        cout << "YES\n";
        for(int i = 1; i <= n; i++)cout << ans[i];
        cout << "\n";
        return 0;
    }else{
        if(s.size() == n || !sc)vout("NO");
        ll kol = 0, kol1 = 1;
        for(int i = 1; i <= n; i++)if(pd[a[i]] == 1){
            if(kol == 0)ans[i] = 'A'; else ans[i] = 'B';
            kol = 1 - kol;
        }else{
            if(pd[a[i]] > 2){
                if(kol1)ans[i] = 'B';else ans[i] = 'A';
                kol1 = 0;
            }else{
                ans[i] = 'A';
            }
        }
        cout << "YES\n";
        for(int i = 1; i <= n; i++)cout << ans[i];
        cout << "\n";
        return 0;
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}