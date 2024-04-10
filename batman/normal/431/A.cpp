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
    int a[4]={},ans=0;
    string s="";
    for(int i=0;i<4;i++)
        cin>>a[i];
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
            ans+=a[0];
        if(s[i]=='2')
            ans+=a[1];
        if(s[i]=='3')
            ans+=a[2];
        if(s[i]=='4')
            ans+=a[3];          
    }
    cout<<ans<<endl;
    
    return 0;
}