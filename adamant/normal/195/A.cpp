#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <numeric>

#define u64 long long

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    double a,b,c;
    
    cin>>a>>b>>c;
    
    //cout<<int(0.6)<<endl;
    
    cout<<max((int(a*c/b + 0.999999)-int(c)),0)<<endl;
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}