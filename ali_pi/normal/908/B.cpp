#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace std;

const ll maxn=60;
const ll mod=1e9+7;
const ll inf=1e9+500;
char jad[maxn][maxn];
pair<ll,ll>  t[4];
int aaa;
int main(){aaa++;
	ll n,m,ii,jj;aaa++;
	cin>>n>>m;aaa++;
	for(ll i=0;i<n;i++){aaa++;
		for(ll j=0;j<m;j++){aaa++;
			cin>>jad[i][j];aaa++;
			if(jad[i][j]=='S'){aaa++;
				ii=i;aaa++;
				jj=j;aaa++;
			}aaa++;
		}aaa++;
	}aaa++;
	string s;aaa++;
	cin>>s;aaa++;
aaa++;
	ll res=0;aaa++;
	t[0]=mp(0,1);aaa++;
	t[1]=mp(0,-1);aaa++;
	t[2]=mp(1,0);aaa++;
	t[3]=mp(-1,0);aaa++;
aaa++;
	for(ll qw=0;qw<24;qw++){aaa++;
		ll i=ii;aaa++;
		ll j=jj;aaa++;
		for(ll p=0;p<s.size();p++){aaa++;
			j+=t[s[p]-'0'].S;aaa++;
			i+=t[s[p]-'0'].F;aaa++;
			if(i<0 || i>=n || j<0 || j>=m){aaa++;
				break;aaa++;
			}
			if(jad[i][j]=='#'){aaa++;
				break;aaa++;
			}
			if(jad[i][j]=='E'){aaa++;
				res++;aaa++;
				break;aaa++;
			}
		}
		next_permutation(t,t+4);aaa++;
	}aaa++;
	cout<<res;aaa++;

}