#include"bits/stdc++.h"
using namespace std;
int get(int y)
{
    cout<<y<<endl;
    int t;
    cin>>t;
    if(t==0)exit(0);
    return t;
}
int m,n;
int q[100],qnum;
int solve()
{
    int x1=1,x2=m,x;
    while(x1+1!=x2)
    {
        x=(x1+x2)/2;
        int t=get(x);
        if(q[qnum]==0)t*=-1;
        qnum++;
        qnum%=n;
        if(t<0)x2=x;
        else x1=x+1;
    }
    get(x1);
    return 0;
}
int main()
{
    cin>>m>>n;
    for(int i=0;i<n;i++)
    {
        if(get(m)<0)q[i]=1;
    }
    solve();
    return 0;
}