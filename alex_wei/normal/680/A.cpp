#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,k[102],p; 
int main()
{
	cin>>a>>b>>c>>d>>e,k[a]++,k[b]++,k[c]++,k[d]++,k[e]++;
	for(int i=1;i<101;i++)
		if(k[i]>1)
			p=max(p,min(3,k[i])*i);
	cout<<a+b+c+d+e-p;
	return 0;
}