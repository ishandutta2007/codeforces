#include <cstdlib>
#include <iostream>
#include <math.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
    int a,b,k;
bool*pr;
int limon=1000010;
void build(){
 for(int i=2;i<=sqrt(b);i++)
  for(int j=i*2;j<=b;j+=i)
   pr[j]=false;
}

int main(int argc, char *argv[])
{
    
    int n,x,y,px=-1,py=-1,cnt=1,ret=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
            cin>>x>>y;
            if(x==px && y==py) cnt++;
            else cnt=1;
            ret=max(ret,cnt);
            px=x;
            py=y;
    }
    cout<<ret<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}