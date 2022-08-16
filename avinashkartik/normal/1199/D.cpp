#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll INF = 1e18;

ll a[200005],b[200005],c[200005];
vector <ll> a1;
vector <pair<ll,ll>> a2;
ll vis[200005],ans[200005],m[200005][3];
ll t,n,u,v,ct,q;
pair <ll,ll> p;

int main(){
	cin>>n;
	for(int i = 0;i<n;i++){cin>>ans[i];}
	cin>>q;
	for(int i = 0;i<q;i++){
		cin>>m[i][0];
		if(m[i][0] == 2){
			cin>>m[i][1];
		}
		else{
			cin>>m[i][1]>>m[i][2];
		}
	}
	if(m[0][0] == 2) b[0] = m[0][1];
	for(int i = 0;i<q;i++){
	    if(m[i][0] == 2)
	        b[i] = m[i][1];
	}

	for(int i = q-2;i>-1;i--){
	    b[i] = max(b[i],b[i+1]);
	}
	//for(int i = 0;i<q;i++) cout<<b[i]<<" ";

	for(int i = 0;i<q;i++){
	    if(m[i][0] == 1){
	        ans[m[i][1]-1] = m[i][2];
	        c[m[i][1]-1] = i;
	    }
	}
	for(int i = 0;i<n;i++){
	    ans[i] = max(ans[i],b[c[i]]);
	    cout<<ans[i]<<" ";
	}
	cout<<endl;

}