#include<bits/stdc++.h>
using namespace std;
int a=50,b=50,c,d,n,m;
char p[51][51]; 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>p[i][j];
			if(p[i][j]=='*')
				a=min(a,i),b=min(b,j),c=max(c,i),d=max(d,j);
		}
	for(int i=a;i<=c;i++){
		for(int j=b;j<=d;j++)
			cout<<p[i][j];
		cout<<endl;
	}
    return 0;
}