#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define INF (1000*1000*1000)
#define N (1000*1001)
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");


char s[N];
int a,b,n,x[N];
    
int main()
{
    
    cin>>s>>a>>b;
    n=tool(s);
    int temp=1;
    for(int i=n-1;i>=0;i--)
    {
        x[i]=(x[i+1]+(s[i]-'0')*temp)%b;
        temp=temp*10%b;
    }
        
    //cerr<<x[2]<<endl; 
    int p;
    temp=0; 
    for(p=0;p<n-1;p++)
    {
        temp=((temp*10)+s[p]-'0')%a;
        if(temp==0 && s[p+1]!='0' && x[p+1]==0)
        {
            cout<<"YES"<<endl;
            for(int i=0;i<=p;i++)
                cout<<s[i];
            cout<<endl;
            for(int i=p+1;i<n;i++)
                cout<<s[i];
            cout<<endl;     
            return 0;
            
        }
    }
    cout<<"NO"<<endl;   
    
    
    return 0;
}