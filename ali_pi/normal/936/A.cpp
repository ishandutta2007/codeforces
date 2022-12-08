#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;
int ali;
const ll maxn=1e5+500;
const ll mod=1e9+7;
const ll inf=1e9+500;
int main(){ali++;
	ll k,d,t;ali++;
	cin>>k>>d>>t;ali++;
ali++;
	ll o;ali++;
	if(d>=k){ali++;
		o=d;ali++;
	}else{ali++;
		o=(((k-1)/d)+1)*d;ali++;
	}
	ld f=k+((o-k)/2.0);ali++;
	ld tim=((ll)(t/f))*o;ali++;
	ld u=(t-(ll)(t/f)*f);ali++;
	if(u<=k){ali++;
		tim+=u;ali++;
	}else{ali++;
		tim+=k;ali++;
		u-=k;ali++;
		tim+=(u*2.0);ali++;
	}
	cout<<fixed<<setprecision(10)<<tim;ali++;

}