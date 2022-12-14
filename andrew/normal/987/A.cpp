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

vector <ll> v[MAXN],va;
string s1,s2,s3;
map <string, string> mp;
map <string, ll> mp1;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    mp["yellow"] = "Mind";
    mp["red"] = "Reality";
    mp["orange"] = "Soul";
    mp["blue"] = "Space";
    mp["green"] = "Time";
    mp["purple"] = "Power";
    cin >> n;
    ans = 6 - n;
    cout << ans << "\n";
    while(n--){
        cin >> s1;
        mp1[s1] = 1;
    }
    map <string, string> :: iterator it = mp.begin();
    for(; it != mp.end(); ++it)if(mp1[it -> fi] == 0)cout << it -> se << "\n";
    return 0;
}