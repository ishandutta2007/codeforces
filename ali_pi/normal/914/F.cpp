#include<bits/stdc++.h>
using namespace :: std;
int i,j,m,n,p,k,q,X=100004;
bitset<100005>bit[26],E,Ans,Full; 
char c[100005],c1[100005];

int main()
{
		scanf("%s",c+1); n=strlen(c+1);
		scanf("%d",&q); 
		for (i=1;i<=n;++i) Full[i]=1,bit[c[i]-'a'][i]=1;
		for (;q--;)
		{
			int ty,l,r; char s[2]; 
			scanf("%d",&ty);
			if (ty==1)
			{
					scanf("%d%s",&l,&s);
					bit[c[l]-'a'][l]=0;
					bit[s[0]-'a'][l]=1;
					c[l]=s[0];
			}
			else 
			{
					Ans=Full;
					scanf("%d%d",&l,&r); scanf("%s",c1+1); m=strlen(c1+1);
					if (r-l+1<m)
					{
							puts("0");
					}
					else
					{
						for (i=1;i<=m;++i)
						{
							Ans&=bit[c1[i]-'a']>>(i-1);
						}
						r=r-m+1;
						Ans>>=l;
						Ans<<=(X-(r-l+1)+1);
						printf("%d\n",Ans.count());
					}
			}
		}
	return 0;
}