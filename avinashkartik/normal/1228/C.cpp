    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define foo(i,a,n) for(ll i = (a); i <= n; i++)
    #define frr(i,a,n) for(ll i = (a); i >= n; i--)
    #define fr(i,n) for(ll i = n-1; i >= 0; i--)
    #define fo(i,n) for(ll i = 0; i < n; i++)
    #define newl cout<<"\n"
    #define pb push_back
    #define mp make_pair
    #define s second
    #define f first
     
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll,ll> pll;
    typedef vector<ll> vl;
    typedef vector<pll> vpll;
     
    const ll MOD=1e+9+7;
    const ll MAXN=1e+6+7;
    const ll INF=1e+18;
     
    //<<-----Declare Variable Here------->>//
    set<ll> prime; 
    ll n; 
    ll x;
    ll rr=1;
    ll cnt=0;
     
    //<<-----Implement Functions Here---->>//
    ll mult(ll a , ll b){return (a*b)%MOD;}
     
    void findPfact(ll n){
        while (n % 2 == 0)  { 
        	prime.insert(2);
            n/=2;
        } 
        for (ll i = 3; i <= sqrt(n); i = i + 2) { 
            while (n % i == 0)  {  
                prime.insert(i);  
                n = n/i;  
            }  
        }  
     
        if (n > 2) {
        	prime.insert(n);
     
        }
    }  
     
     
    ll fastexp(ll x, ll y){
    	ll res=1;
    	while(y){
    		if(y&1)res=mult(res,x);
     
    		y/=2;
    		x=mult(x,x);
    	}
    	return res;
    }
     
    void solve(){
    	findPfact(x);
    	for(auto p: prime){ 
    		ld p1=p;
    		while(n>=p1 && p1>=0){
    			cnt+=(n/p1);
    			rr=mult(rr,fastexp(p,cnt));
    			p1*=p;
    			cnt=0;
    		}
    	}
      
    }
     
     
    //<<-----Start of Main--------------->>//
     
    int main(){
    	fastio;
     
    	cin>>x>>n;
    	solve();
    	cout<<rr;
     
    }