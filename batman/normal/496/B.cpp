#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N (1100)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
string a,ans,now;

int main()
{
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++)
        ans+='9';
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<n;j++)
        {
            now="";
            for(int k=0;k<n;k++)
                now+=((a[(j+k)%n]+i)%10 + '0');
            if(now<ans)
                ans=now;
        }
    }   
    cout<<ans<<endl;
    
    return 0;
}