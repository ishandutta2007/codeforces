#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
#define endl "\n"
#define m_p make_pair
#define all(x) x.begin(),x.end()
#define ull unsigned long long

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

vector <ull> v[MAXN],va;
string s1,s2,s3;
multiset <ull> s;
char cc;
ll i;
ull a[MAXN],b[MAXN],a1,b1,c1,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for(i = 0; i < n; i++)cin >> a[i];
        sort(a, a + n);
    for(j = 0; j < n; j++){
        s.clear();
        for(i = 0; i < n; i++)s.insert(a[i]);
        va.clear();
        x = a[j];
        va.p_b(a[j]);
        s.erase(s.find(a[j]));
        while(!s.empty()){
            if(x % 3 == 0){
                if(s.find(x / 3) != s.end()){
                    va.p_b(x / 3);
                    s.erase(s.find(x / 3));
                    x /= 3;
                    continue;
                }
            }
            if(s.find(x * 2) == s.end())break;
            va.p_b(x * 2);
            s.erase(s.find(x * 2));
            x *= 2;
        }
        if(va.size() != n)continue;
        for(i = 0; i < va.size(); i++)cout << va[i] << " ";
        return 0;
    }
    vout(-1);
    return 0;
}