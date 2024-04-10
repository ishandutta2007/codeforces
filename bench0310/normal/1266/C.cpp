#include <bits/stdc++.h>

using namespace std;

int main()
{
    int r,c;
    scanf("%d%d",&r,&c);
    vector<vector<int>> v(r,vector<int>(c,1));
    if(r==1&&c==1) printf("0\n");
    else if(r==1||c==1)
    {
        int a=2;
        for(int o=0;o<r;o++) for(int i=0;i<c;i++) v[o][i]=a++;
        for(int o=0;o<r;o++) for(int i=0;i<c;i++) printf("%d%c",v[o][i]," \n"[i==c-1]);
    }
    else
    {
        for(int o=0;o<r;o++) for(int i=0;i<c;i++) v[o][i]*=(o+1);
        for(int o=0;o<r;o++) for(int i=0;i<c;i++) v[o][i]*=(i+r+1);
        for(int o=0;o<r;o++) for(int i=0;i<c;i++) printf("%d%c",v[o][i]," \n"[i==c-1]);
    }
    return 0;
}