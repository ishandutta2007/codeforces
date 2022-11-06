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
const int N=1e5+9;
char a[N];
char b[N];
int cnt[256];
int len=9,n,ans;
int main()
{
	cin>>a;
	n=strlen(a);
	for(int i=0;i<n;i++)
		if(a[i]=='a')ans++;
	cout<<max(0,min(ans*2-1,n))<<endl;
	return 0;
}