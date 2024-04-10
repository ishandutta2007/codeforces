#include <bits/stdc++.h>

#define fi first
#define se second
#define p_b push_back
#define pll pair<ll,ll>
//#define endl "\n"
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


string s1,s2,s3;
multiset <ll> s;

char cc;
ll a[MAXN],b[MAXN],c,a1,b1,c1,i,j,n,m,k,ans,sc,x;
ll q1 = 2;
ll ke[4 * MAXN];
set <ll> p[4 * MAXN];
vector <pll> q;
vector <ll> v1, va;
ll hd[4 * MAXN][2];
ll md = 1e18;
set <ll> :: iterator it;
void modify(ll v, ll tl, ll tr, ll pos, ll number, ll k){
    if(tl == tr){
            if(k == -1)p[v].erase(number); else
            p[v].insert(number);
            ke[v] += k;
            return;
    }
    ll tm = (tl + tr) >> 1;
    if(!hd[v][0])hd[v][0] = q1++;
    if(!hd[v][1])hd[v][1] = q1++;
    if(pos <= tm)modify(hd[v][0], tl, tm, pos, number, k); else modify(hd[v][1], tm + 1, tr, pos, number, k);
    ke[v] = max(ke[hd[v][0]], ke[hd[v][1]]);
}
void get(ll v, ll tl, ll tr){
    if(tl == tr){
        ll xe = tl * 2;
        modify(1, 1, md, tl, *(p[v].begin()), -1);
        ll pz = *(p[v].begin());
        modify(1, 1, md, tl, *(p[v].begin()), -1);
        modify(1, 1, md, xe, pz, 1);
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(!hd[v][0])hd[v][0] = q1++;
    if(!hd[v][1])hd[v][1] = q1++;
    if(ke[hd[v][0]] > 1)get(hd[v][0], tl, tm); else get(hd[v][1], tm + 1, tr);
    ke[v] = max(ke[hd[v][0]], ke[hd[v][1]]);
}
void build(ll v, ll tl, ll tr){
    if(tl == tr){
        ll xe = *p[v].begin();
        q.p_b(m_p(xe, tl));
        return;
    }
    ll tm = (tl + tr) >> 1;
    if(!hd[v][0])hd[v][0] = q1++;
    if(!hd[v][1])hd[v][1] = q1++;
    if(ke[hd[v][0]] > 0)build(hd[v][0], tl, tm);
    if(ke[hd[v][1]] > 0)build(hd[v][1], tm + 1, tr);
    return;
}
int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
   cin >> n;
   for(i = 1; i <= n; i++)cin >> a[i];
   for(i = 1; i <= n; i++)modify(1, 1, md, a[i], i, 1);
   while(ke[1] > 1)get(1, 1, md);
   build(1, 1, md);
   cout << q.size() << endl;
   sort(all(q));
   for(i = 0; i < q.size(); i++)cout << q[i].se << " ";
    return 0;
}