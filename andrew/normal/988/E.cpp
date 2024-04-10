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
map <ll, ll> mp;
set <ll> s[26];
char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s1;
    n = s1.size();
    ans = 1e9;
    for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)if(((s1[i] - '0') * 10 + s1[j] - '0') % 25 == 0 && i != j){
        s2 = s1;
        bool fl = 0;
        ll l = i, r = j;
        sc = 0;
        if(r == 0 && s2.size() != 2){
            for(k = 1; k < s2.size(); ++k)if(l != k && s2[k] != '0')break;
            if(k == s2.size())fl = 1;
            else{
                while(k > 1){
                    swap(s2[k], s2[k - 1]);
                    sc++;
                    k--;
                    if(k == l)l++;
                }
            }
        }
        if(fl)continue;
        while(r < n - 1){
            swap(s2[r], s2[r + 1]);
            r++;
            if(r == l)l--;
            sc++;
        }
        if(l == 0 && l != n - 2){
            for(k = 1; k < s2.size(); ++k)if(r != k && s2[k] != '0')break;
            if(k == s2.size())fl = 1;
            else{
                while(k > 1){
                    swap(s2[k], s2[k - 1]);
                    sc++;
                    k--;
                    if(k == r)r++;
                }
            }
        }
        if(fl)continue;
        while(l < n - 2){
            swap(s2[l], s2[l + 1]);
            l++;
            sc++;
        }
        ans = min(ans, sc);
    }
    if(ans == 1e9)vout(-1);
    vout(ans);
    return 0;
}