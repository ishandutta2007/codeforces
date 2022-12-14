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

ll n, m;
char cc[1011][1011];
char a[1011][1011];


bool add(ll y, ll x){
    if(y < 1 || x < 1 || y > n || x > m || cc[y][x] != '#')return 0;
    return 1;
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)cin >> cc[i][j];

        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)a[i][j] = '.';

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){

        bool fl = 0;
        for(int i1 = -1; i1 < 2; i1++)
        for(int j1 = -1; j1 < 2; j1++)if(i1 != 0 || j1 != 0){
            if(!add(i + i1, j + j1))fl = 1;
        }
        if(!fl){
                for(int i1 = -1; i1 < 2; i1++)
            for(int j1 = -1; j1 < 2; j1++)if(i1 != 0 || j1 != 0){
                a[i + i1][j + j1] = '#';
        }
        }
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)if(a[i][j] != cc[i][j])vout("NO");
    vout("YES");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}