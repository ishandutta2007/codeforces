#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define repeat(i,a,b) for(int i=(a),i##__end=(b);i<i##__end;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,i##__end=(a);i>=i##__end;i--)
#define mst(a,x) memset((a),(x),sizeof(a))
#define pii pair<int,int>
int n,a[300010],s[300010],s0;
string ss;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n;
	cin>>ss;
	a[0]=s[0]=0;
	bool f=false;
	repeat(i,0,n){
		a[i+1]=(ss[i]=='(')-(ss[i]==')');
		s[i+1]=s[i]+a[i+1];
		if(ss[i]==ss[(i+1)%n]){f=true;s0=i+1;}
	}
	if(s[n]!=0){cout<<0<<endl<<1<<' '<<1<<endl;return 0;}
	
	int ans=-1,l,r;
	for(int LL=1;LL<=n;LL++)
	for(int RR=LL+1;RR<=n;RR++)
	if(a[LL]!=a[RR]){
		swap(a[LL],a[RR]);
		int m=1000000,cnt=0;
		repeat(i,1,n+1){
			s[i]=s[i-1]+a[i];
			if(m>s[i])m=s[i],cnt=1;
			else if(m==s[i])cnt++;
		}
		swap(a[LL],a[RR]);
		if(ans<cnt){
			ans=max(ans,cnt);
			l=LL;
			r=RR;
		}
	}
	
		int m=1000000,cnt=0;
		repeat(i,1,n+1){
			s[i]=s[i-1]+a[i];
			if(m>s[i])m=s[i],cnt=1;
			else if(m==s[i])cnt++;
		}
		if(ans<cnt){
			ans=max(ans,cnt);
			l=1;
			r=1;
		}
	
	cout<<ans<<endl<<l<<' '<<r<<endl;
	return 0;
}