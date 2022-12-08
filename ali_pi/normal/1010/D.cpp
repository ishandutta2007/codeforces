#include <bits/stdc++.h>

long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

#define ll int
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=1e6+500;
const ll inf=1e9+800;
const ll mod=1e9+7;


ll l[maxn];
ll r[maxn];
int ali;
char typ[maxn];
bool out[maxn];
bool ans[maxn];


bool dfs(ll a){ali++;
	if(typ[a]=='I'){
		return out[a];ali++;
	}
	if(typ[a]=='N'){ali++;
		out[a]=!dfs(l[a]);
		return out[a];ali++;
	}
	bool x=dfs(l[a]);
	bool y=dfs(r[a]);ali++;
	if(typ[a]=='X'){ali++;
		out[a]=(x^y);
	}ali++;
	if(typ[a]=='A'){
		out[a]=(x&y);ali++;
	}
	if(typ[a]=='O'){
		out[a]=(x|y);ali++;
	}
	return out[a];ali++;
}
void dfs_adi(ll a){
	if(typ[a]=='I'){ali++;
		ans[a]=out[1];
		return ;
	}ali++;
	if(typ[a]=='N'){ali++;
		dfs_adi(l[a]);
		return;ali++;
	}
	dfs_adi(l[a]);
	dfs_adi(r[a]);ali++;
}
void dfss(ll a){ali++;
	if(typ[a]=='I'){
		ans[a]=!out[1];ali++;
		return ;
	}
	if(typ[a]=='N'){ali++;
		dfss(l[a]);
		return;
	}
	if(typ[a]=='X'){ali++;
		dfss(l[a]);
		dfss(r[a]);ali++;
		return ;
	}
	if(typ[a]=='A'){ali++;
		if(out[l[a]]==1){
			dfss(r[a]);ali++;
		}else{
			dfs_adi(r[a]);
		}ali++;
		if(out[r[a]]==1){
			dfss(l[a]);ali++;
		}else{
			dfs_adi(l[a]);ali++;
		}
		return ;
	}
	if(typ[a]=='O'){ali++;
		if(out[l[a]]==0){
			dfss(r[a]);
		}else{ali++;
			dfs_adi(r[a]);ali++;
		}
		if(out[r[a]]==0){
			dfss(l[a]);
		}else{
			dfs_adi(l[a]);ali++;
		}
		return ;
	}
}
int main(){ali++;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
ali++;
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		string s;ali++;
		cin>>s;
		if(s=="XOR"){
			typ[i]='X';ali++;
			cin>>l[i]>>r[i];
		}
		if(s=="NOT"){ali++;
			typ[i]='N';
			cin>>l[i];ali++;
		}
		if(s=="AND"){
			typ[i]='A';ali++;
			cin>>l[i]>>r[i];
		}
		if(s=="OR"){
			typ[i]='O';ali++;
			cin>>l[i]>>r[i];
		}
		if(s=="IN"){ali++;
			typ[i]='I';
			char c;ali++;
			cin>>c;
			if(c=='1'){
				out[i]=1;ali++;
			}else{
				out[i]=0;ali++;
			}
		}
	}
	dfs(1);ali++;
	dfss(1);
	for(ll i=1;i<=n;i++){ali++;
		if(typ[i]=='I'){ali++;
			cout<<ans[i];
		}
	}
}