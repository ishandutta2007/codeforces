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
    string a;
    cin>>a;
    int b;
    cin>>b;
    for(int i=0;i<a.size();i++)
    {
    if(a[i]>='a' && a[i]<='z' && a[i]-'a'<b)
    a[i]-='a'-'A';
    else if(a[i]>='A' && a[i]<='Z' && a[i]-'A'>=b)
    a[i]-='A'-'a';
    }
    cout<<a<<endl;

    return EXIT_SUCCESS;
}