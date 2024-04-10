#include"bits/stdc++.h"
using namespace std;
vector<int>x,y;
int ans[1000][4],nn;
void add(int x1,int y1,int x2,int y2)
{
    if(x1==x2&&y1==y2)return;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    ans[nn][0]=x1;
    ans[nn][1]=y1;
    ans[nn][2]=x2;
    ans[nn++][3]=y2;
}
void solve(int x1,int y1)
{
    add(x1,y1,x1,y[1]);
    add(x1,y[1],x[1],y[1]);
}
int main()
{
    int x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    x.push_back(x1);x.push_back(x2);x.push_back(x3);
    y.push_back(y1);y.push_back(y2);y.push_back(y3);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    solve(x1,y1);
    solve(x2,y2);
    solve(x3,y3);
    cout<<nn<<endl;
    for(int i=0;i<nn;i++)printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    return 0;
}