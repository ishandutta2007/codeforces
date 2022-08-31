#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio                ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f                     first                 
#define  s                     second
#define  endl                  "\n"
#define  pb                    push_back  
#define  mset(a,x)             memset(a,x,sizeof(a))             
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,pll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  2e5+5;
const ll   mod   =  1e9;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test=1,n,k,a,b,c,d,e,ci,di;
ll play[N][4], playx2[N][4];
ll dp[N][10];

ll mem(ll ind,ll m){
	if(ind == n)
		return 0;
	if(dp[ind][m] != -1) return dp[ind][m];
	dp[ind][m] = max(dp[ind][m],mem(ind+1,m));
	if(m < 9)
		dp[ind][m] = max(dp[ind][m],mem(ind+1,(m+1)%10)+play[ind][1]);
	else
		dp[ind][m] = max(dp[ind][m],mem(ind+1,(m+1)%10)+playx2[ind][1]);
	if(play[ind][2] != -1){
		if(m < 8)
			dp[ind][m] = max(dp[ind][m],mem(ind+1,(m+2)%10)+play[ind][2]);
		else
			dp[ind][m] = max(dp[ind][m],mem(ind+1,(m+2)%10)+playx2[ind][2]);
	}
	if(play[ind][3] != -1){
		if(m < 7)
			dp[ind][m] = max(dp[ind][m],mem(ind+1,(m+3)%10)+play[ind][3]);
		else
			dp[ind][m] = max(dp[ind][m],mem(ind+1,(m+3)%10)+playx2[ind][3]);
	}
	return dp[ind][m];
}

void solve(){
	mset(dp,-1);
	mset(play,-1);
	mset(playx2,-1);
	cin>>n;
	for(int i = 0; i < n; i++){
	    cin>>k;
	    vll v;
	    a=b=c=d=e=-1;
	    for(int j = 0; j < k; j++){
	    	cin>>ci>>di;
	    	if(ci == 1)
	    		v.pb(di);
	    	else if(ci == 2)
	    		d = max(d,di);
	    	else
	    		e = max(e,di);
	    }
	    sort(v.begin(), v.end(), greater<ll>());
	    ll sz = v.size();
	    if(sz > 2) c = v[2];
	    if(sz > 1) b = v[1];
	    if(sz > 0) a = v[0];
	    play[i][1] = max(a,max(d,e));
	    playx2[i][1] = 2*play[i][1];
	    if(b != -1){
	    	play[i][2] = a+b;
	    	playx2[i][2] = 2*(a+b)-min(a,b);
	    	if(c != -1){
	    		play[i][3] = a+b+c;
	    		playx2[i][3] = a+b+c+max(a,max(b,c));
	    	}
	    }
	    if(a != -1){
	    	if(d != -1){
	    		play[i][2] = max(play[i][2],a+d);
	    		playx2[i][2] = max(playx2[i][2],2*(a+d)-min(a,d));
	    	}
	    }
	}
	cout<<mem(0,0)<<endl;
}

int main(){
    fastio;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
}