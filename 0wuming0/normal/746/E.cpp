#include"bits/stdc++.h"
using namespace std;
int a[200005];
int n,m;
int use[400005];
struct _
{
    int k;
    int pos;
}save[200005];
bool cmp(_ x,_ y)
{
    return x.k<y.k;
}
vector<_> now;
vector<_> wrong;
void add(vector<_> &v,_ &data)
{
    v.push_back(data);
}
int main()
{
    cin>>n>>m;
    int odd,even;
    odd=even=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        save[i].pos=i;
        save[i].k=a[i];
        if(a[i]<400005)use[a[i]]++;
    }
    sort(save+1,save+1+n,cmp);
    add(now,save[1]);
    for(int i=2;i<=n;i++)
    {
        if(save[i].k!=save[i-1].k)add(now,save[i]);
        else add(wrong,save[i]);
    }
    for(vector<_>::iterator it=now.begin();it!=now.end();++it)if(it->k>m)
    {
        if(it->k%2)odd++;
        else even++;
    }
    odd+=m/2+m%2;
    even+=m/2;
    if(min(odd,even)*2<n)
    {
        putchar('-');
        putchar('1');
        return 0;
    }
    odd=even=0;
    for(vector<_>::iterator it=now.begin();it!=now.end();++it)
    {
        if(it->k%2)odd++;
        else even++;
    }
    if(odd>n/2)
    {
        for(vector<_>::iterator it=now.begin();it!=now.end();++it)
        {
            if(it->k%2)
            {
                add(wrong,*it);
                odd--;
            }
            if(odd==n/2)break;
        }
    }
    else if(even>n/2)
    {
        for(vector<_>::iterator it=now.begin();it!=now.end();++it)
        {
            if(it->k%2==0)
            {
                add(wrong,*it);
                even--;
            }
            if(even==n/2)break;
        }
    }
    for(vector<_>::iterator it=wrong.begin();it!=wrong.end();++it)
    {
        if(it->k<400005)use[it->k]--;
    }
    int oddpos=1,evenpos=2;
    for(vector<_>::iterator it=wrong.begin();it!=wrong.end();++it)
    {
        while(use[oddpos])oddpos+=2;
        while(use[evenpos])evenpos+=2;
        if(odd!=n/2)
        {
            odd++;
            a[it->pos]=oddpos;
            oddpos+=2;
        }
        else
        {
            even++;
            a[it->pos]=evenpos;
            evenpos+=2;
        }
    }
    cout<<wrong.size()<<endl;
    for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}
/*
6 7
2 4 6 1 8 12
*/