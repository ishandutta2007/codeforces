#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

#define ll long long
#define ld long double

int main(int argc, char *argv[])
{
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size())
    {
    cout<<"NO"<<endl;
    return 0;
    }
    if(a=="1" && b!="1")
    {
    cout<<"NO"<<endl;
    return 0;
    }
    int num1=0,num0=0;
    int nm1=0,nm0=0;
    for(int i=0;i<a.size();i++)
    if(a[i]=='0')
    num0++;
    else
    num1++;
    for(int i=0;i<b.size();i++)
    if(b[i]=='0')
    nm0++;
    else
    nm1++;
    if((num1==0 && nm1) || (nm1==0 && num1))
    {
    cout<<"NO"<<endl;
    return 0;
    }
    cout<<"YES"<<endl;
    return EXIT_SUCCESS;
}