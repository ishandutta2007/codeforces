#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <fstream>

#define u64 long long

using namespace std;


int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");    
    int n;
    in>>n;
    int *tmp=new int[n];
    for(int i=0;i<n;i++)
    in>>tmp[i];
    int ans=0;
    int minu,plu=0;
    if(tmp[0]>-1)
    minu=1;
    else
    minu=0;
    for(int i=1;i<n;i++)
    if(tmp[i]<1)
    plu++;
    ans=minu+plu;
    for(int k=1;k<n-1;k++)   
    {
            if(tmp[k]>-1)
            minu++;
            if(tmp[k]<1)
            plu--;
            if(minu+plu<ans)
            ans=minu+plu;
    }
    out<<ans<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}