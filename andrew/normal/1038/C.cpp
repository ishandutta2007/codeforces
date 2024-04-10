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

multiset <ll> s, s1;
ll sc, sc1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        sc += m;
        s.insert(m);
    }

    for(int i = 0; i < n; i++){
        cin >> m;
        sc1 += m;
        s1.insert(m);
    }

    ll sg = 0;
    ll a, b;
    a = b = 0;
    while(!s.empty() || !s1.empty()){
        if(sg == 0){
            if(s.empty()){s1.erase(--s1.end());sc1 -= m;}else{
                   ll val = *(--s.end());
                    if(s1.empty() || val > *(--s1.end())){
                        a += val;
                        s.erase(s.find(val));
                        sc -= val;
                    }else {sc1 -= *(--s1.end()); s1.erase(--s1.end());}
            }
        }else{
            if(s1.empty()){s.erase(--s.end());sc -= m;}else{
                   ll val = *(--s1.end());
                    if(s.empty() || val > *(--s.end())){
                        b += val;
                        s1.erase(s1.find(val));
                        sc1 -= val;
                    }else {sc -= *(--s.end());s.erase(--s.end());}
            }
        }
        sg = 1 - sg;
    }
    ll k = a - b;
    cout << k << endl;
    return 0;
}