// Tima the best
#include <bits/stdc++.h>

#define ll long long                   
#define f first 
#define s second 
#define pb push_back               
#define mp make_pair 
#define o cout<<"BUG"<<endl;
#define	IOS ios_base::sync_with_stdio(0);
using namespace std;                    
const ll maxn=2e4+123,inf=1e8,mod=1e9+7,block=200,N=1e5+123;
int n,m,p,x[maxn],y[maxn],dp1[maxn],dp2[maxn],tmp[maxn],ans;	
string s;
int get(int i,int j){
	return (x[i]+y[j])%p;
}
void rec(int ln,int rn,int lm,int rm){
	if(ln==rn){
		for(int i=lm;i<rm;i++)	
			s+='S';
	   	if(rn!=n)
		   	s+='C';
	   	return;
	}
	int mn=(ln+rn)/2;
	
	for(int i=lm;i<=rm;i++)
		tmp[i]=0;       
	
	for(int i=ln;i<=mn;i++){
		for(int j=lm;j<=rm;j++)
			dp1[j]=max(tmp[j],dp1[j-1])+get(i,j);
		for(int j=lm;j<=rm;j++)
			tmp[j]=dp1[j];
	}

	for(int i=lm;i<=rm;i++)
		tmp[i]=0;

	for(int i=rn;i>mn;i--){
		for(int j=rm;j>=lm;j--)
			dp2[j]=max(tmp[j],dp2[j+1])+get(i,j);
		for(int j=lm;j<=rm;j++)
			tmp[j]=dp2[j];
	}

	int x=lm;
	for(int i=lm;i<=rm;i++)
		if( dp1[i]+dp2[i]>dp1[x]+dp2[x] )
			x=i;                      
	for(int i=lm;i<=rm;i++)
		dp1[i]=0,dp2[i]=0;
	
	rec(ln,mn,lm,x);
	rec(mn+1,rn,x,rm);

}
int main(){
	#ifdef LOCAL
    	freopen ("test.in", "r", stdin);
	#endif
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++)
		cin>>x[i];

	for(int i=1;i<=m;i++)
		cin>>y[i];
	
	rec(1,n,1,m);
	int x=1,y=1;
	for(int i=0;i<s.size();i++){
		ans+=get(x,y);
		if(s[i]=='S')
			y++;
		else
			x++;	
	}
	cout<<ans+get(n,m)<<endl<<s;

}