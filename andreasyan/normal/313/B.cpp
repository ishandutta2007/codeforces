#include <iostream>
using namespace std;

struct ban
{
	int l,r;
};
int n,m,prefix[100005];
ban a[100005];
char b[100005];
int main()
{
	int i,j;
	cin>>b;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i].l>>a[i].r;
	m=strlen(b);
	////////////////////////]
	for(i=1;i<m;i++)
	{
		if(b[i]==b[i-1])
			prefix[i]=prefix[i-1]+1;
		else
			prefix[i]=prefix[i-1];
	}
	for(i=0;i<n;i++)
	{
		cout<<prefix[a[i].r-1]-prefix[a[i].l-1]<<endl;
	}
	return 0; 
}