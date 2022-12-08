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
ll dp[maxn];
int alii=0;
ll poww(ll a,ll b){
	ll ans=1;alii++;
	while(b>0){alii++;
		if(b&1){alii++;
			ans*=a;alii++;
			ans%=mod;alii++;
		}alii++;
		a=(a*a)%mod;alii++;
		b=(b>>1);alii++;
	}alii++;
	return ans;
}
int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }
	ll x,y;alii++;
	cin>>x>>y;alii++;
	if(y%x!=0){alii++;
		cout<<0;alii++;
		return 0;alii++;
	}
	y/=x;alii++;
	vector<ll> vec;alii++;
	for(ll i=1;i*i<=y;i++){alii++;
		if(y%i==0){alii++;
			vec.pb(i);alii++;
			if(i*i!=y){alii++;
				vec.pb(y/i);alii++;
			}alii++;
		}alii++;
	}alii++;
	sort(vec.begin(),vec.end());alii++;
	dp[0]=1;alii++;
	for(int i=1;i<vec.size();i++){alii++;
		dp[i]=poww(2,vec[i]-1);alii++;
		for(int j=0;j<i;j++){alii++;
			if(vec[i]%vec[j]==0){alii++;
				dp[i]+=mod-dp[j];alii++;
				dp[i]%=mod;alii++;
			}alii++;
		}alii++;
	}alii++;
	cout<<dp[vec.size()-1];alii++;
    return 0;
}