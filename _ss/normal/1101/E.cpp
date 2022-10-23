#include <iostream>

using namespace std;
struct bg
{
    char c;int x,y;
};

bg a[1000001];
int main()
{
    int n,maxx=0,maxy=0,x,y;
    char c;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i].c>>a[i].x>>a[i].y;
        if (a[i].x>a[i].y) swap(a[i].x,a[i].y);
    }
    for (int i=1;i<=n;i++)
    {
        //cin>>c;
        //while (c!='+' && c!='?') cin>>c;
        //cin>>x>>y;
        //if (x>y) swap(x,y);
        if (a[i].c=='+')
        {
            maxx=max(a[i].x,maxx);
            maxy=max(a[i].y,maxy);
        }
        else
        {
            if (maxx<=a[i].x && maxy<=a[i].y) cout<<"YES"; else cout<<"NO";
            cout<<"\n";
        }
    }
    return 0;
}