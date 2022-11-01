#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 101*1000
ll n,a[N],l[N],ans=((ll)1e10);
ifstream fin("input.txt");
ofstream fout("output.txt");
int main()
{
	ios_base::sync_with_stdio(0);
	fin>>n;
	for(int i=0;i<n;i++)
		fin>>a[i];
	for(int i=0;i<n;i++)
		l[i]=((i)?l[i-1]:0)+(a[i]>=0);
		
	ll p=0;	
	for(int i=n-1;i>0;i--)
	{
		p+=(a[i]<=0);
		ans=min(ans,p+l[i-1]);
	}	
	fout<<ans;
	return 0;
}