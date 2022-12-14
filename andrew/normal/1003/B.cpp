#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
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
    ll n, a, b;
    string ans;
    cin >> a >> b >> n;
    char cc1 = '0', cc2 = '1';
    if(a < b){
        swap(a, b);
        swap(cc1, cc2);
    }
    for(int i = 0; i < a; i++)ans += cc1;
    if(n % 2)ans += cc2, b--, n--;
    while(n > 0){
        b--;
        for(int i = 1; i < ans.size(); i++){
            if(ans[i] == ans[i - 1] && ans[i] == cc1){
                string s2;
                s2 = s2 + cc2;
                ans.insert(i, s2);
                n -= 2;
                break;
            }
        }
    }
    while(b > 0){
        for(int i = 0; i < ans.size(); i++)if(ans[i] == cc2){
            string s2;
            s2 = s2 + cc2;
            ans.insert(i + 1, s2);
            break;
        }
        b--;
    }
    vout(ans);
    return 0;
}