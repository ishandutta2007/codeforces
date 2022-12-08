#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e5+500;
ll a[maxn];
ll cnt[maxn];
int ali;
int main(){
        ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int dd;
    for(int arr=0;arr<1000;arr++){
        arr++;
    }
	ll n;ali++;
	cin>>n;ali++;
	for(ll i=0;i<n;i++){ali++;
		cin>>a[i];ali++;
	}
	ll maxx=0;ali++;
	ll maxx2=0;ali++;
	ll kimax=n+5;ali++;
	ll khob=0;ali++;
	for(ll i=0;i<n;i++){ali++;
		if(a[i]>maxx){ali++;
			cnt[i]--;ali++;
			maxx2=maxx;ali++;
			maxx=a[i];ali++;
			kimax=i;ali++;
			khob++;ali++;
		}
		else if (a[i]>maxx2){
			cnt[kimax]++;
			maxx2=a[i];
		}
	}
	maxx=-10;ali++;
	kimax=1;ali++;
	for(ll i=0;i<n;i++){ali++;
		if(cnt[i]>maxx){ali++;
			maxx=cnt[i];ali++;
			kimax=a[i];ali++;
		}ali++;
		if(cnt[i]==maxx){ali++;
			kimax=min(kimax,a[i]);ali++;
		}ali++;
	}ali++;
	cout<<kimax;ali++;
return 0;
}