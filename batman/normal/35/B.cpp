#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (33)

ifstream fin("input.txt");
ofstream fout("output.txt");


ll n,m,k;
string s[N][N];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fin>>n>>m>>k;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)s[i][j]="*";
    while(k--)
    {
        char c;
        fin>>c;
        if(c=='-')
        {    
            bool p=0;
            fin>>c;
            string x;
            fin>>x;
            for(int i=0;i<n;i++)    
                for(int j=0;j<m;j++)
                    if(s[i][j]==x)
                        s[i][j]="*",p=1,fout<<i+1<<" "<<j+1<<"\n";            
            if(!p)fout<<"-1 -1\n";
            continue;            
        }
        fin>>c;
        ll x,y;
        string ex;
        fin>>x>>y>>ex;
        x--,y--;
        bool p=0;
        for(int i=y;i<m;i++)
            if(s[x][i]=="*" && !p)
                s[x][i]=ex,p=1;
        for(int i=x+1;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=="*" && !p)
                    s[i][j]=ex,p=1;
    }
    
    return 0;
}