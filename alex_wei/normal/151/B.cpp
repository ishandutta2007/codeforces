#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,tx[105],piz[105],g[105];
string s[105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x>>s[i];
		for(int j=1;j<=x;j++){
			char a,b,c,d,e,f;
			cin>>a>>b>>c>>c>>d>>e>>e>>f;
			if(a==b&&b==c&&c==d&d==e&&e==f)tx[i]++;
			else if(a>b&&b>c&&c>d&&d>e&&e>f)piz[i]++;
			else g[i]++;
		}
	}
	int pos=0,p=0;
	for(int i=1;i<=n;i++)if(tx[i]>tx[pos])pos=i;
	cout<<"If you want to call a taxi, you should call: ";
	for(int i=1;i<=n;i++)if(tx[i]==tx[pos])cout<<(p==0?"":", ")<<s[i],p=1;
	cout<<".\n";
	pos=p=0;
	for(int i=1;i<=n;i++)if(piz[i]>piz[pos])pos=i;
	cout<<"If you want to order a pizza, you should call: ";
	for(int i=1;i<=n;i++)if(piz[i]==piz[pos])cout<<(p==0?"":", ")<<s[i],p=1;
	cout<<".\n";
	pos=p=0;
	for(int i=1;i<=n;i++)if(g[i]>g[pos])pos=i;
	cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
	for(int i=1;i<=n;i++)if(g[i]==g[pos])cout<<(p==0?"":", ")<<s[i],p=1;
	cout<<".\n";
	return 0;
}