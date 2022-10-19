#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vbool;
int mod = 1000000007;

typedef unsigned int uint;
template<class C> void mini(C&a, C b){a=min(a,b);}
template<class C> void maxi(C&a, C b){a=max(a,b);}
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define forall(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define F0(i,n) for(int i = 0; i < n; i++)
#define F1(i,n) for(int (i) = 1; i <= n; i++)
#define F0R(i,n) for(int (i) = n-1; i >= 0; i--)
#define F1R(i,n) for(int (i) = n; i >= 1; i--)
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define F first
#define S second
#define INF 100000000
#define todo(v) v.begin(),v.end()

void a(){
    int n;
    cin>>n;
    if(n%2 == 0){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vi res(2*n);
    int i = 0;
    while(i < n/2){
        res[2*i] = 4*i+1;
        res[2*i+n] = 4*i+2;
        res[2*i+1] = 4*i+4;
        res[2*i+1+n] = 4*i+3;
        i++;
    }
    res[n-1] = 2*n-1;
    res[2*n-1] = 2*n;
    F0(i,2*n) cout<<res[i]<<' ';
    cout<<'\n';
}

int main(){
    a();
    return 0;
}