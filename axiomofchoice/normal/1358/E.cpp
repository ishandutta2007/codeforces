#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=500010; typedef long long ll;
#define int ll
int T,n,x,a[N],S[N],*s=S+1;
signed main(){
	cin>>n;
	repeat(i,0,(n+1)/2)
		cin>>a[i],s[i]=s[i-1]+a[i];
	cin>>x;
	repeat(i,(n+1)/2,n)
		a[i]=x,s[i]=s[i-1]+a[i];
	if(x>=0)cout<<(s[n-1]>0?n:-1)<<endl,exit(0);
	
	function<int(int,int)> calc=[](int l,int r){
		return s[r]-s[l-1];
	};
	int l=(n+1)/2,r=n-1;
	while(1){
		//orz(make_pair(l,r)); //orz(calc(l,r));
		while(l>0 && calc(l-1,r)<=0)l--; //orz(l);
		if(l==0)cout<<-1<<endl,exit(0);
		l--;
		while(l>0 && calc(l-1,r-1)>0)l--,r--; //orz(make_pair(l,r));
		if(l==0)cout<<r-l+1<<endl,exit(0);
		l--;
		r=n-1;
	}
	return 0;
}