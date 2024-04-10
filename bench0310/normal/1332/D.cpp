#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x;
    scanf("%d",&x);
    vector<vector<int>> res(3,vector<int>(3,(1<<17)+x));
    res[1][1]-=(1<<17);
    res[2][2]-=(1<<17);
    res[0][2]-=x;
    res[2][0]-=x;
    printf("3 3\n");
    for(int o=0;o<3;o++) for(int i=0;i<3;i++) printf("%d%c",res[o][i]," \n"[i==2]);
    return 0;
}