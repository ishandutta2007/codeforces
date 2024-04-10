#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string in[8];
    bool ok=true;
    for(int i=0;i<8;i++)
    {
    cin>>in[i];
    if(in[i][0]==in[i][7])
    {
                    ok=false;
                    break;
    }
    for(int j=0;j<7;j++)
    if(in[i][j]==in[i][j+1])
    {
                    ok=false;
                    break;
    }
    }
    if(ok)
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;
    
    
    
    
    //system("pause");
    return EXIT_SUCCESS;
}