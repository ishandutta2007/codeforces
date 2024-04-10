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

vector <ll> v[MAXN],va;
string s1,s2,s3;
set <ll> s;
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //srand(time(0));
    n = 0;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   // cout << 0 << endl;
    //cin >> s1;
    for(i = 0; i < 5; i++){
        n = rand() % 10;
        cout << n << endl;
        cin >> s1;
        //if(sc == 5)vout("normal");
        int kek = s1.find("touch");
        if(kek != -1)vout("normal");
        kek = s1.find("cool");
        if(kek != -1)vout("normal");
         kek = s1.find("think");
        if(kek != -1)vout("normal");
         kek = s1.find("cool");
        if(kek != -1)vout("normal");
         kek = s1.find("great");
        if(kek != -1)vout("normal");
         kek = s1.find("bad");
        if(kek != -1)vout("normal");
    }
    vout("grumpy");
    return 0;
}