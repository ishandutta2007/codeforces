#include <iostream>

using namespace std;

int abs(int x)
{
    if(x<0) return -x;
    else return x;
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,x,y,d;
        cin>>n>>x>>y>>d;
        if((abs(x-y)%d)==0)
        {
            cout<<(abs(x-y)/d)<<endl;
            continue;
        }
        int path=1000000000;
        bool good=0;
        if((abs(1-y)%d)==0)
        {
            path=((abs(1-x))+d-1)/d+(abs(1-y)/d);
            good=1;
        }
        if((abs(n-y)%d)==0)
        {
            path=min(((abs(n-x))+d-1)/d+(abs(n-y)/d),path);
            good=1;
        }
        if(good) cout<<path<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}