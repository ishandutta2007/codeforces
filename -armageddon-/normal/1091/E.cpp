#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#include <time.h>
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int a[500005];
ll sum[500005];
int data[500005];
ll s[500005];

bool compare(const int &a,const int &b)
{
	return a>b;
}

int check(int x)
{
	int i=x;
	int res=0;
	for(int k=1;k<=n;k++)
	{	
		a[k]=data[k];
	}
	int pos=lower_bound(a+1,a+n+1,x,compare)-a;
//	cout<<a[1]<<' '<<a[2]<<' '<<x<<endl;
	for(int i=n+1;i>pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos]=i;
//	a[n+1]=i;
//	sort(a+1,a+n+2);
//	reverse(a+1,a+n+2);
	sum[1]=a[1];
	for(int k=2;k<=n+1;k++)
	{
		sum[k]=sum[k-1]+a[k];
	}
//	for(int k=1;k<=n+1;k++)
//	{
//		cout<<a[k]<<' ';
//	}
//	cout<<endl;
//	cout<<endl;
	bool f=true;
	int last=n+1;
	for(int k=1;k<=n+1;k++)
	{
//		cout<<sum[k]<<' ';
		ll s=1LL*k*(k-1);
		last=max(last,k);
		while(last>k && a[last]<=k) last--;
//		last++;
//		cout<<k<<' '<<last<<' '<<sum[n+1]-sum[last]<<endl;
//		last=lower_bound(a+k+1,a+n+1,k,compare)-a;
		s+=1LL*(last-k)*k+sum[n+1]-sum[last];
//		cout<<sum[k]<<' '<<s<<endl;
//		for(int j=k+1;j<=n+1;j++)
//		{
//			s+=min(k,a[j]);
//		}
//			cout<<sum[k]<<' '<<s<<endl;
		if(sum[k]>s)
		{
//			f=false;
			res++;
		}
//			cout<<endl;
	}
//	cout<<endl;
	return res;
}

//int check(int x)
//{
//	int N=n+1;
////    init();
//    for (int i=1; i<N; ++i) {
//    	a[i]=data[i];
//    	a[i]=-a[i];
//    }
//    a[N]=-x;
//    sort(a+1, a+N+1);
//    for (int i=1; i<=N; ++i) {
//        s[i] = s[i-1]-a[i];
//    }
//    int res=0;
//    for (int r=1; r<=N; ++r) {
//        int pos = upper_bound(a+r+1, a+N+1, -r)-a;
//        if (s[r]> 1LL*r*(r-1)+  s[N]-s[pos-1]+  1LL*r*(pos-r-1)) {
////            flag = false;
//            res++;
//        }
//    }
//    return res;
////    printf ("%s\n", flag ? "yes" : "no");
//}

int main()
{
//	srand((unsigned)time(0));
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		data[i]=a[i];
	}
	sort(data+1,data+n+1,compare);
//	int debug=true;//(n==500000 && a[1]==500000 && a[2]==300000);
	sort(a+1,a+n+1,compare);
//	reverse(a+1,a+n+1);
	sum[1]=a[1];
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
//	cout<<check(2)<<endl;
//	return 0;
//	for(int i=-1;i<=n;i++)
//	{
//		cout<<check(i)<<' ';
//	}
//	cout<<endl;
	int l=0,r=n,mid,resl=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		if(check(mid)>check(mid+1))
		{
			resl=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
//	l=0;
//	r=n;
//	int resr=-1;
//	while(l<=r)
//	{
//		mid=l+r>>1;
//		if(check(mid)>check(mid-1))
//		{
//			resr=mid;
//			r=mid-1;
//		}
//		else
//		{
//			l=mid+1;
//		}
//	}
//	cout<<resl<<' '<<resr<<endl;
//	for(int i=resl;i<resr;i++)
//	{
//		if(!((i+sum[n])&1)) cout<<i<<' ';
//	}
//	check(0);
//	return 0;
//	for(int i=0;i<=n;i++)
//	{
//		cout<<check(i)<<' ';
//	}
//	cout<<endl;
	int fuck=check(0);
//	int l=fuck-1;
	if((l+sum[n])&1) l--;
	if(l<0) l+=2;
	if(check(l)!=0) l+=2;
//	cout<<l<<endl;
	int mask=(sum[n]&1);
	int rl,rr;
	rl=l;
	rr=n;
	if((rr&1)!=mask) rr--;
//	int mid,r=-1;
//	cout<<check(2)<<endl;
//	return 0;
//	cout<<rl<<' '<<rr<<endl;
	r=-1;
	while(rl<=rr)
	{
//		mid=(double)(rr-rl)*((double)1/rand())+rl;
		mid=rl+rr>>1;
//		cout<<rl<<' '<<rr<<' '<<mid<<endl;
		int x=check(mid);
		if(x==0)
		{
			r=mid;
			rl=mid+1;
		}
		else
		{
			rr=mid-1;
		}
	}
//	cout<<l<<endl;
//	int k2;
//	if(((n)&1)==(sum[n]&1))
//	{
//		k2=n;
//	}
//	else
//	{
//		k2=n-1;
//	}
//	tn=k2;
//	cout<<check(8)<<endl;
//	cout<<k2<<endl;
//	k2=check(k2);
////	cout<<k2<<endl;
//	int r=n-k2;
////	cout<<r<<endl;
////	cout<<(sum[n]&1)<<endl;
//	if((r&1)!=(sum[n]&1)) r--;
//	if(r<0) r+=2;
////	cout<<r<<endl;
//	while(r<=tn && check(r)==0)
//	{
//		r+=2;
//	}
//	r-=2;
//	cout<<l<<' '<<r<<endl;
	if(l>r)
	{
		cout<<-1<<endl;
	}
	else
	{
		for(int i=l;i<=r;i+=2)
		{
			printf("%d ",i);
		}
	}
////		sort(a+1,a+n+2);
////		reverse(a+1,a+n+2);
////		sum[1]=a[1];
////		for(int k=2;k<=n+1;k++)
////		{
////			sum[k]=sum[k-1]+a[k];
////		}
//////		for(int k=1;k<=n+1;k++)
//////		{
//////			cout<<sum[k]<<' ';
//////		}
//////		cout<<endl;
////		bool f=true;
////		for(int k=1;k<=n+1;k++)
////		{
////			int s=k*(k-1);
////			for(int j=k+1;j<=n+1;j++)
////			{
////				s+=min(k,a[j]);
////			}
//////			cout<<sum[k]<<' '<<s<<endl;
////			if(sum[k]>s)
////			{
////				f=false;
////				cout<<k<<' ';
////			}
//////			cout<<endl;
////		}
////		cout<<endl;
////		if(f) cout<<i<<endl;
////		int pos=lower_bound(a,a+n,i)-a;
//	}
	return 0;
}