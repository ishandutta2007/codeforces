// Remember...

#include<bits/stdc++.h>

#define F first
#define S second
#define PB push_back
#define sz(s) int((s).size())
#define bit(n,k) (((n)>>(k))&1)

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const int maxn=2e5 + 10,mod=1e9+7;
const ll inf=3e18;

int a[maxn], b[maxn];
map<int,int> mp;

set<int> st;
int cnt[maxn];

void add(int a,int b){
    cout<<a<<" "<<b<<"\n";
}
void f(int u){
    if(--cnt[u]==0){
	st.insert(u);	
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie();

    int n,m; cin>>n>>m;

    int A,B; cin>>A>>B;
    for(int i=0;i<A;i++){
	cin>>a[i];	
    }
    for(int i=0;i<B;i++){
	cin>>b[i];
    }
    if(A > m-1 || B>n-1){
	return cout<<"No\n",0;
    }
    cout<<"Yes\n";
    
    while(A<m-1){
	a[A++]=n;
    }
    while(B<n-1){
	b[B++]=n+m;
    }

    for(int i=1;i<=n+m;i++)
	st.insert(i);
    for(int i=0;i<A;i++)
	st.erase(a[i]), cnt[a[i]]++;
    for(int i=0;i<B;i++)
	st.erase(b[i]), cnt[b[i]]++;
    int pta=0, ptb=0;

    for(int i=0;i<n+m-2;i++){
	int u=*st.begin();
	st.erase(u);
	if(u>n){
	    add(u, a[pta]);
	    f(a[pta++]);	    
	}
	else{
	    add(u, b[ptb]);
	    f(b[ptb++]);
	}	    
    }
    add(*st.begin(), *(++st.begin()));
    return 0;
}
// Deathly mistakes:
//  * Read the problem carefully.
//  * Check maxn.
//  * Overflows.


// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")