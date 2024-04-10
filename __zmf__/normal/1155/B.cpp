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
int n,cnt1,cnt2;
char a[100009];
int main()
{
	cin>>n;
	cin>>a;
	for(int i=0;i<n-10;i++)
		if(a[i]=='8')cnt1++;
		else cnt2++;
	if(cnt1>cnt2)puts("YES");
	else puts("NO");
	return 0;
}