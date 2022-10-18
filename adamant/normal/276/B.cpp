#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <numeric>
 
using namespace std;
 
#define ll long long
 
int main(int argc, char *argv[])
{
    string a;
    cin>>a;
    
    vector<int> b(26,0);
    for(int i=0;i<a.size();i++)
    b[a[i]-'a']++;
 int nch=0;
    for(int i=0;i<26;i++)
    {
 nch+=b[i]%2;
 }
 if(nch<2)
 cout<<"First"<<endl;
 else if(!(nch%2))
 cout<<"Second"<<endl;
 else
 cout<<"First"<<endl;
    return EXIT_SUCCESS;
}