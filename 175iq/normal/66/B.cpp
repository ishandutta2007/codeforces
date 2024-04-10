#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	std::vector<int> A(n,0);
	int ans=INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i] ;
	}
    int left,right;
	for (int i = 0; i < n; ++i)
	{
		left=i;
		right=i;
		while(left>=1 && A[left]>=A[left-1])
		{
			left--;
		}
		while(right<=(n-2) && A[right]>=A[right+1])
		{
			right++;
		}
		ans=max(ans,abs(left-i)+abs(right-i)+1);
	}
	cout<<ans;
	return 0;
}