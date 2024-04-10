#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,ap[10002],cnt,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		int pd[10];
		memset(pd,0,sizeof(pd));
		pd[a%10]=pd[(a/10)%10]=pd[(a/100)%10]=pd[a/1000]=1;
		for(int j=123;j<9877;j++){
			int p=j%10,q=(j/10)%10,r=(j/100)%10,s=j/1000;
			if(p==q||q==r||r==s||p==r||q==s||p==s)continue;
			int bb=0,tot=0;
			if(p==a%10)bb++;
			if(q==(a/10)%10)bb++;
			if(r==(a/100)%10)bb++;
			if(s==a/1000)bb++;
			tot=pd[j%10]+pd[(j/10)%10]+pd[(j/100)%10]+pd[j/1000];
			if(bb==b&&tot-bb==c)ap[j]++;
		}
	}
	for(int i=123;i<9877;i++)
		if(ap[i]==n)
			cnt++,ans=i;
	if(!cnt)cout<<"Incorrect data";
	else if(cnt>1)cout<<"Need more data";
	else cout<<ans/1000<<ans/100%10<<ans/10%10<<ans%10;
	return 0;
}