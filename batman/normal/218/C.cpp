#include<iostream>
using namespace std;

int n,ans;
int x[102],y[102];
bool v[102];
void dfs(int i)
{
    v[i]=true;
    for(int j=0;j<n;j++)if(!v[j] && (x[i]==x[j] || y[i]==y[j]))dfs(j);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>x[i]>>y[i];
    for(int i=0;i<n;i++)if(!v[i]){
        dfs(i);
        ans++;
    }
    cout<<ans-1;
    return 0;
}