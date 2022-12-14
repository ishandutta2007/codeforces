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

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("joseph.in", "r", stdin);
    //freopen("joseph.out", "w", stdout);
    ll n;
    cin >> n;
    vector <ll> a(n);
    ll kol = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0)kol++;
    }
    if(kol % 2 == 0){
        kol = 0;
        for(int i = 0; i < n; i++)if(a[i] == 0)kol++;
        if(kol >= 1){
            ll last = 0;
            ll kolnul = 0;
            for(int i = 1; i <= n; i++)if(!a[i - 1]){
                last = i;
                kolnul++;
            }
            for(int i = 1; i <= n; i++)if(last != i && a[i - 1] == 0)cout << "1 " << i << " " << last << "\n";
            if(kolnul == n)return 0;
            cout << "2 " << last << "\n";
            last = 0;
            for(int i = 1; i <= n; i++)if(a[i - 1])last = i;
            for(int i = 1; i <= n; i++)if(a[i - 1] && last != i)cout << "1 " << i << " " << last << "\n";
            return 0;
        }else{
            for(int i = 2; i <= n; i++)cout << "1 " << i << " 1\n";
            return 0;
        }
    }
    else{
        kol = 0;
        for(int i = 0; i < n; i++)if(a[i] == 0)kol++;
        if(kol >= 1){
            ll last = 0;
            for(int i = 1; i <= n; i++)if(!a[i - 1]){
                last = i;
                break;
            }
            for(int i = 1; i <= n; i++)if(last != i && a[i - 1] == 0)cout << "1 " << i << " " << last << "\n";
            ll pos = 0;
            for(int i = 1; i <= n; i++)if(a[i - 1] < 0){
                if(!pos)pos = i;
                else if(a[pos - 1] < a[i - 1])pos = i;
            }
            cout << "1 " << pos << " " << last << "\n";
            if(kol + 1 < n)cout << "2 " << last << "\n";
            last = 0;
            for(int i = 1; i <= n; i++)if(a[i - 1] && i != pos)last = i;
            for(int i = 1; i <= n; i++)if(a[i - 1] && last != i && i != pos)cout << "1 " << i << " " << last << "\n";
            return 0;
        }else{
             ll pos = 0;
            for(int i = 1; i <= n; i++)if(a[i - 1] < 0){
                if(!pos)pos = i;
                else if(a[pos - 1] < a[i - 1])pos = i;
            }
            if(pos == 1){
                for(int i = 3; i <= n; i++)cout << "1 " << i << " 2\n";
                cout << "2 1\n";
                return 0;
            }else{
                cout << "2 " << pos << "\n";
                for(int i = 2; i <= n; i++)if(pos != i)cout << "1 " << i << " 1\n";
                return 0;
            }
        }
    }
    return 0;
}