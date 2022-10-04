#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN=500005;

int n,cur;
struct Data
{
    int a,id;
    bool operator <(const Data &b)const
        {return a<b.a;}
    /*bool operator >(const Data &b)const
        {return a>b.a;}*/
    Data(int a=0,int id=0):a(a),id(id){}
}d[MAXN];
char s[MAXN];
priority_queue<Data,vector<Data>,less<Data> > pq;
int vis[MAXN];

int main()
{
    Data t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d[i].a);
        d[i].id=i;
    }
    sort(d+1,d+n+1);
    scanf("%s",s+1);
    cur=0;
    for(int i=1;i<=2*n;i++)
        if(s[i]=='0')
        {
            cur++;
            printf("%d ",d[cur].id);
            pq.push(d[cur]);
        }
        else
        {
            t=pq.top();pq.pop();
            printf("%d ",t.id);
        }
    return 0;
}