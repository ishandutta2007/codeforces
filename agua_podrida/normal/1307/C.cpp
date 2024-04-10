#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(ll i = a; i <= b; i++)
#define REPR(i,a,b) for(int i = a; i >= b; i--)
#define F first
#define S second
#define INF 1e17
#define todo(v) v.begin(),v.end()
#define eps 0.000000000001
#define mod 998244353

void a(){
    int n,d;
    cin>>n>>d;
    vi a(n);
    F0(i,n) cin>>a[i];
    int i = 1;
    while(i < n and i <= d){
        while(i <= d and a[i] > 0){
            a[0]++;
            a[i]--;
            d -= i;
        }
        i++;
    }
    cout<<a[0]<<'\n';
}

void b(){
    int n;
    ll x;
    cin>>n>>x;
    vll a(n);
    F0(i,n) cin>>a[i];
    int i = 0;
    while(i < n and a[i] != x) i++;
    if(i < n){
        cout<<"1\n";
        return;
    }
    ll maxHop = 0;
    F0(i,n) maxi(maxHop,a[i]);
    ll res = (x+maxHop-1)/maxHop;
    maxi(res,(ll)2);
    cout<<res<<'\n';
}

void c(){
    string s;
    cin>>s;
    int n = s.size();
    vi a(n+1);
    F0(i,n) a[i+1] = (int) s[i] - (int) 'a';
    vll ap1(26);
    vvll ap2(26,vll(26));
    F1(i,n){
        F0(c,26){
            ap2[c][a[i]] += ap1[c];
        }
        ap1[a[i]]++;
    }
    ll res = 0;
    F0(i,26) maxi(res,ap1[i]);
    F0(i,26) F0(j,26) maxi(res,ap2[i][j]);
    cout<<res<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("../output.txt","w",stdout);
    c();
    return 0;
}