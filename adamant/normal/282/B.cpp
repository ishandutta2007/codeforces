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
    int n;
    cin>>n;
    int*a=new int[n];
    int*g=new int[n];
    int diff=0;
    string ans;
    for(int i=0;i<n;i++)
    {
    cin>>a[i]>>g[i];
    int diff1=diff-a[i];
    int diff2=diff+g[i];
    if(abs(diff1)<=abs(diff2))
    ans.push_back('A'),diff=diff1;
    else
    ans.push_back('G'),diff=diff2;
    }
    
    if(diff<=500)
    cout<<ans<<endl;
    else
    cout<<-1<<endl;

    return EXIT_SUCCESS;
}