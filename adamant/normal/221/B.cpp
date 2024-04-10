#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    int x;
    cin>>x;
    if(x<10)
    {
    cout<<1<<endl;
    return 0;
    }
    char cx[10];
    bool ch[10];
    itoa(x,cx,10);
    string ccx="";
    ccx+=cx;
    for(int i=0;i<10;i++)
    {
            if(count(ccx.begin(),ccx.end(),i+'0'))
            ch[i]=true;
            else
            ch[i]=false;
    }
    int ans=0;
    for(int i=1;i<sqrt(x)+1;i++)
    {
            //cout<<i<<endl;
            if(!(x%i))
            {
            char dx1[10];
            itoa(i,dx1,10);
            string ddx1="";
            ddx1+=dx1;
            char dx2[10];
            itoa(x/i,dx2,10);
            string ddx2="";
            ddx2+=dx2;
            for(int j=0;j<10;j++)
                    {
                    if(ch[j])
                    if(count(ddx1.begin(),ddx1.end(),j+'0'))
                    {
                    ans++;
                    break;
                    }
                    }
                    if(ddx1!=ddx2)
                    for(int j=0;j<10;j++)
                    {
                    if(ch[j])
                    if(count(ddx2.begin(),ddx2.end(),j+'0'))
                    {
                    ans++;
                    break;
                    }
                    }
            }
            
    }
    cout<<ans<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}