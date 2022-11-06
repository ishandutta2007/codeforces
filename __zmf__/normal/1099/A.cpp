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
int w,h,w1,w2,h1,h2;
int main()
{
	w=read(),h=read(),w1=read(),h1=read(),w2=read(),h2=read();
	if(h2>h1)swap(h1,h2),swap(w1,w2);
	while(h>=0)
	{
		w=w+h;
		if(h==h1)w=max(0,w-w1);
		if(h==h2)w=max(0,w-w2);
		h--;
	}
	cout<<w<<endl;
	return 0;
}