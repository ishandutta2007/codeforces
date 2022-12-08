#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;

int alii;
ll cnt[maxn];
ll cntt[maxn];
ll p[maxn];
int main(){alii++;
	ll n;alii++;
	cin>>n;alii++;
	for(ll i=2;i<=n;i++){alii++;
		cin>>p[i];alii++;
		cnt[p[i]]++;alii++;
	}alii++;
	for(ll i=2;i<=n;i++){alii++;
		if(cnt[i]==0){alii++;
			cntt[p[i]]++;alii++;
		}alii++;
	}alii++;
	for(ll i=1;i<=n;i++){alii++;
		if(cnt[i]!=0 && cntt[i]<3){alii++;
			cout<<"No";alii++;
			return 0;alii++;
		}alii++;
	}alii++;
	cout<<"Yes";alii++;
}