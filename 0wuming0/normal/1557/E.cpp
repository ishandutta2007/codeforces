#include"bits/stdc++.h"
using namespace std;
int pos[10][10];
void add(int &x,int &y,int X,int Y,multimap<int,pair<int,int> >&mp,int val)
{
    if(X>=1&&X<=8&&Y>=1&&Y<=8&&(x!=X||y!=Y)&&(x==X||y==Y||x+y==X+Y||x-y==X-Y))
    {
        mp.insert(make_pair(val,make_pair(X,Y)));
    }
}
void solve()
{
    for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)pos[i][j]=0;
    cout<<"1 1"<<endl;
    string s;
    int x=1,y=1;
    bool flag=1,op=0;
    while(1)
    {
        cin>>s;
        if(s=="Done")break;
        int L,R,D,U;
        L=R=D=U=0;
        for(auto c:s)
        {
            if(c=='L')L=1;
            if(c=='R')R=1;
            if(c=='D')D=1;
            if(c=='U')U=1;
        }
        if(flag)
        {
            if(y==1&&L==0)
            {
                y++;
                cout<<x<<" "<<y<<endl;
            }
            else if(L==1)
            {
                flag=0;
                y=8;
                cout<<x<<" "<<y<<endl;
                for(int i=2;i<=8;i++)for(int j=1;j<=7;j++)pos[i][j]=1;
            }
            else
            {
                flag=0;
                y=1;
                cout<<x<<" "<<y<<endl;
                for(int i=2;i<=8;i++)for(int j=2;j<=8;j++)pos[i][j]=1;
            }
            continue;
        }
        if(L)
        {
            for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)pos[i][j-1]=pos[i][j];
            for(int i=1;i<=8;i++)pos[i][8]=0;
        }
        if(R)
        {
            for(int i=1;i<=8;i++)for(int j=8;j>=1;j--)pos[i][j+1]=pos[i][j];
            for(int i=1;i<=8;i++)pos[i][1]=0;
        }
        if(D)
        {
            for(int i=8;i>=1;i--)for(int j=1;j<=8;j++)pos[i+1][j]=pos[i][j];
            for(int i=1;i<=8;i++)pos[1][i]=0;
        }
        if(U)
        {
            for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)pos[i-1][j]=pos[i][j];
            for(int i=1;i<=8;i++)pos[8][i]=0;
        }
        for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)
        {
            if(i==x||j==y)pos[i][j]=0;
            //if(i+j==x+y||i-j==x-y)pos[i][j]=0;
        }//for(int i=1;i<=8;i++){for(int j=1;j<=8;j++)printf("%d",pos[i][j]);cout<<endl;};
        L=10;R=0;U=10;D=0;
        for(int i=1;i<=8;i++)for(int j=1;j<=8;j++)if(pos[i][j])
        {
            L=min(L,j);R=max(R,j);
            U=min(U,i);D=max(D,i);
        }
        multimap<int,pair<int,int> >mp;
        add(x,y,U-1,L-1,mp,8-R+8-D);
        add(x,y,U-1,R+1,mp,L-1+8-D);
        add(x,y,D+1,L-1,mp,8-R+U-1);//cout<<L<<" "<<R<<" "<<U<<" "<<D<<endl;
        add(x,y,D+1,R+1,mp,L-1+U-1);//for(auto pr:mp)cout<<"<<"<<pr.second.first<<" "<<pr.second.second<<endl;
        x=mp.begin()->second.first;
        y=mp.begin()->second.second;
        cout<<x<<" "<<y<<endl;
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}