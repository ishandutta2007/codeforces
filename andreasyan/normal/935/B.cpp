#include <iostream>
using namespace std;
const int N=100005;

int n,ans;
char a[N];
int main()
{
    cin>>n;
    cin>>a;
    int x=0;
    int y=0;
    bool z=false;
    for(int i=0;i<n;++i)
    {
        int nx=x,ny=y;
        if(a[i]=='U')
            x++;
        else if(a[i]=='R')
            y++;
        if(i==0)
        {
            if(a[i]=='U')
                z=true;
            continue;
        }
        if(nx==ny && z==false && a[i]=='U')
        {
            ++ans;
            z=true;
        }
        if(nx==ny && z==true && a[i]=='R')
        {
            ++ans;
            z=false;
        }
    }
    cout<<ans<<endl;
    return 0;
}