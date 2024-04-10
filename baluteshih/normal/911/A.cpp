#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];

int main()
{
	int n,i,mi=1e9+1,ans,last;
	cin >> n,ans=n;
	for(i=0;i<n;i++)
		cin >> arr[i],mi=min(mi,arr[i]);
	for(last=0;arr[last]!=mi;last++) ;
	for(i=last+1;i<n;i++)
		if(arr[i]==mi) ans=min(i-last,ans),last=i;
	cout << ans << "\n";
}