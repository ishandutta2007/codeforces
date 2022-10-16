#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k,d1,d2,a,b,c,m;
int mx(int x,int y,int z){return max(a,max(b,c));} 
signed main()
{
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>k>>d1>>d2;
		a=0,b=d1,c=d1-d2,m=mx(a,b,c);
		if(a+b+c<=k&&(k-a-b-c)%3==0&&c+(k-a-b-c)/3>=0&&(m+(k-a-b-c)/3)*3<=n&&n%3==0){cout<<"yes\n";continue;}
		a=0,b=d1,c=d1+d2,m=mx(a,b,c);
		if(a+b+c<=k&&(k-a-b-c)%3==0&&(m+(k-a-b-c)/3)*3<=n&&n%3==0){cout<<"yes\n";continue;}
		a=d1,b=0,c=d2,m=mx(a,b,c);
		if(a+b+c<=k&&(k-a-b-c)%3==0&&(m+(k-a-b-c)/3)*3<=n&&n%3==0){cout<<"yes\n";continue;}
		a=d2-d1,b=d2,c=0,m=mx(a,b,c);
		if(a+b+c<=k&&(k-a-b-c)%3==0&&a+(k-a-b-c)/3>=0&&(m+(k-a-b-c)/3)*3<=n&&n%3==0){cout<<"yes\n";continue;}
		a=d2+d1,b=d2,c=0,m=mx(a,b,c);
		if(a+b+c<=k&&(k-a-b-c)%3==0&&(m+(k-a-b-c)/3)*3<=n&&n%3==0){cout<<"yes\n";continue;}
		cout<<"no\n";
	}
	return 0; 
}