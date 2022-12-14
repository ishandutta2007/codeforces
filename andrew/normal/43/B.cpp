#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
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
    string s1, s2;
    vector <ll> pod(200);
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.size(); ++i)pod[s1[i]]++;
    for(int i = 0; i < s2.size(); ++i)if(s2[i] != ' '){
        if(!pod[s2[i]])vout("NO");
        pod[s2[i]]--;
    }
    vout("YES");
    return 0;
}