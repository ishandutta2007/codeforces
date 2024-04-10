#include <iostream>
#include <vector>

using namespace std;

int min3(int a,int b,int c)
{
    return min(min(a,b),c);
}

int max3(int a,int b,int c)
{
    return max(max(a,b),c);
}

int abs(int a)
{
    if(a<0) return -a;
    else return a;
}

bool maze[8][1001][1001];

void solve(int x1,int y1,int x2,int y2,bool first,int idx) //0-x,1-y
{
    maze[idx][y1][x1]=1;
    maze[idx][y2][x2]=1;
    if(first==0)
    {
        while(x1!=x2)
        {
            if(x1<x2)
            {
                x1++;
                maze[idx][y1][x1]=1;
            }
            else
            {
                x1--;
                maze[idx][y1][x1]=1;
            }
        }
        while(y1!=y2)
        {
            if(y1<y2)
            {
                y1++;
                maze[idx][y1][x1]=1;
            }
            else
            {
                y1--;
                maze[idx][y1][x1]=1;
            }
        }
    }
    else
    {
        while(y1!=y2)
        {
            if(y1<y2)
            {
                y1++;
                maze[idx][y1][x1]=1;
            }
            else
            {
                y1--;
                maze[idx][y1][x1]=1;
            }
        }
        while(x1!=x2)
        {
            if(x1<x2)
            {
                x1++;
                maze[idx][y1][x1]=1;
            }
            else
            {
                x1--;
                maze[idx][y1][x1]=1;
            }
        }
    }
}

int main()
{
    int ax,ay,bx,by,cx,cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    int x,y,mx=1000000,my=1000000;
    for(int i=min3(ax,bx,cx);i<=max3(ax,bx,cx);i++)
    {
        if(abs(ax-i)+abs(bx-i)+abs(cx-i)<mx)
        {
            x=i;
            mx=abs(ax-i)+abs(bx-i)+abs(cx-i);
        }
    }
    for(int i=min3(ay,by,cy);i<=max3(ay,by,cy);i++)
    {
        if(abs(ay-i)+abs(by-i)+abs(cy-i)<my)
        {
            y=i;
            my=abs(ay-i)+abs(by-i)+abs(cy-i);
        }
    }
    for(int a=0;a<2;a++)
    {
        for(int b=0;b<2;b++)
        {
            for(int c=0;c<2;c++)
            {
                int idx=4*a+2*b+c;
                solve(ax,ay,x,y,a,idx);
                solve(bx,by,x,y,b,idx);
                solve(cx,cy,x,y,c,idx);
            }
        }
    }
    vector<pair<int,int> > v[8];
    int m=10000000,id;
    for(int d=0;d<8;d++)
    {
        int cnt=0;
        for(int o=0;o<1001;o++)
        {
            for(int i=0;i<1001;i++)
            {
                if(maze[d][o][i])
                {
                    cnt++;
                    v[d].push_back(make_pair(o,i));
                }
            }
        }
        if(cnt<m)
        {
            m=cnt;
            id=d;
        }
    }
    cout << v[id].size() << endl;
    for(int i=0;i<(int)v[id].size();i++) cout << v[id][i].second << " " << v[id][i].first << endl;
    return 0;
}