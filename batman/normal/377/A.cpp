#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 550
int n,m,k,ex1[4]={0,1,-1,0},ex2[4]={1,0,0,-1};
bool mark[N][N];
char a[N][N];

void output();

void DFS(int i,int j)
{
    if(a[i][j]!='.' || mark[i][j]==true)
        return ;
    mark[i][j]=true;    
    for(int q=0;q<4;q++)
        DFS(i+ex1[q],j+ex2[q]);
    
    if(k==0)
        output();
    a[i][j]='X';
    if(k>0)
        k--;    
    
    
    
        
}



void output()
{
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                    cout<<a[i][j];
            cout<<endl;     
        }
    exit(0);    
}

int main() {
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='.')
                DFS(i,j);
        }   
    
    
    
            
                
    
    return 0;
}