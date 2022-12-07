#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int ans[1005],n;
mt19937_64 rnd(time(0));
int ask1(int x){
	cout<<1<<' '<<x<<'\n';
	fflush(stdout);
	int val;
	cin>>val;RE val;
}
int ask2(int x){
	cout<<2<<' '<<x<<'\n';
	fflush(stdout);
	int val;
	cin>>val;RE val;
}
void solve(int i){
	int t=ask1(i);
	if(t)ans[i]=ans[t];else ans[i]=1; 
}
void solve(){
	cin>>n;
	ans[1]=0;
	if(ask1(2)==1)ans[2]=0;else ans[2]=1;
	FOR(i,3,n){
		if(i==n){
			solve(i);
		}else{
			if(rnd()&1){
				int t=ask1(i+1);
				if(ans[1]==ans[2]){
					if(!t){
						ans[i+1]=1;
						solve(i);
					}else if(t==1){
						ans[i]=1;ans[i+1]=0;
					}else{
						if(t==i){
							ans[i]=ans[i+1]=0;
						}else{
							ans[i]=ans[t-1];ans[i+1]=ans[t];
						}
					}
				}else{
					if(!t){
						ans[i+1]=ans[i]=1;
					}else if(t==1){
						ans[i+1]=0;solve(i);
					} else {
						if(t==i){
							ans[i]=ans[i+1]=0;
						}else {
							ans[i]=ans[t-1];ans[i+1]=ans[t];
						}
					}
				}
			}else{
				int t=ask2(i+1);
				if(ans[1]==ans[2]){
					if(!t){
						ans[i+1]=0;
						solve(i);
					}else if(t==1){
						ans[i+1]=1;ans[i]=0;
					}else {
						ans[i]=!ans[t-1];ans[i+1]=!ans[t];
					}
				}else{
					if(!t){
						ans[i]=ans[i+1]=0;
					}else if(t==1){
						ans[i+1]=1;solve(i);
					}else {
						if(t==i){
							ans[i]=!(i&1);ans[i+1]=!ans[i];
						}else{
							ans[i]=!ans[t-1];ans[i+1]=!ans[t];
						}
					}
				}
			}
			i++;
		}
	}
	cout<<"0 ";
	FOR(i,1,n)cout<<ans[i];
	cout<<"\n";
	fflush(stdout);
	int x;cin>>x;
}
signed main(){
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}