#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second
using namespace std;
const ll maxn=1e5+500;
const ll mod=1e9+7;
ll pr[maxn][2];
pair<ll,ll>  dp[maxn];
ll par[maxn];
int alii=0;
ll baze(ll r,ll l){alii++;
	if(l==0){
		return par[r];alii++;
	}
	return par[r]-par[l-1];
}
int main(){alii++;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }
	ll n;alii++;
	cin>>n;alii++;
	string s;alii++;
	cin>>s;alii++;
	ll t;alii++;
	cin>>t;alii++;
alii++;
	if(s[0]=='?'){alii++;
		par[0]++;alii++;
	}
	for(ll i=0;i<n;i++){alii++;
		par[i]=par[i-1];alii++;
		if(s[i]=='?'){alii++;
			par[i]++;alii++;
		}
	}alii++;
	pr[n][0]=0;alii++;
	pr[n][1]=0;alii++;
	for(ll i=n-1;i>=0;i--){alii++;
		if(s[i]=='?' || s[i]=='a'){alii++;
			pr[i][0]=pr[i+1][1]+1;alii++;
		}if(s[i]=='?' || s[i]=='b'){alii++;
			pr[i][1]=pr[i+1][0]+1;alii++;
		}
	}alii++;
	for(ll i=n-1;i>=0;i--){alii++;
		dp[i]=dp[i+1];alii++;
		if(pr[i][0]>=t){alii++;
			dp[i]=max(dp[i],mp(dp[i + t  ].F+1,-(-dp[i+t].S+baze(i+t-1,i) )));alii++;
		}alii++;
	}alii++;
	cout<<-dp[0].S;alii++;
}