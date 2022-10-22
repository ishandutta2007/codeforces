#include<bits/stdc++.h>
using namespace std;
int n;
int x[2000],y[2000],x2[2000],y2[2000
],az1,az2;
bool p[2009],zl;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
		cin>>x2[i]>>y2[i];
	for(int i=1;i<=n;i++){
	memset(p,0,sizeof(p));
	//int az1,az2;
	az1=x[1]+x2[i];
	az2=y[1]+y2[i];
	bool ax=0;
	p[i]=1;
	for(int j=2;j<=n;j++){
	 zl=0;
	for(int k=1;k<=n;k++)
	if(p[k]==0&&x[j]+x2[k]==az1&&y[j]+y2[k]==az2)
	{p[k]=1;zl=1;break;}
	if(!zl)break;
	if(j==n&&zl)ax=1;
	}
	if(ax)break;
	}
	cout<<az1<<' '<<az2;
	return 0;
}