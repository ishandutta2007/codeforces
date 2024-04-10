#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    int s[4];
    for(int i=0;i<4;i++)
    cin>>s[i];
    
    int ch[4]={0,0,0,0};
    
    for(int i=0;i<4;i++)
    {
            for(int j=i;j<4;j++)
            if(s[i]==s[j])
            ch[i]++;
    }
    int ans=0;
    for(int i=0;i<4;i++)
    {
            if(ch[i]==1)
            ans++;
    }
    
    cout<<4-ans<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}