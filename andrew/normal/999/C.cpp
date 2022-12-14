#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define m_p make_pair
#define next ku
#define all(x) x.begin(),x.end()

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
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    set <ll> ans[30], del;
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)ans[s[i] - 'a'].insert(i);
    for(int i = 0; i < k; i++){
                         for(int j = 0; j < 26; j++){
                                                  if(ans[j].empty())continue;
                                                  set <ll> :: iterator it = ans[j].begin();
                                                  del.insert(*it);
                                                  ans[j].erase(it);
                                                  break;
                         }
    }
    string maybe;
    for(int i = 0; i < n; i++)if(del.find(i) == del.end())maybe += s[i];
    return cout << maybe << "\n", 0;
 }