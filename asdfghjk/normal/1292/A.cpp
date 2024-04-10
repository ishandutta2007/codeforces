#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,i,j,cnt;
bool v[5][100005];
int main()
{
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d",&i,&j);
		if(j>1&&((v[1][j]&&v[2][j-1])||(v[2][j]&&v[1][j-1])))
			--cnt;
		if(j<n&&((v[1][j]&&v[2][j+1])||(v[2][j]&&v[1][j+1])))
			--cnt;
		if(v[1][j]&&v[2][j])
			--cnt;
		v[i][j]=!v[i][j];
		if(j>1&&((v[1][j]&&v[2][j-1])||(v[2][j]&&v[1][j-1])))
			++cnt;
		if(j<n&&((v[1][j]&&v[2][j+1])||(v[2][j]&&v[1][j+1])))
			++cnt;
		if(v[1][j]&&v[2][j])
			++cnt;
		if(cnt==0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}