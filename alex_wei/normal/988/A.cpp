#include<bits/stdc++.h>
using namespace std;
int k,n,a[102],t,p[102];
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i],t+=!p[a[i]],p[a[i]]=1;
	if(t<k)cout<<"NO";
	else{
		t=0;
		cout<<"YES\n";
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			if(!p[a[i]])p[a[i]]=1,cout<<i<<" ",t++;
			if(t==k)exit(0);
		}
	}
    return 0;
}