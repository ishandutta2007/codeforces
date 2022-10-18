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
    u64 n;
    in>>n;
    char*at=new char[n];
    for(int i=0;i<n;i++)
    {
            in>>at[i];
    }
    
    for(int i=0;i<n/2;i++)
    {
            if(at[i]=='L')
            out<<i+1<<' '<<n/2+i+1<<endl;
            else
            out<<n/2+i+1<<' '<<i+1<<endl;
    }
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}