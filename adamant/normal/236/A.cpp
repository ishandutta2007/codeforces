#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <numeric>
#include <math.h>

#define u64 long long

using namespace std;

int main(int argc, char *argv[])
{
    string b;
    
    cin>>b;             
 for(int i=0;i<b.size();i++)     
              b.erase(remove(b.begin()+i+1,b.end(),b[i]),b.end());
//cout<<b<<endl;
    if(!(b.size()%2))
    cout<<"CHAT WITH HER!"<<endl;
    else
    cout<<"IGNORE HIM!"<<endl;
    
    
    
    //system("PAUSE");
    return EXIT_SUCCESS;
}