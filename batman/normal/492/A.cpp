#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1000*1000*1000)
#define N 
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,cubes,i;

int main()
{
    cin>>n;
    for(i=1;;i++)
    {
        if(cubes+(i*(i+1))/2 <=n)
            cubes+=(i*(i+1))/2;
        else
            break;  
    }
    cout<<i-1<<endl;
    
    
    
    
    
    return 0;
}