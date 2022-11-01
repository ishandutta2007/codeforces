#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int a,b,c,im=0;
    cin>>a>>b>>c;
    if((a+b)*c>im)
        im=(a+b)*c;
    if(a*(b+c)>im)
        im=a*(b+c);
    if(a*b*c>im)
        im=a*b*c;
    if(a+b+c>im)
        im=a+b+c;
    if(a*b+c>im)
        im=a*b+c;
    if(a+b*c>im)
        im=a+b*c;
    cout<<im<<endl;                 
            
    
    
    return 0;
}