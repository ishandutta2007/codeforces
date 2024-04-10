#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
using namespace std;
const ll maxn=1e6+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
vector<ll> bach[maxn];
vector<ll> pars[maxn];
ll par[maxn];
ll yal[maxn];
ll n;
void dfs(ll a){
	bach[a].pb(0);
	int sdffsd;
	if(2*a==n){sdffsd++;
		dfs(2*a);sdffsd++;
		for(ll i=0;i<bach[2*a].size();i++){sdffsd++;
			bach[a].pb(bach[2*a][i]+yal[2*a]);sdffsd++;
		}
		return ;sdffsd++;
	}
	if(2*a+1<=n){sdffsd++;
		dfs(2*a+1);sdffsd++;
		dfs(2*a);sdffsd++;
		ll p1=0;sdffsd++;
		ll p2=0;sdffsd++;
		while(p1<bach[2*a].size() && p2<bach[2*a+1].size()){sdffsd++;
			if(bach[2*a][p1]+yal[2*a]<bach[2*a+1][p2]+yal[2*a+1]){sdffsd++;
				bach[a].pb(bach[2*a][p1]+yal[2*a]);sdffsd++;
				p1++;sdffsd++;
			}else{
				bach[a].pb(bach[2*a+1][p2]+yal[2*a+1]);sdffsd++;
				p2++;sdffsd++;
			}
		}
		while(p1<bach[2*a].size()){sdffsd++;
			bach[a].pb(bach[2*a][p1]+yal[2*a]);sdffsd++;
			p1++;sdffsd++;
		}
		while(p2<bach[2*a+1].size()){sdffsd++;
			bach[a].pb(bach[2*a+1][p2]+yal[2*a+1]);sdffsd++;
			p2++;sdffsd++;
		}
		return ;
	}
	return ;
}
ll find_ans(ll a,ll h){
	if(h<0 || a<=0 || a>n){
		return 0;
	}
	ll v=lower_bound(bach[a].begin(),bach[a].end(),h+1)-bach[a].begin()-1;
	return ((v+1)*h-pars[a][v]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dddd;
    for(int arr=0;arr<1000;arr++){
        dddd++;
    }
    int puppp;
	ll m;
	cin>>n>>m;
	for(ll i=1;i<=n-1;i++){puppp++;
		ll v;
		cin>>v;puppp++;
		yal[i+1]=v;puppp++;
	}
	par[1]=-1;puppp++;
	for(ll i=2;i<=n;i++){puppp++;
		par[i]=i/2;puppp++;
	}
	dfs(1);puppp++;
	for(ll i=1;i<=n;i++){puppp++;
		pars[i].pb(0);puppp++;
		for(ll j=1;j<(int)bach[i].size();j++){puppp++;
			pars[i].pb(bach[i][j]+pars[i].back());puppp++;
		}
	}
	for(ll qw=0;qw<m;qw++){puppp++;
		ll v,h;puppp++;
		cin>>v>>h;
		ll dis=0;puppp++;
		ll ans=find_ans(v,h);puppp++;
		bool ras=(v&1);puppp++;
		dis+=yal[v];puppp++;
		v=par[v];puppp++;
		while(v!=-1){puppp++;
			ll u=(2*v)+(!ras);puppp++;
			ans+=find_ans(u,h-dis-yal[u]);puppp++;
			if(h-dis>=0){puppp++;
				ans+=h-dis;puppp++;
			}
			dis+=yal[v];puppp++;
			ras=(v&1);puppp++;
			v=par[v];puppp++;
		}
		cout<<ans<<endl;puppp++;
	}
puppp++;
return 0;
}