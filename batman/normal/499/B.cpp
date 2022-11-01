#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
#define INF (1000*1000*1000)
#define N 3300
#define ll long long
ll tool(char xt[]){ll p=0;for(int i=0;xt[i]!=0;i++)p++;return p;}
void prt(char xt[]){for(int i=0;xt[i]!=0;i++)cout<<xt[i];cout<<"\n";}
ll tavan(ll a,ll b){int p=1;for(int i=0;i<b;i++)p*=a;return p;}
ifstream fin("input.txt");
ofstream fout("output.txt");

int n,m;
string words[N],words2[N],text,ex;
bool mark[N];
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>words[i]>>words2[i];
        if(words[i].size()>words2[i].size())
            mark[i]=true;
    }
    for(int i=0;i<n;i++)
    {
        cin>>text;
        for(int i=0;i<m;i++)
            if(text==words[i])
            {
                if(mark[i]==false)
                    cout<<words[i]<<" ";
                else
                    cout<<words2[i]<<" ";   
            }
    }
    cout<<endl;
    
    return 0;
}