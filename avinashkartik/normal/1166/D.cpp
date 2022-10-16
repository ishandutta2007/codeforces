    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma")
    #pragma GCC optimization ("unroll-loops")
    #include<bits/stdc++.h>
    //#include"debuglib.h"
     
    using namespace std;
     
    #define fastio ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define foo(i,a,n) for(ll i = (a); i <= n; i++)
    #define frr(i,a,n) for(ll i = (a); i >= n; i--)
    #define fr(i,n) for(ll i = n-1; i >= 0; i--)
    #define fo(i,n) for(ll i = 0; i < n; i++)
    #define all(x) (x).begin(),(x).end()
    #define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
    #define deb cerr<<"<----REACHED HERE---->\n"
    #define showvv(x) for(auto it: (x))cout<<it<<" ";newl;
    #define showaa(x,n) fo(i,n)cout<<x[i]<<" ";newl;
    #define readaa(x,n) fo(i,n)cin>>x[i];
    #define newl cout<<"\n"
    #define pb push_back
    #define mp make_pair
    #define s second
    #define f first
     
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll,ll> pll;
    typedef vector<ll> vll;
    typedef unordered_map<ll,ll> um;
    typedef vector<pll> vpll;
     
    const ll MOD=1e+9+7;
    const ll MAXN=1e+16;
    const ll INF=1e+18;
     
    //<<-----Declare Variable Here------->>//
    ll q, a, b, m, pow2[60]={};
    ll mark;
    ll upb,lob;
    vll v, help, res;
    //<<-----Implement Functions Here---->>//
    ll P(ll key){
    	return ((a+key)*pow2[mark-2]>=b)?1:0;
    }
     
    ll bs(ll L, ll R){
        while (L < R) {     // after the loop, l = r = x
     
          ll mid = (L + R) / 2;
          if (P(mid)) R = mid;
          else L = mid + 1;
        }
        return L;
    }
    /*This might not work if P(r)=0 (in this case the algorithm will return x=r), but you can easily extend your search range to r + 1 and artificially set P(r+1)=1 or you can just precheck for that situation.*/
     
     
     
     
    //<<-----Start of Main--------------->>//
     
    int main(){
    	fastio;
    		
    	pow2[0]=1;
    	foo(i,1,59)pow2[i]=pow2[i-1]*2;
     
    	cin>>q;
    	while(q--){
    		v.clear();help.clear();res.clear();
    		
    		cin>>a>>b>>m;v.pb(a);
    		if(a==b){cout<<1<<" "<<a<<"\n";continue;}
    		foo(i,2,59){
    			if(pow2[i-2]*(a+m)>MAXN)break;
    			v.pb(pow2[i-2]*(a+m));
    		}
    		//v.pb(INF);
    		//for(auto it: v)cout<<it<<" ";newl;
    		mark=lower_bound(all(v),b)-v.begin()+1;
    		upb=v[mark-1];lob=pow2[mark-2]*(a+1);
    		
    		//cout<<mark<<"-"<<lob<<" "<<upb;newl;
    		//lob=1;
    		if(lob<=b && b<=upb){
    			//cout<<"yo";
    			ll cnt=lower_bound(pow2,pow2+46,upb/(a+m))-pow2+2;
    			ll fact=bs(1,m)-1;
    			if(!fact)fact++;
    			//cout<<fact;newl;
    			res.pb(a);
    			ll sum=a;
    			foo(i,1,cnt-1)res.pb(sum+fact),sum+=res[i];
    			ll ct=b-res[cnt-1];ll cadd=m-fact;
    			//cout<<diff<<" "<<cadd;newl;
    	
    			ll j=1;
    			ll n = cnt;
    			while(ct > 0){
	                ll i = 0,j;
	                for(i = 0;i < 60; i++)
	                    if(pow2[i+1] > ct)
	                        break;
	                for(j = n-1;j > max(n-i-2,0ll); j--)
	                    res[j] += pow2[j-n+i+1];
	                if(j > 0) res[j] += 1;
	                ct -= pow2[i];
	        	}
    			cout<<cnt<<" ";fo(i,cnt)cout<<res[i]<<" ";
    			
    		}
    		else{
    			cout<<-1;
    		}
    		newl;
    	}
     
     
    	/* #ifndef ONLINE_JUDGE
        cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
        #endif */
    }