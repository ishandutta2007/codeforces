#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1000000007;
struct ban
{
	int m,z;
};

int n,ans,m;
int a[100005];
ban t;
int main()
{
	int i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++)
		if(a[i]>a[0] && a[i]<a[n-1])
			ans++;
	cout<<ans<<endl;
//	system("pause");
	return 0;
}