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

int  p,q;
char a,b;
int main()
{
    
    cin>>a>>b;
    switch(a)
    {
        case '0': 
            p=2;
            break;
        case '1': 
            p=7;
            break;
        case '2': 
            p=2;
            break;
        case '3': 
            p=3;
            break;
        case '4': 
            p=3;
            break;  
        case '5': 
            p=4;
            break;
        case '6': 
            p=2;
            break;
        case '7': 
            p=5;
            break;
        case '8': 
            p=1;
            break;
        case '9': 
            p=2;
            break;                              
    }
    switch(b)
    {
        case '0': 
            p*=2;
            break;
        case '1': 
            p*=7;
            break;
        case '2': 
            p*=2;
            break;
        case '3': 
            p*=3;
            break;
        case '4': 
            p*=3;
            break;  
        case '5': 
            p*=4;
            break;
        case '6': 
            p*=2;
            break;
        case '7': 
            p*=5;
            break;
        case '8': 
            p*=1;
            break;
        case '9': 
            p*=2;
            break;                              
    }   
    cout<<p<<endl;
    return 0;
}