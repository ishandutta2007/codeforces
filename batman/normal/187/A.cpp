#include <bits/stdc++.h>
using namespace std;
#define N (201*1000)

int n,a[N],b[N],pos[N];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i],pos[b[i]]=i;
	for(int i=0;i<n;i++)
	{
		if(!i)continue;
		if(pos[a[i]]<pos[a[i-1]])return cout<<n-i,0;
	}
	cout<<0;
    return 0;
}