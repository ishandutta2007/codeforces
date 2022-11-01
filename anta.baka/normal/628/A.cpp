#include <bits/stdc++.h>
using namespace std;

int ppow[10]={1,2,4,8,16,32,64,128,256,512};

int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    int n,b,p;
    cin>>n>>b>>p;
    int x=0,y=n*p;
    while(n>1)
    {
        int k=0;
        while(ppow[k+1]<=n)
            k++;
        x+=b*ppow[k]+ppow[k-1];
        n-=ppow[k-1];
    }
    cout<<x<<' '<<y;
    return 0;
}