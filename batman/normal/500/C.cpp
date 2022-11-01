#include <iostream>
#include <vector>
#define N 550
#define M 1100
using namespace std;
vector <int> stack;
int n,m,w[N],a[M],mark[N],ans;

void takebook(int x)
{
    int i;
    for(i=0;i<stack.size();i++)
    {
        if(stack[i]==x)
           break;
        ans+=w[stack[i]];  
    }
    int ex=stack[i];
    for(int j=i;j>0;j--)
        stack[j]=stack[j-1];
    stack[0]=ex;    
    return ;               
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>w[i];
    for(int i=0;i<m;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        if(mark[a[i]]==false)
        {
            mark[a[i]]=true;
            stack.push_back(a[i]);  
        }       
    for(int i=0;i<m;i++)
        takebook(a[i]);
    cout<<ans<<endl;    
    return 0;    
}