#include<bits/stdc++.h>
using namespace std;
const int N=55;
char c[N][N];
bool b[N];
vector<int>v;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		scanf("%s",c[i]+1);
	for (int i=1;i<=n;++i)
		if (!b[i])
		{
			for (int j=1;j<=m;++j)
				if (c[i][j]=='#')
					v.push_back(j);
			for (int k=i+1;k<=n;++k)
			{
				unsigned sum=0;
				for (unsigned l=0;l<v.size();++l)
					if (c[k][v[l]]=='#')
						++sum;
				if (sum)
				{
					bool p=1;
					for (int l=1;l<=m;++l)
						if (c[i][l]!=c[k][l])
							p=0;
					if (p)
						b[k]=1;
					else
					{
						// cout<<i<<' '<<k<<endl;
						puts("No");
						return 0;
					}
				}
			}
			v.clear();
		}
	puts("Yes");
	return 0;
}