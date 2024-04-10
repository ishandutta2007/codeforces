#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ap[100005];
map <ll,int> x,y;
vector <int> g[100005];
int main()
{
	cin>>n;
	for(int i=3;i<=n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		if(!x[a*n+b])x[a*n+b]=c;
		else y[a*n+b]=c;
		if(!x[b*n+a])x[b*n+a]=c;
		else y[b*n+a]=c;
		if(!x[c*n+b])x[c*n+b]=a;
		else y[c*n+b]=a;
		if(!x[c*n+a])x[c*n+a]=b;
		else y[c*n+a]=b;
		if(!x[b*n+c])x[b*n+c]=a;
		else y[b*n+c]=a;
		if(!x[a*n+c])x[a*n+c]=b;
		else y[a*n+c]=b;
		ap[a]++,ap[b]++,ap[c]++;
		g[a].push_back(b);
		g[a].push_back(c);
		g[b].push_back(a);
		g[b].push_back(c);
		g[c].push_back(a);
		g[c].push_back(b);
	}
	int pos,pos2,pos3;
	for(int i=1;i<=n;i++)
		if(ap[i]==1)
			{pos=i;break;}
	pos2=ap[g[pos][0]]==2?g[pos][0]:g[pos][1];
	pos3=x[pos2*n+pos];
	cout<<pos<<" "<<pos2<<" ";
	for(int i=3;i<=n;i++){
		cout<<pos3<<" ";
		int nw=0;
		if(x[pos2*n+pos3]==pos)nw=y[pos2*n+pos3];
		else nw=x[pos2*n+pos3];
		pos=pos2,pos2=pos3,pos3=nw;
	}
    return 0;
}