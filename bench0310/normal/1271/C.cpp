#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,sx,sy;
    scanf("%d%d%d",&n,&sx,&sy);
    vector<pair<int,int>> v(8);
    for(int i=0;i<8;i++) v[i]=make_pair(0,i);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(y>sy) v[0].first++;
        if(x>sx&&y>sy) v[1].first++;
        if(x>sx) v[2].first++;
        if(x>sx&&y<sy) v[3].first++;
        if(y<sy) v[4].first++;
        if(x<sx&&y<sy) v[5].first++;
        if(x<sx) v[6].first++;
        if(x<sx&&y>sy) v[7].first++;
    }
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    vector<pair<int,int>> t={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
    printf("%d\n",v[0].first);
    printf("%d %d\n",sx+t[v[0].second].first,sy+t[v[0].second].second);
    return 0;
}