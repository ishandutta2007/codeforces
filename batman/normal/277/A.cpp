#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define N 110
vector <int> e[N];
vector <int> lang[N];
vector <int> langperson[N];
vector <int> alones;
bool mark[N];
int n,m,ans;

ifstream fin("input.txt");

void input()
{
    cin>>n>>m;
    int ex,ex2,ex3;
    for(int i=1;i<=n;i++)
    {
        cin>>ex;
        for(int j=1;j<=ex;j++)
        {
            cin>>ex2;
            lang[ex2].push_back(i);
            langperson[i].push_back(ex2);
            for(int k=0;k<lang[ex2].size()-1;k++)
            {
                ex3=lang[ex2][k];
                e[ex3].push_back(i);
                e[i].push_back(ex3);
            }
        }
    }
}

void DFS(int x)
{
    mark[x]=true;
    
    for(int i=0;i<e[x].size();i++)
    {
        int ex=e[x][i];
        if(mark[ex]==false)
            DFS(ex);
    }
    
}

int main() {
    input();
    /*
    6 2

    0

    0

    2 1 2

    1 1

    1 1

    0
    */
    
    for(int i=1;i<=n;i++)
        if(langperson[i].size()==0)
        {
            alones.push_back(i);
            for(int j=0;j<alones.size()-1;j++)
            {
                e[i].push_back(alones[j]);
                e[alones[j]].push_back(i);
            }
        }
    if(alones.size()>1)
        ans+=alones.size();
    if(n-alones.size()!=0 && alones.size()>1)
        ans--;
    
            
    for(int i=1;i<=n;i++)
        if(mark[i]==false)
        {
            DFS(i);
            ans++;
        }
    
    cout<<ans-1<<endl;
    
    
    return 0;
}