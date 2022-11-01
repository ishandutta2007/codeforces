#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
vector <int> e[110];
long long x[110],y[110],p,a,x1,y1,ans;
bool mark[110];

void dfs(int q)
{
    if(q==y1)
    {
        ans=1;
        return ;
    }
        
    mark[q]=true;
    for(int i=0;i<e[q].size();i++)
        if(mark[e[q][i]]==false)
            dfs(e[q][i]);   
}


int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>x1>>y1;
        if(a==1)
        {
            p++;
            x[p]=x1;
            y[p]=y1;
            for(int j=1;j<p;j++)
            {
                if((x[p]>x[j] && y[j]>x[p]) || (y[p]>x[j] && y[j]>y[p]))
                    e[p].push_back(j);
                if((x[j]>x[p] && y[p]>x[j]) || (y[j]>x[p] && y[p]>y[j]))
                    e[j].push_back(p);  
            }
        }
        else
        {
            dfs(x1);
            if(ans==1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
            ans=0;
            for(int i=0;i<110;i++)
                mark[i]=false;      
                
        }
            
        
        
        
    }
        
        
    return 0;
}