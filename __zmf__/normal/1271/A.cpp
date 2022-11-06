//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int a,b,c,d,e,f;
int main()
{
	a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
	int qwq=min(b,c);
	if(a+qwq<=d)cout<<a*e+qwq*f<<endl;
	else if(e>f)cout<<min(a,d)*e+max(0,d-a)*f<<endl;
	else cout<<min(qwq,d)*f+max(0,d-qwq)*e<<endl;
	return 0;
}