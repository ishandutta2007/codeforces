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

ll kol[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char a, b, c;

    cin >> a >> b >> c;
    if(b == '>')kol[a - 'A']++; else kol[c - 'A']++;

    cin >> a >> b >> c;
    if(b == '>')kol[a - 'A']++; else kol[c - 'A']++;

    cin >> a >> b >> c;
    if(b == '>')kol[a - 'A']++; else kol[c - 'A']++;

    string res;
    for(int i = 0; i < 3; i++)if(kol[i] == 2){
        res += char(i + 'A');
        break;
    }

    for(int i = 0; i < 3; i++)if(kol[i] == 1){
        res += char(i + 'A');
        break;
    }

    for(int i = 0; i < 3; i++)if(kol[i] == 0){
        res += char(i + 'A');
        break;
    }

    if(res.size() != 3)vout("Impossible");
    reverse(all(res));
    vout(res);

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}