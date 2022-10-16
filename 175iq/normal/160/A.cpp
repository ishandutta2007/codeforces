#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> vec(n,0);
	int sum=0;
	for (int i = 0; i < n; i++)
	{
		cin>>vec[i];
		sum+=vec[i];
	}
	sort(vec.begin(),vec.end(),greater<int>()) ;
	int temp_sum=0;  
	int thresh=sum/2; 
	int i=0;
	for (i = 0; i < n; i++)
	{
		temp_sum+=vec[i];
		if(temp_sum>thresh)
		{
			break;
		}
	}
	int ans=i+1;
	cout<<ans<<endl;
	return 0;
}