#include<bits/stdc++.h>
using namespace std;
long long n,k[100002],c,a;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a,c+=a;
	for(int i=1;i<=n;i++)cin>>k[i];
	sort(k+1,k+(int)n+1);
	if(c<=k[n]+k[n-1])cout<<"YES";
	else cout<<"NO";
    return 0;
}