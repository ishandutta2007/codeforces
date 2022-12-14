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
char cc[101][101];
ll a[MAXN],b[MAXN],c[MAXN],a1,b1,c1,i,j,n,m,k,ans,sc,x;
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for(i = 1; i <= 4; i++)
        for(j = 1; j <= n; j++)cc[i][j] = '.';
    if(k % 2 == 1){
      if(k >= n){
            for(i = 2; i < 4; i++)
                for(j = 2; j < n; j++)if(i % 2 == j % 2)cc[i][j] = '#';
            k -= n - 2;
            if(k != 0){
                cc[3][2] = '#';
                cc[3][n - 1] = '#';
                k -= 2;
            }

            for(i = 2; i < 4; i++)
                    for(j = 2; j < n; j++)if(k > 0 && i % 2 != j % 2 && cc[i][j] == '.')cc[i][j] = '#', k--;
            }else{
                ll ku = (n + 1) / 2;
                ll l = ku - k / 2, r = ku + k / 2;
                for(i = 2; i < 4; i++)
                    for(j = l; j <= r; j++)if(i % 2 == j % 2)cc[i][j] = '#';
            }
    }else{
        j = 2;i = 2;
        while(k--){
            cc[i][j] = '#';
            i++;
            if(i == 4){
                i = 2;
                j++;
            }
        }
    }
    cout << "YES\n";
    for(i = 1; i <= 4; i++){
        for(j = 1; j <= n; j++)cout << cc[i][j];
        cout << "\n";
    }
    return 0;
}