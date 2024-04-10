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

template <typename T> void vout(T s){
    cout << s << endl;
    exit(0);
}

vector <ll> v[MAXN];


int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;

    vector <ll> a(n + 1);
    vector <pll> b(n + 1);

    set <pll> s;

    vector <pll> ans;

    ll last = 0;

    for(int i = 1; i <= n; i++)cin >> a[i];

    for(int i = 1; i <= n; i++)if(a[i] > 1){
        if(!last)last = i;
        else if(a[last] > a[i])last = i;
    }

    if(!last)vout("NO");

    ll first = last;

    for(int i = 1; i <= n; i++){
        b[i].fi = a[i];
        b[i].se = i;
    }

    sort(b.begin() + 1, b.end());
    reverse(b.begin() + 1, b.end());
    if(b[2].fi == 1){

        if(b[1].fi < n - 1)vout("NO");
        cout << "YES 2\n";
        cout << n - 1 << "\n";
        for(int i = 2; i <= n; i++)cout << b[i].se << " " << b[1].se << "\n";
        return 0;
    }

    ll val = 0;
    bool f = 0;
    last = 0;
    for(int i = 1; i <= n; i++)if(b[i].fi > 1)last = i;
    swap(b[last], b[2]);
    for(int i = 2; i <= n; i++)if(b[i].fi > 1){
        ans.p_b({b[i].se, b[i - 1].se});
        val++;
        b[i - 1].fi--;
        b[i].fi--;
    }

    bool fl = 0;

    ll uk = 1;

    for(int i = 2; i <= n; i++)if(a[b[i].se] == 1){
        if(!fl){
            fl = 1;
            val++;
            ans.p_b({b[last].se, b[i].se});
            b[last].fi--;
        }else{
            if(!f)val++;
            f = 1;
            while(uk <= last && b[uk].fi == 0)uk++;
            if(uk > last)vout("NO");
            ans.p_b({b[uk].se, b[i].se});
            b[uk].fi--;
        }
    }

    cout << "YES " << val << "\n";
    cout << ans.size() << "\n";
    for(auto i : ans)cout << i.fi << " " << i.se << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}