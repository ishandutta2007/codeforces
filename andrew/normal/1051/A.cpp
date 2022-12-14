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

ll group[MAXN];
ll kol[3];
char cc[3];
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll n;
    cin >> n;
    cc[0] = '1';
    cc[1] = 'A';
    cc[2] = 'a';
    for(int i = 'A'; i <= 'Z'; i++)group[i] = 1;
    for(int i = 'a'; i <= 'z'; i++)group[i] = 2;
    while(n--){
        string s;
        cin >> s;
        ll a, b, c;
        for(int i = 0; i < 3; i++)kol[i] = 0;
        ll m = s.size();
        for(int i = 0; i < m; i++)kol[group[s[i]]]++;
        ll count__ = 0;
        vector <char> cec;
        for(int i = 0; i < 3; i++)if(kol[i] == 0){
            count__++;
            cec.p_b(cc[i]);
        }
        for(int i = 0; i < m; i++){
            bool fl = 0;
            for(int j = 0; j < count__; j++)if(kol[group[s[i + j]]] < 2)fl = 1;

            if(fl)continue;
            for(int j = 0; j < count__; j++)s[i + j] = cec[j];
            break;
        }
        cout << s << "\n";
    }
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}