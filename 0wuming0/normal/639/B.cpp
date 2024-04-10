#include"bits/stdc++.h"
using namespace std;
vector<pair<int,int> >v;
void add(int x,int y)
{
    v.push_back(make_pair(x,y));
}
int main()
{
    int n,d,h;
    cin>>n>>d>>h;
    if(h*2<d)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(n==2)
    {
        if(h==1&&d==1)
        {
            cout<<"1 2"<<endl;
            return 0;
        }
        else
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=1;i<=h;i++)add(i,i+1);
    if(d==h)
    {
        if(d==1)
        {
            cout<<-1<<endl;
            return 0;
        }
        else
        {
            for(int i=h+2;i<=n;i++)add(2,i);
            for(auto pr:v)
            {
                printf("%d %d\n",pr.first,pr.second);
            }
            return 0;
        }
    }
    add(1,h+2);
    for(int i=h+2;i<=d;i++)add(i,i+1);
    for(int i=d+2;i<=n;i++)add(1,i);
    for(auto pr:v)
    {
        printf("%d %d\n",pr.first,pr.second);
    }
    return 0;
}