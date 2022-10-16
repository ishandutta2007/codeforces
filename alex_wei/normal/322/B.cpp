#include<bits/stdc++.h>
using namespace std;
int minn(int a,int b,int c){return min(min(a,b),c);}
int r,g,b,p; 
int main()
{
	cin>>r>>g>>b,p=minn(r,g,b);
	r-=p,g-=p,b-=p;
	if(p>0&&r%3+g%3+b%3==4)p++;
	cout<<p+r/3+g/3+b/3;
	return 0;
}