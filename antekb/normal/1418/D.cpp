//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>

#define st first
#define nd second
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

using namespace std;

///~~~~~~~~~~~~~~~~~~~~~~~~~~

void debug(){cerr<<"\n";}
template <typename H, typename... T>
void debug(H h, T... t) {cerr<<h; if (sizeof...(t)) cerr << ", "; debug(t...);}
#define deb(x...) cerr<<#x<<" = ";debug(x);

///~~~~~~~~~~~~~~~~~~~~~~~~~

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N=2e5+5, INF=2e9+5, mod=1e9+7;
set<int> S1, S2;
multiset<int> S;
int get_low(int t){
    return -*(S2.upper_bound(-t));
}
int get_high(int t){
    return *(S1.upper_bound(t));
}
void add(int x){
        int a=get_high(x);
        int b=get_low(x);
        if(b!=0)S.insert(x-b);
        if(a!=INF)S.insert(a-x);
        if(a!=INF && b!=0){
            S.erase(S.find(a-b));
        }
    S1.insert(x);
    S2.insert(-x);
}
void del(int x){
    int a=get_high(x);
    int b=get_low(x);
    if(b!=0)S.erase(S.find(x-b));
    if(a!=INF)S.erase(S.find(a-x));
    if(a!=INF && b!=0){
        S.insert((a-b));
    }
    S1.erase(S1.find(x));
    S2.erase(S2.find(-x));
}
int get(){
    if(S1.size()<=2)return 0;
    int a=*(S1.begin());
    int b=-*(S2.begin());
    int c=*(S.crbegin());
    return b-a-c;
}
int main(){
    int n, m;
    cin>>n>>m;
    S1.insert(INF);
    S2.insert(0);
    while(n--){int x; cin>>x; add(x);}
    cout<<get()<<"\n";
    while(m--){
        int t, x;
        cin>>t>>x;
        if(t==0){
            del(x);
        }
        else{
            add(x);
        }
        cout<<get()<<"\n";
    }
}