#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    if(n<=2) printf("-1\n");
    else
    {
        vector<vector<int>> v={{9,7,2},{3,5,6},{1,8,4}};
        vector<vector<int>> res(n,vector<int>(n,0));
        int now=1;
        for(int i=0;i+3<n;i++)
        {
            for(int j=i+1;j<n;j++) res[n-i-1][j]=now++;
            res[n-i-1][i]=now++;
            for(int j=0;j<n-i-1;j++) res[j][i]=now++;
        }
        for(int o=0;o<3;o++) for(int i=n-3;i<n;i++) res[o][i]=now-1+v[o][i-(n-3)];
        for(int o=0;o<n;o++) for(int i=0;i<n;i++) printf("%d%c",res[o][i]," \n"[i==n-1]);
    }
    return 0;
}