#include <bits/stdc++.h>
using namespace std;
double x[200005],y[200005],k,b,Dn[200005],Dn1[200005],D1[200005];
int XX[200005],YY[200005];
pair <double,double> B[200005];
pair <double,int> a[200005];
int n;
inline int check(int i,int j)
{
	k=(y[j]-y[i])/(x[j]-x[i]);
	b=y[i]-k*x[i];
	int pos=-1;
	for(int i=1;i<=n;i++)
	{
		if(fabs(y[i]-x[i]*k-b)>=1e-8)
		{
			if(pos==-1) pos=i;
			else return -1;
		}
	}
	return pos;
}
inline double dis(int i,int j)
{
	double X=x[a[i].second]-x[a[j].second],Y=y[a[i].second]-y[a[j].second];
	return sqrt(X*X+Y*Y);
}
map <pair<double,double>,int> mp;
int main(int argc, char** argv) {
//	freopen("data.txt","r",stdin);
	int s,p;
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand((unsigned long long)new char);
	cin >> n >> s;
	for(int i=1;i<=n;i++)
	{
		cin >> XX[i] >> YY[i];
		x[i]=XX[i],y[i]=YY[i];
		B[i]={x[i],y[i]};
	}
//	return 0;
	pair<double,double> S=B[s];
	sort(B+1,B+n+1);
	int cnt=0;x[0]=1e9;
	for(int i=1;i<=n;i++)
		if(B[i]!=make_pair(x[cnt],y[cnt])) x[++cnt]=B[i].first,y[cnt]=B[i].second;
	for(int i=1;i<=cnt;i++)
		if(make_pair(x[i],y[i])==S) s=i;
	n=cnt;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
	{
		if(x[i]==x[1]) ++cnt1;
		else if(x[i]==x[2]) ++cnt2;
	}
	if(cnt1==n-1)
	{
		for(int i=1;i<=n;i++)
			if(x[i]!=x[1]) p=i;
	}
	else if(cnt2==n-1)
	{
		for(int i=1;i<=n;i++)
			if(x[i]!=x[2]) p=i;
	}
	else if((p=check(1,2))==-1)if((p=check(3,2))==-1) p=check(1,3);
	double X=(double)rand()/rand(),Y=(double)rand()/rand();
	while(X<0.1)  X=(double)rand()/(double)rand();
	while(Y<0.1)  Y=(double)rand()/(double)rand();
	cnt=0;
	for(int i=1;i<=n;i++) if(i!=p) a[++cnt].first=X*x[i]+Y*y[i],a[cnt].second=i;
	sort(a+1,a+n);
	a[n].second=p;
/*	for(int i=1;i<=n;i++)
	{
		cout << x[a[i].second] << " " << y[a[i].second] << "*\n";
	}*/
	double ans=1e100; 
	if(p==s)
	{
	//	cout << dis(1,n-1) << "\n";
	//	cout << dis(n,1) << "\n";
		ans=min(ans,dis(n,1)+dis(1,n-1));
		ans=min(ans,dis(n,n-1)+dis(1,n-1));
		printf("%.10lf",ans);
	}
	else
	{
		for(int i=1;i<=n;i++)
			D1[i]=dis(1,i),Dn[i]=dis(n,i),Dn1[i]=dis(n-1,i);
	/*	for(int i=1;i<n-1;i++)
		{
			ans=min(ans,dis(s,1)+dis(1,i)+dis(i,p)+dis(p,i+1)+dis(i+1,n));
			ans=min(ans,dis(s,n)+dis(n,i+1)+dis(i+1,p)+dis(p,i)+dis(i,1));
		}*/
		//cout << dis(2,1) << " " << dis(1,n) << " " << dis(n,3) << " " << dis(3,4) << "\n"; 
	/*	for(int i=1;i<n;i++)
		{
			ans=min(ans,dis())
		}*/
		for(int i=1;i<n;i++)
		{
			if(a[i].second==s)
			{
				ans=min(dis(i,n-1)+dis(n-1,n)+(i==1?0:dis(n,i-1)+dis(i-1,1)),dis(i,1)+dis(1,n)+(i==n-1?0:dis(n-1,i+1)+dis(n,i+1)));
				for(int j=1;j<n-1;j++)
				{
					ans=min(ans,D1[i]+D1[j]+Dn[j]+Dn[j+1]+Dn1[j+1]);
					ans=min(ans,Dn1[i]+Dn1[j+1]+Dn[j+1]+Dn[j]+D1[j]);
				}
				ans=min(ans,dis(i,1)+dis(1,n-1)+dis(n-1,n));
				ans=min(ans,dis(i,n-1)+dis(1,n-1)+dis(n,1));
				break;
			}
		}
		printf("%.10lf",ans);
	}
	return 0;
}