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

ll bp(ll a,ll n){
    ll res = 1;
    while(n){
        if(n % 2)res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

map <string, set <ll> > mp;

string a[MAXN];

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ll m = a[i].size();
        for(int j = 0; j < m; j++){
            string sb;
            for(int i1 = j; i1 < m; i1++){
                sb += a[i][i1];
                mp[sb].insert(i);
            }
        }
    }

    ll q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        if(mp.find(s) == mp.end()){
            cout << "0 -\n";
            continue;
        }
        cout << mp[s].size() << " ";
        cout << a[*mp[s].begin()] << "\n";
    }

    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}