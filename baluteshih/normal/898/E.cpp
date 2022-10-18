#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

struct mode
{
	long long data,move;
	void get()
	{
		long long tmp=sqrt(data);
		move=min(data-tmp*tmp,(tmp+1)*(tmp+1)-data);
	}
}arr[200001];

bool yee(mode a,mode b)
{
	if(a.move==b.move) return a.data<b.data;
	return a.move<b.move;
}

int main()
{
	long long n,i,ans=0;
	cin >> n;
	for(i=0;i<n;i++)
		cin >> arr[i].data,arr[i].get();
	sort(arr,arr+n,yee);
	if(arr[n/2-1].move==0)
	{
		for(i=n/2;i<n;i++)
			if(arr[i].move!=0) break;
			else if(arr[i].data==0) ans+=2;
			else ans++;
	}
	else
	{
		for(i=0;i<n/2;i++)
			ans+=arr[i].move;
	}
	cout << ans << "\n";
}