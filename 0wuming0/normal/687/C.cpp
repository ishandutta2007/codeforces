#include"bits/stdc++.h"
using namespace std;
bool dp[505][505];
bool save[505][505];
int main()
{
    int n,k;
    cin>>n>>k;
    dp[0][0]=1;
    while(n--)
    {
        int a;
        scanf("%d",&a);
        for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)save[i][j]=0;
        for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)if(dp[i][j])
        {
            save[i][j]=1;
            if(i+a<=500)
            {
                save[i+a][j]=1;
                if(j+a<=500)save[i+a][j+a]=1;
            }
        }
        for(int i=0;i<=500;i++)for(int j=0;j<=500;j++)dp[i][j]=save[i][j];
    }
    vector<int>v;
    for(int i=0;i<=500;i++)
    {
        if(dp[k][i])v.push_back(i);
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)printf("%d%c",v[i]," \n"[i==v.size()-1]);
    return 0;
}