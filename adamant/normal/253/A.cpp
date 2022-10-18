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
    ofstream out("output.txt");
    ifstream in("input.txt");
    int n,m;
    in>>n>>m;
    
    for(int i=0;i<min(n,m);i++)
    {
            if(n>=m)
            out<<'B'<<'G';
            else
            out<<'G'<<'B';
    }
    int t=min(n,m);
    m-=t;
    n-=t;
    for(int i=0;i<max(n,m);i++)
    {
            if(n>=m)
            out<<'B';
            else
            out<<'G';
    }
    
    out<<endl;
    //system("PAUSE");
    return EXIT_SUCCESS;
}