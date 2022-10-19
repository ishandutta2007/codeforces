#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>>
using namespace std;
const int N=200005;

int n,k;
int a[N],b[N];
bool c[N];
bool stg()
{
    queue<int> q;
    stack<int> s;
    for(int i=0;i<n;++i)
        q.push(a[i]);
    int b=0;
    while(1)
    {
        if(b==n)
            return true;
        if(!s.empty() && s.top()==b+1)
        {
            s.pop();
            b++;
        }
        else
        {
            if(q.empty())
                return false;
            s.push(q.front());
            q.pop();
        }
    }
    return true;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<k;++i)
    {
        cin>>a[i];
        b[i]=a[i];
        c[a[i]]=true;
    }
    sort(b,b+k);
    for(int i=0;i<k;++i)
    {
        for(int j=b[i]-1;j>0 && !c[j];--j)
        {
            a[k++]=j;
        }
    }
    for(int j=n;j>0 && !c[j];--j)
    {
        a[k++]=j;
    }
    if(stg())
    {
        for(int i=0;i<n;++i)
            cout<<a[i]<<' ';
        cout<<endl;
    }
    else
    {
        cout<<"-1"<<endl;
    }
    return 0;
}