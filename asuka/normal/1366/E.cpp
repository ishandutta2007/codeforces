#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
//#define mp make_pair
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int n,m,a[N],b[N];
map<int,int> mp;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,m) cin>>b[i];
	rep(i,1,n) mp[a[i]] = i; 
	int idx = 1;ll res = 1;
	rep(i,1,m){
		if(!mp.count(b[i])||idx>mp[b[i]]){
			cout << 0;
			return 0;
		}
		if(i==1){
			while(idx <= mp[b[i]]){
				if(a[idx]<b[i]){
					cout << 0;
					return 0;
				}
				idx++;
			}
		}else{
			int temp = mp[b[i-1]];
			while(idx<mp[b[i]]){
				if(a[idx]<b[i-1]){
					cout << 0;
					return 0;
				}
				if(a[idx]<b[i]) temp = idx;
				idx++;
			}
			res = (res*(mp[b[i]]-temp)%mod)%mod;
		}
	}
	rep(i,idx,n){
		if(a[i]<b[m]){
			cout << 0;
			return 0;
		}
	}
	cout << res << endl;
	return 0;
}