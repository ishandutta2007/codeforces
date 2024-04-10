//ulala
//code by 255
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pll pair<ll, ll>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef __gnu_pbds::tree<ll, __gnu_pbds::null_type, less<ll>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> yree;
const ll inf = 0x3fff3fff3fff3fff;
const ll N = 1005;
ll god[N][N], gor[N][N];
bool ban[N][N];

signed main(){
	cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
	ll n, m, q, res=0;
	cin >> n >> m >> q;
	ll fr=n*m;
	for(ll i = n-1;i>=0;i--){
		for(ll j = m-1;j>=0;j--){
			gor[i][j]=1+(god[i][j+1]);
			god[i][j]=1+(gor[i+1][j]);
			res+=gor[i][j]+god[i][j];
		}
	}
	//cout<<"D "<<res-fr<<'\n';
	while(q--){
		ll r, c;
		cin >> r >> c;
		--r, c--;
		ll td=0, tr=0;
		ll xr=r+1, xc=c, l=1;
		while(xr<n&&xc<m&&!ban[xr][xc]){
			td++;
			if(l) xc++;
			else xr++;
			l^=1;
		}
		xr=r, xc=c+1, l=0;
		while(xr<n&&xc<m&&!ban[xr][xc]){
			tr++;
			if(l) xc++;
			else xr++;
			l^=1;
		}
		ll tu = 0, tl=0;
		xr=r-1, xc=c;
		l=0;
		while(xr>=0&&xc>=0&&!ban[xr][xc]){
			tu++;
			if(l) xr--;
			else xc--;
			l^=1;
		}
		xr=r, xc=c-1;
		l=1;
		while(xr>=0&&xc>=0&&!ban[xr][xc]){
			tl++;
			if(l) xr--;
			else xc--;
			l^=1;
		}
		if(!ban[r][c]){
			fr--;
			ban[r][c]=1;
			res-=(tu+1)*(tr+1);
			res-=(tl+1)*(td+1);
		}else{
			fr++;
			ban[r][c]=0;
			res+=(tu+1)*(tr+1);
			res+=(tl+1)*(td+1);
		}
		cout<<res-fr<<'\n';
	}
}