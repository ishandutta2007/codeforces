#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long s,n;
	pair <int,int> xy[1100];
	cin>>s>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		xy[i].first=a;
		xy[i].second=b;
	}
	sort(xy,xy+n);
	for(int i=0;i<n;i++)
	{
		if(xy[i].first>=s)
		{
			cout<<"NO"<<endl;
			return 0;
		}
		s+=xy[i].second;
	}
	cout<<"YES"<<endl;
	return 0;
}