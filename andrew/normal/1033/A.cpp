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
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
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

bool fl[1001][1001];
queue <pll> q;
bool f[1001][1001];
ll n;

void add(ll x, ll y){
    if(y < 1 || x < 1 || y > n || x > n || f[x][y] || fl[x][y])return;
    f[x][y] = 1;
    q.push({x, y});
}

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll ax, bx, cx;
    ll ay, by, cy;
    cin >> ax >> ay;
    cin >> bx >> by;
    cin >> cx >> cy;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)if(i == ax || j == ay || abs(i - ax) == abs(j - ay))fl[i][j] = 1;


    add(bx, by);

    while(!q.empty()){
        pll xe = q.front();
        q.pop();
        add(xe.fi + 1, xe.se - 1);
        add(xe.fi + 1, xe.se);
        add(xe.fi + 1, xe.se + 1);

        add(xe.fi - 1, xe.se - 1);
        add(xe.fi - 1, xe.se);
        add(xe.fi - 1, xe.se + 1);

        add(xe.fi, xe.se + 1);
        add(xe.fi, xe.se - 1);
    }
    if(f[cx][cy])vout("YES");
    vout("NO");
    cerr << "Time execute: " << clock() / (double)CLOCKS_PER_SEC << " sec" << endl;
    return 0;
}