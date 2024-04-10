#include"bits/stdc++.h"
using namespace std;
#define NUM 100007
char s[100005];
char t[100005];
int n;
#define next nexts
int next[100005];
int ans[100005],nn;
int solve(int k,int m)
{
    int sum=1e9;
    nn=0;
    int i=0,j=-1;
    next[0]=-1;
    while(t[i])
    {
        if(j==-1||t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
        {
            j=next[j];
        }
    }
    for(i=0,j=0;i<n;)
    {
        if(j==-1||s[i]==t[j])
        {
            i++;
            j++;
            if(j==m)ans[nn++]=i;
        }
        else j=next[j];
    }
    k--;
    for(int i=0;i+k<nn;i++)
    {
        sum=min(sum,ans[i+k]-ans[i]+m);
    }
    if(sum==1e9)sum=-1;
    return sum;
}
#define ll long long
ll hashnum[105];
ll hashnums[1005];
ll hashn(int l,int r)
{
    long long ans=0;
    for(int i=0;i+l<=r;i++)
    {
        ans*=NUM;
        ans+=hashnums[s[l+i]];
    }
    return ans;
}
ll hashn(char r[])
{
    long long ans=0;
    for(int i=0;r[i];i++)
    {
        ans*=NUM;
        ans+=hashnums[r[i]];
    }
    return ans;
}
int preans[100005];
int num[100005];
map<ll,int>mp[100005];
list<int>v[100005];
int main()
{
    srand(1314520);
    scanf("%s",s);
    n=strlen(s);
    int q;
    cin>>q;
    for(int i=0;i<105;i++)hashnum[i]=(rand()+1)*(ll)(rand()+1)*(rand()+1)*(rand()+1)+1;
    for(int i=0;i<1005;i++)hashnums[i]=(rand()+1)*(ll)(rand()+1)*(rand()+1)*(rand()+1)+1;
    for(int I=1;I<=q;I++)
    {
        scanf("%d",num+I);
        scanf("%s",t);
        int len=strlen(t);
        if(len>=100)preans[I]=solve(num[I],len);
        else mp[len][hashn(t)]=I;
    }
    ll pash=1;
    for(int len=1;len<100;len++)if(mp[len].size()!=0*(pash*=NUM))
    {
        ll ans=0;
        for(int i=0;i<len;i++)
        {
            ans*=NUM;
            ans+=hashnums[s[i]];
        }
        for(int i=len;;i++)
        {
            auto it=mp[len].find(ans);
            int pos=it->second;
            if(it!=mp[len].end())
            {
                v[pos].push_back(i);
                if(v[pos].size()==num[pos])
                {
                    if(preans[pos]==0)preans[pos]=i-*v[pos].begin()+len;
                    else preans[pos]=min(i-*v[pos].begin()+len,preans[pos]);
                    v[pos].erase(v[pos].begin());
                }
            }
            if(i>=n)break;
            ans*=NUM;
            ans+=hashnums[s[i]];
            ans-=pash*hashnums[s[i-len]];
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(preans[i]==0)preans[i]=-1;
        printf("%d\n",preans[i]);
    }
    return 0;
}