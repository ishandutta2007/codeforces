#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],b[200005],a1,a2,neg,pos;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]>0?a[i]=1:a[i]=-1;
	b[1]=a[1];
	for(int i=2;i<=n;i++)
		b[i]=b[i-1]*a[i];
	for(int i=1;i<=n;i++){
		if(b[i]<0)a1+=pos,a2+=neg,neg++,a1++;
		else a1+=neg,a2+=pos,pos++,a2++;
	}
	cout<<a1<<" "<<a2;
    return 0;
}