#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=505;

int n;
char s[MAXN][MAXN];
int d[5][2]={0,0,1,1,1,-1,-1,1,-1,-1};

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%s",s[i]+1);
    int ans=0;
    for(int i=2;i<n;i++)
    	for(int j=2;j<n;j++)
    	{
    		bool flag=1;
    		for(int k=0;k<5;k++)
    		{
    			int x=i+d[k][0],y=j+d[k][1];
    			if(s[x][y]=='.')flag=0;
    		}
    		if(flag)++ans;
    	}
    cout<<ans<<endl;
    return 0;
}