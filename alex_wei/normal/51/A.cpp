#include<bits/stdc++.h>
using namespace std;
#define ll long long
map <int,bool> p;
char a,b,c,d; 
int n,e,f,g,h,w,x,y,z,ans;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c>>d;
		e=a^48,f=b^48,g=c^48,h=d^48;
		w=e*343+f*49+g*7+h;
		x=f*343+h*49+e*7+g;
		y=h*343+g*49+f*7+e;
		z=g*343+e*49+h*7+f;
		ans+=!p[w];
		p[w]=p[x]=p[y]=p[z]=1;
		if(i<n)cin>>a>>b;
	}
	cout<<ans;
	return 0;
}