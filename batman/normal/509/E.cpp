#include <bits/stdc++.h>
using namespace std;
string s;
double l[501000],n,sum,ans;
int main()
{
	cin>>s;
	n=s.size();
	for(int i=1;i<=n;i++)l[i]=l[i-1]+(s[i-1]=='I' || s[i-1]=='A' || s[i-1]=='Y' || s[i-1]=='U' || s[i-1]=='O' || s[i-1]=='E');
	for(int i=1;i<=n;i++)
		sum+=l[(int)n-i+1]-l[i-1],ans+=sum/i;
	cout<<fixed<<setprecision(10)<<ans;	
    return 0;
}