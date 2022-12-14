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



int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("advertisement.in","r",stdin);
    //freopen("advertisement.out","w",stdout);

    ll x;
    cin >> x;
    if(x == 1)vout(-1);
    cout << x << " " << x << "\n";

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}