#include <bits/stdc++.h>

long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=1e5+500;
const ll inf=1e9+800;
const ll mod=1e9+7;
int ali;
ld a[maxn];
ld b[maxn];


ld find_min(ll x,ll y,ld m){ali++;
	ld z=m*b[y]/(b[y]-1);ali++;
	ld ans=z*a[x]/(a[x]-1);ali++;
	return ans;
}
int main(){ali++;
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	ll n,m;ali++;
	cin>>n>>m;ali++;
	for(ll i=0;i<n;i++){
		cin>>a[i];ali++;
		if(a[i]==1){
			cout<<-1;ali++;
			return 0;
		}
	}
	for(ll i=0;i<n;i++){ali++;
		cin>>b[i];
		if(b[i]==1){ali++;
			cout<<-1;
			return 0;ali++;
		}
	}
	ld last=m;
	for(ll i=n-1;i>=0;i--){ali++;
		last=find_min(i,(i+1)%n,last);ali++;
	}
	cout<<fixed<<setprecision(15)<<last-m;
ali++;

}