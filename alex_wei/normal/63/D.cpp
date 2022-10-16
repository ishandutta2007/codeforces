#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,k[27],n,x,y,rem;
char ch[55][105];
int main()
{
	cin>>a>>b>>c>>d>>n,cout<<"YES\n";
	for(int i=1;i<=max(b,d);i++)
		for(int j=1;j<=a+c;j++)
			ch[i][j]='.';
	for(int i=1;i<=n;i++)cin>>k[i];
	if(b%2)x=b,y=0;
	else x=b,y=a+1;
	rem=a*b;
	for(int i=1;i<=n;i++){
		int cnt=min(rem,k[i]);
		k[i]-=cnt,rem-=cnt;
		for(int j=0;j<cnt;j++){
			if(x%2)y++;
			else y--;
			if(y>a)x--,y=a;
			if(y<1)x--,y=1;
			ch[x][y]=i+'a'-1;
		}
		if(!rem)break;
	}
	x=1,y=a,rem=c*d;
	for(int i=1;i<=n;i++){
		int cnt=min(rem,k[i]);
		k[i]-=cnt,rem-=cnt;
		for(int j=0;j<cnt;j++){
			if(x%2)y++;
			else y--;
			if(y>a+c)x++,y=a+c;
			if(y<=a)x++,y=a+1;
			ch[x][y]=i+'a'-1;
		}
		if(!rem)break;
	}
	for(int i=1;i<=max(b,d);i++){
		for(int j=1;j<=a+c;j++)
			cout<<ch[i][j];
		cout<<endl;
	}
	return 0;
}