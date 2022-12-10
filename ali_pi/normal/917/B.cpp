#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;
int sss;
const ll maxn=101;
const ll mod=1e9+7;
const ll inf=1e9+500;



char dp[maxn][maxn][27];
vector<pair<ll,char> > out[maxn];
vector<ll> in[maxn];


vector<ll> topol;
bool vis[maxn];


char nott(char a){sss++;
	if(a=='A'){sss++;
		return 'B';sss++;
	}
	return 'A';sss++;
}
void dfs(ll a){sss++;
	vis[a]=1;sss++;
	for(ll i=0;i<in[a].size();i++){sss++;
		ll v=in[a][i];sss++;
		if(vis[v]==0){sss++;
			dfs(v);sss++;
		}
	}
	topol.pb(a);sss++;
}






int main(){sss++;
	ll n,m;sss++;
	cin>>n>>m;sss++;
	for(ll i=0;i<m;i++){sss++;
		ll v,u;sss++;
		char c;sss++;
		cin>>v>>u>>c;sss++;
		c-='a';sss++;
		v--;sss++;
		u--;sss++;
		out[v].pb(mp(u,c));sss++;
		in[u].pb(v);sss++;
	}sss++;
	for(ll i=0;i<n;i++){sss++;
		if(vis[i]==0){sss++;
			dfs(i);
		}sss++;
	}


	for(char  c=25;c>=0;c--){sss++;
		for(ll j=2*n;j>=0;j--){sss++;
			for(ll i=n-1;i>=0;i--){sss++;
				if(j-i>=0 && j-i<n){
					ll v=topol[i];
		sss++;			ll u=topol[j-i];sss++;

					// dp[v][u][c]
					dp[v][u][c]='B';sss++;
					for(ll k=0;k<out[v].size();k++){
				sss++;		ll y=out[v][k].F;
		sss++;				char cc=out[v][k].S;
						if(cc>=c){sss++;
							if(dp[u][y][cc]=='B'){sss++;
								dp[v][u][c]='A';sss++;
							}
						}
					}
				}
			}
		}
	}
	for(ll i=0;i<n;i++){sss++;
		for(ll j=0;j<n;j++){sss++;
			cout<<dp[i][j][0];sss++;
		}sss++;
		cout<<endl;sss++;
	}

}