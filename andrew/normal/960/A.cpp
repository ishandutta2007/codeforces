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
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1;
    n = s1.size();
    int la = s1.find('a'), ra = s1.rfind('a');
    int lb = s1.find('b'), rb = s1.rfind('b');
    int lc = s1.find('c'), rc = s1.rfind('c');
    if(la == -1 or lb == -1 or lc == -1)vout("NO");
    if(ra + 1 == lb && rb + 1 == lc){
        for(i = 0; i < n; i++){
            if(s1[i] == 'a')a1++; else if(s1[i] == 'b')b1++; else {
                a1 --;
                b1--;
            }
        }
        if(a1 == 0 or b1 == 0)vout("YES");
    }
    vout("NO");
    return 0;
}