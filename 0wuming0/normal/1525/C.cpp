#include"bits/stdc++.h"
using namespace std;
//int x[300005];
//int op[300005];
int ans[300005];
int st[300005],nn;
struct _
{
    int op;
    int inx;
    int x;
}p[300005];
bool cmp(_ x,_ y)
{
    return x.x<y.x;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char s[10];
        for(int i=0;i<n;i++)
        {
            ans[i]=-1;
            scanf("%d",&p[i].x);
        }
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            if(s[0]=='L')p[i].op=0;
            else p[i].op=1;
            p[i].inx=i;
        }
        sort(p,p+n,cmp);
        nn=0;
        for(int i=0;i<n;i++)if(p[i].x%2)
        {//cout<<i<<endl;
            if(nn==0)st[nn++]=i;
            else
            {
                if(p[i].op)
                {
                    st[nn++]=i;
                }
                else
                {
                    nn--;
                    if(p[st[nn]].op==0)p[st[nn]].x=-p[st[nn]].x;
                    ans[p[st[nn]].inx]=ans[p[i].inx]=(p[i].x-p[st[nn]].x)/2;
                    //cout<<st[nn]<<" "<<i<<" "<<(x[i]-x[st[nn]])/2<<endl;
                }
            }
        }
        while(nn>1)
        {
            nn--;
            if(p[st[nn-1]].op==0)p[st[nn-1]].x=-p[st[nn-1]].x;
            p[st[nn]].x=2*m-p[st[nn]].x;
            ans[p[st[nn]].inx]=ans[p[st[nn-1]].inx]=(p[st[nn]].x-p[st[nn-1]].x)/2;
            //cout<<st[nn]<<" "<<st[nn-1]<<" "<<(x[st[nn]]-x[st[nn-1]])/2<<endl;
            //cout<<x[st[nn]]<<x[st[nn-1]]<<endl;
            nn--;
        }
        nn=0;
        for(int i=0;i<n;i++)if(p[i].x%2==0)
        {//cout<<i<<endl;
            if(nn==0)st[nn++]=i;
            else
            {
                if(p[i].op)
                {
                    st[nn++]=i;
                }
                else
                {
                    nn--;
                    if(p[st[nn]].op==0)p[st[nn]].x=-p[st[nn]].x;
                    ans[p[st[nn]].inx]=ans[p[i].inx]=(p[i].x-p[st[nn]].x)/2;
                    //cout<<st[nn]<<" "<<i<<" "<<(x[i]-x[st[nn]])/2<<endl;
                }
            }
        }
        while(nn>1)
        {
            nn--;
            if(p[st[nn-1]].op==0)p[st[nn-1]].x=-p[st[nn-1]].x;
            p[st[nn]].x=2*m-p[st[nn]].x;
            ans[p[st[nn]].inx]=ans[p[st[nn-1]].inx]=(p[st[nn]].x-p[st[nn-1]].x)/2;
            //cout<<st[nn]<<" "<<st[nn-1]<<" "<<(x[st[nn]]-x[st[nn-1]])/2<<endl;
            //cout<<x[st[nn]]<<x[st[nn-1]]<<endl;
            nn--;
        }
        for(int i=0;i<n;i++)printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}