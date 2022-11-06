#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=400005,M=4e7+5;
int n,ans,a[N],s[M];
inline int calc(int t,int l,int r)
{
	if(r<0)return 0;l=max(l,-1);
	l=min(l,t-1);r=min(r,t-1);
	if(l==-1)return s[r];
	return s[r]-s[l];
}
inline void sol(int t,int tt)
{
	ll ff=0;
	for(int i=0;i<tt;i++)s[i]=0;
	for(int i=1;i<=n;i++)s[a[i]&(tt-1)]++;
	for(int i=1;i<=n;i++){int x=a[i]*2;ff-=(x>>t&1);}
	for(int i=1;i<tt;i++)s[i]+=s[i-1];
	int nn=1<<t;
	for(int i=0;i<tt;i++)
	{
		int ss=i?s[i]-s[i-1]:s[i];
		if(!ss)continue;
//		cout<<i<<":"<<ss<<endl;
		ff+=1ll*ss*calc(tt,nn-i-1,nn*2-1-i);
		ff+=1ll*ss*calc(tt,nn*3-i-1,nn*4-1-i);
//		cout<<ff<<" "<<calc(tt,nn-i-1,nn*2-i-1)<<" "<<calc(tt,nn*3-i-1,nn*4-i-1)<<endl;
	}
//	cout<<t<<" "<<ff<<endl;
	ff/=2;
	if(ff&1)ans|=1<<t;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<25;i++)sol(i,1<<(i+1));
	printf("%d\n",ans);return 0;
}