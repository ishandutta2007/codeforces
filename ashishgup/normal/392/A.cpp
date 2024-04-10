#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
int dx[2]={0, 1};
int dy[2]={1, 0};

int dist(int x, int y)
{
    return x*x + y*y;
}

int calc(int x, int y)
{   
    if(y==0)
        return 0;
    if(dist(x, y)>n*n)
        return calc(x-1, y-1);
    int check=0;
    for(int k=0;k<2;k++)
    {
        if(dist(x+dx[k], y+dy[k])>n*n)
            check=1;
    }
    return check + calc(x+1, y);
}

int32_t main()
{
    IOS;
    cin>>n;
    if(n==0)
    {
        cout<<"1";
        return 0;
    }
    cout<<4*calc(1, n-1)+4;
    return 0;
}