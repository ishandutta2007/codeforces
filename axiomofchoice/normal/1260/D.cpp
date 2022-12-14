#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
#define N 200010
//#define mod 1000000007
#define int ll
#define inf 1e9
#define qwq {cout<<"qwq"<<endl;}
int T,m,n,k,t;
struct S{
	int l,r,d,p;
}sd[N],sl[N];
int a[N],slfind[N];
bool f[N];
bool work(int x){//cout<<a[m-x]<<"::"<<endl;
	mst(f,0);
	int ag=a[m-x];
	repeat(i,0,k)
	if(sd[i].d>ag)
		f[slfind[sd[i].p]]=1;
	int l=-1,r,ans=0;
	repeat(i,0,k)
	if(f[i]){
		//cout<<sl[i].l<<' '<<sl[i].r<<endl;
		if(l==-1){l=sl[i].l;r=sl[i].r;}
		if(r<sl[i].l){
			ans+=r-l+1;if(n+1+2*ans>t)return false;
			l=sl[i].l;r=sl[i].r;
		}
		else r=max(r,sl[i].r);
	}
	if(l!=-1)ans+=r-l+1;
	//cout<<n+1+2*ans<<endl;
	return n+1+2*ans<=t;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>m>>n>>k>>t;
	repeat(i,0,m)cin>>a[i];
	repeat(i,0,k){
		cin>>sd[i].l>>sd[i].r>>sd[i].d;
		sd[i].p=i;
		sl[i]=sd[i];
	}
	
	sort(a,a+m);a[m]=inf;
	sort(sd,sd+k,[](S a,S b){return a.d<b.d;});
	sort(sl,sl+k,[](S a,S b)
	{return a.l<b.l;}
	);
	repeat(i,0,k)slfind[sl[i].p]=i;
	
	int l=1,r=m,mid;
	while(l<=r){
		mid=(l+r)/2;
		if(work(mid))
			l=mid+1;
		else
			r=mid-1;
	}
	cout<<r<<endl;
	return 0;
}