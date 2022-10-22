#include <bits/stdc++.h>
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define all(A) A.begin(),A.end()
const int inf=1018181818;
using namespace std;
int n;
int a[105];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int res=0;
	vector <int> vec;
	for(int i=1;i<n-1;i++)
	{
		if(a[i]==0 && a[i-1]==1 && a[i+1]==1)
		{
			a[i+1]=0;
			res++;
		}
//		if(a[i]==0) res++;
	}
//	cout<<vec.size()-1<<endl;
//	int len=0;
//	for(int i=0;i<(int)vec.size()-1;i++)
//	{
//		if(vec[i]+2==vec[i+1])
//		{
//			len++;
//			cout<<len<<endl;
//		}
//		else
//		{
//			res-=len/2;
//			len=0;
//		}
//	}
//	res-=len/2;
	cout<<res<<endl;
	return 0;
}