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

ll o[111111], st = 0;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        o[++st] = 1;
            while (st > 1 && o[st] == o[st - 1]) {
                o[st - 1]++;
                st--;

            }
    }

    for (int i = 1; i <= st; i++) cout << o[i] << " ";
    return 0;
}