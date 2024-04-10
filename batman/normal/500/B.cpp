#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF (1000*1000*1000)
#define N (330)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");


int main()
{
    int n,a[N];
    string s[N];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>s[i];  
    for(int k=0;k<n;k++)    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s[i][k]=='1' && s[k][j]=='1')
                    s[i][j]=s[j][i]='1';
        
    for(int i=0;i<n;i++)
    {
        int minim=INF,index=0;  
        for(int j=i+1;j<n;j++)
            if(s[i][j]=='1' && a[j]<minim)
                minim=a[j],index=j;
        if(minim<a[i])
        {
            int ex=a[i];
            a[i]=a[index];
            a[index]=ex;
        }
                        
    }
        
    
            
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";        
    
    
    return 0;
}