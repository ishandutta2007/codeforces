#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x,y,z,n,a[200005],b[200005],c[200005],ans,f[200005],f2[200005],pos,pos2,gg[200005];
int main()
{
	cin>>x>>y>>z,ans=n=x+y+z;
	for(int i=1;i<=x;i++)
		cin>>a[i];
	for(int i=1;i<=y;i++)
		cin>>b[i];
	for(int i=1;i<=z;i++)
		cin>>c[i];
	sort(a+1,a+x+1);
	sort(b+1,b+y+1);
	sort(c+1,c+z+1);
	pos=1;
	f[0]=x;
	for(int i=1;i<=n;i++){
		if(a[pos]==i)pos++;
		f[i]=i-pos+1+x-pos+1;
	}
	pos=z,pos2=y;
	f2[n+1]=gg[n+1]=z;
	for(int i=n;i>0;i--){
		if(c[pos]==i)pos--;
		else if(b[pos2]==i)pos2--;
		f2[i]=pos+y-pos2;
		gg[i]=min(f2[i],gg[i+1]);
	}
	for(int i=0;i<=n;i++)
		ans=min((ll)ans,(ll)(f[i]+gg[i+1]-(lower_bound(c+1,c+z+1,i)-c-1)));
	cout<<ans;
    return 0;
}