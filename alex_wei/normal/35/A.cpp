#include<bits/stdc++.h>
using namespace std;
int a,p[4];
#define aba ababa
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>a,p[a]=1;
	for(int i=0;i<3;i++){int a,b;cin>>a>>b,swap(p[a],p[b]);}
	for(int i=1;i<4;i++)if(p[i])cout<<i;
	return 0;
}