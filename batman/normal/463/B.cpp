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
long long n,a,maxim;
int main() {
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>maxim)
            maxim=a;
    }
    cout<<maxim;
    return 0;
}