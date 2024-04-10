#include <iostream>
#include <vector>
using namespace std;
const int N=3003;

int n,m;
pair<int,int> a[N];
int b[N][N]; 
long long ans;
int main()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;++i)
	{
		cin>>a[i].first>>a[i].second;
		b[a[i].first+1000][a[i].second+1000]++;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<i;++j)
		{
			int x,y;
			if((a[i].first+a[j].first)%2)
				continue;
			if((a[i].second+a[j].second)%2)
				continue;
			x=(a[i].first+a[j].first)/2;
			y=(a[i].second+a[j].second)/2;
			ans+=b[x+1000][y+1000];
		}
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}