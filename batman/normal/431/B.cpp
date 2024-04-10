#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N (100*1001)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

int a[6][6],maxim;
char s[6];
bool mark[6];


void make()
{
    int ans=0;
    for(int i=1;i<5;i++)
        for(int j=i;j<5;j+=2)
            ans+=a[s[j]][s[j+1]]+a[s[j+1]][s[j]];
    if(ans>maxim)
        maxim=ans;
}

void calc(int x)
{
    if(x==6)
    {
        make();
        return ;
    }
    for(int i=1;i<6;i++)
        if(mark[i]==false)
        {
            s[x]=i;
            mark[i]=true;
            calc(x+1);
            mark[i]=false;
        }
}

int main()
{
    for(int i=1;i<6;i++)
        for(int j=1;j<6;j++)
            cin>>a[i][j];
            
    calc(1);
    cout<<maxim<<endl;
    return 0;
}