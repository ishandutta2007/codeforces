#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (201*1000)

ll n,c,now,p[N],t[N],ans1,ans2;

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>c;
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)
	{	
		cin>>t[i];
		now+=t[i];
		ans1+=max(0ll,p[i]-now*c);
	}
	now=0;
	for(int i=n-1;i>=0;i--)
	{
		now+=t[i];
		ans2+=max(0ll,p[i]-now*c);
	}
	cout<<((ans1>ans2)?"Limak":(ans1==ans2)?"Tie":"Radewoosh");
    return 0;
}