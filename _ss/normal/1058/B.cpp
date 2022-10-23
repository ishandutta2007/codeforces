#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double
const ll maxn=1e2+1;
struct toado
{
    ld x,y;
};
int n,m,d;
toado a[10];
ld s=0;

ld area(ld x1,ld y1,ld x2,ld y2,ld x3,ld y3)
{
    return abs((x2-x1)*(y2+y1)+(x3-x2)*(y3+y2)+(x1-x3)*(y1+y3))/2;
}

bool check(ld x,ld y)
{
    ld st=0;
    for (int i=1;i<=4;i++)
        st+=area(a[i].x,a[i].y,a[i+1].x,a[i+1].y,x,y);
    return st==s;
}
int main()
{
    cin>>n>>d>>m;
    a[1].x=0;
    a[1].y=d;
    a[2].x=d;
    a[2].y=0;
    a[3].x=n;
    a[3].y=n-d;
    a[4].x=n-d;
    a[4].y=n;
    a[5]=a[1];
    for (int i=1;i<=4;i++) s+=(a[i+1].x-a[i].x)*(a[i+1].y+a[i].y);
    s=abs(s)/2;
    int x,y;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        if (check(x,y)) cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
    return 0;
}