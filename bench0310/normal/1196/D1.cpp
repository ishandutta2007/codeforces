#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        char s[n+2];
        scanf("%s",s+1);
        map<char,int> m={{'R',0},{'G',1},{'B',2}};
        string t="RGBRGB";
        int dp[n+1][3];
        dp[0][0]=dp[0][1]=dp[0][2]=0;
        for(int o=1;o<=n;o++) for(int i=0;i<3;i++) dp[o][i]=dp[max(o-3,0)][i]+(s[o]==t[i]);
        int res=k;
        for(int o=1;o+k-1<=n;o++)
        {
            for(int i=0;i<3;i++)
            {
                int now=0;
                for(int j=0;j<min(3,k);j++)
                {
                    int d=(k-1-j)/3;
                    now+=(d+1-(dp[o+j+3*d][m[t[i+j]]]-dp[max(o+j-3,0)][m[t[i+j]]]));
                }
                res=min(res,now);
            }
        }
        printf("%d\n",res);
    }
	return 0;
}