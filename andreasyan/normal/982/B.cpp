#include <bits/stdc++.h>
using namespace std;
const int N=200003;
struct ban2
{
    int x,w;
};
bool operator<(const ban2& a,const ban2& b)
{
    return a.w>b.w;
}

struct ban1
{
    int x,w;
};
bool operator<(const ban1& a,const ban1& b)
{
    return a.w<b.w;
};

int n;
int a[N*2];
char b[N*2];

int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    cin>>b;
    priority_queue<ban2> q2;
    priority_queue<ban1> q1;
    for(int i=0;i<n;++i)
    {
        ban2 t;
        t.x=i;
        t.w=a[i];
        q2.push(t);
    }
    for(int i=0;i<n*2;++i)
    {
        if(b[i]=='0')
        {
            ban2 t=q2.top();
            q2.pop();
            cout<<t.x+1<<' ';
            ban1 t1;
            t1.x=t.x;
            t1.w=t.w;
            q1.push(t1);
        }
        else
        {
            ban1 t=q1.top();
            q1.pop();
            cout<<t.x+1<<' ';
        }
    }
    cout<<endl;
    return 0;
}