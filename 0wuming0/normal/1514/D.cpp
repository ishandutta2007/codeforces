#include"bits/stdc++.h"
using namespace std;
int a[300005];
int ans[300005];
struct qus
{
    int l,r;
    int pos;
}s[300005];
bool cmp1(qus x,qus y)
{
    return x.l<y.l;
}
bool cmp2(qus x,qus y)
{
    return x.r<y.r;
}
int save[300005];
int num[300005],mm;
void ins(int k)
{
    save[num[k]]--;
    num[k]++;
    save[num[k]]++;
    if(save[mm+1]>0)mm++;
}
void del(int k)
{
    save[num[k]]--;
    num[k]--;
    save[num[k]]++;
    if(save[mm]==0)mm--;
}
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&s[i].l,&s[i].r);
        s[i].pos=i;
    }
    sort(s+1,s+1+q,cmp1);
    int now=1;
    int add=548;
    for(int mr=add;now!=q+1;mr+=add)
    {
        int ll=now;
        while(now<=q&&s[now].l<=mr)
        {
            now++;
        }
        int rr=now;
        if(ll!=rr)
        {
            sort(s+ll,s+rr,cmp2);
            for(int i=0;i<300005;i++)
            {
                save[i]=0;
                num[i]=0;
            }
            save[1]++;
            num[a[1]]++;
            mm=1;
            int nowl=1,nowr=1;
            for(int i=ll;i<rr;i++)
            {
                while(nowr!=s[i].r)
                {
                    nowr++;
                    ins(a[nowr]);
                }
                if(nowl<s[i].l)
                {
                    while(nowl!=s[i].l)
                    {
                        del(a[nowl]);
                        nowl++;//cout<<"!!!"<<nowl<<" "<<nowr<<"<<"<<save[1]<<save[2]<<save[3]<<endl;
                    }
                }
                else
                {
                    while(nowl!=s[i].l)
                    {
                        nowl--;
                        ins(a[nowl]);
                    }
                }
                {//cout<<"<<<<"<<s[i].l<<" "<<s[i].r<<" "<<mm<<endl;
                    int ss=s[i].r-s[i].l+1;
                    ss=mm-(ss-mm);
                    ans[s[i].pos]=max(1,ss);
                }
            }
        }
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
/*
6 4
2 2 2 2 2 2
1 6
2 4
2 2
2 3
*/