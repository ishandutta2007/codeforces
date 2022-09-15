#include <cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int a[505050];
bool c[505050];
int ac[505050];
vector<int> smooth(vector<int> a)
{
	vector<int> b;
	int n = a.size();
	b.push_back(a[0]);
	for(int i=1; i<n-1; i++)
		b.push_back( (a[i-1] + a[i] + a[i+1] +1 )/3 );
	b.push_back(a[n-1]);
	return b;
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
		scanf("%d",a+i);
	for(int i=1; i<N-1; i++)
	{
		if(a[i-1] != a[i] && a[i] != a[i+1])
			c[i] = true;
	}
	int ans = 0;
	for(int i=N-1; i>=0; i--)
	{
		if(c[i])
			ac[i] = ac[i+1] + 1;
		else
			ac[i] = 0;
		ans = max(ans, ac[i]);
	}
	ans = (ans+1)/2;
	for(int i=0; i<N; i++)
	{
		if(ac[i] != 0)
		{
			if(ac[i]%2)
				for(int j=0;j<ac[i];j++)
					a[j+i] = a[i-1];
			else
			{
				for(int j=0;j<ac[i]/2;j++)
					a[j+i] = a[i-1];
				for(int j=ac[i]/2; j<ac[i]; j++)
					a[j+i] = 1-a[i-1];
			}
			i += ac[i];
		}
	}
	printf("%d \n",ans);
	for(int i=0;i<N;i++) printf("%d ",a[i]);
	return 0;
}