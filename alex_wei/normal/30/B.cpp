#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f,m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
void ck(int x,int y,int z)
{
	m[1]=28+(z%4==0);
	if(y<13&&x<=m[y-1]&&(c-z>18||c-z==18&&y<b||c-z==18&&y==b&&x<=a))cout<<"YES",exit(0);
}
int main()
{
	scanf("%d.%d.%d%d.%d.%d",&a,&b,&c,&d,&e,&f);
	ck(d,e,f),ck(d,f,e),ck(e,d,f),ck(e,f,d),ck(f,d,e),ck(f,e,d);
	cout<<"NO";
	return 0;
}