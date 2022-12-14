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
set <ll> s;
char cc;
vector <ll> psl[MAXN];
ll kol;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
set <ll> zk,nzk;
set <ll> :: iterator it,it1;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1;
    n = s1.size();
    for(i = 0; i < n; i++)if(s1[i] == '0'){
        if(nzk.size()){
            it = nzk.begin();
            x = *it;
            psl[x].p_b(i + 1);
            nzk.erase(it);
            zk.insert(x);
        }else {
            zk.insert(kol);
            psl[kol].p_b(i + 1);
            kol++;
        }
    }else {
        //cout << zk.size() << endl;
        if(zk.empty())vout(-1);
        it = zk.begin();
        x = *it;
        psl[x].p_b(i + 1);
        zk.erase(it);
        nzk.insert(x);
    }
    if(nzk.size())vout(-1);
    cout << kol << endl;
    for(i = 0; i < kol; i++){
        ll nn = psl[i].size();
        cout << nn;
        for(j = 0; j < nn; j++)cout << " " << psl[i][j];
        cout << endl;
    }
    return 0;
}