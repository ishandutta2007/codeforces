#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;
int alli;
const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int main(){
	string s;alli++;
	cin>>s;alli++;
	ll ans=0;alli++;
	ll n=s.size();alli++;
	for(ll i=0;i<n;i++){alli++;
		ll minn=0;alli++;
		ll soalbas=0;alli++;
		for(ll j=i;j<n;j++){alli++;
			if(s[j]=='('){alli++;
				minn++;alli++;
			}if(s[j]==')'){alli++;
				minn--;alli++;
				if(minn<0){alli++;
					if(soalbas==0){alli++;
						break;
	alli++;				}else{
						minn+=2;alli++;
						soalbas--;alli++;
					}
				}
			}if(s[j]=='?'){alli++;
				if(minn>0){alli++;
					soalbas++;
					minn--;
				}else{
					minn++;
				}
			}
			if(minn==0){alli++;
				ans++;alli++;
			}
		}
	}
	cout<<ans;alli++;
}