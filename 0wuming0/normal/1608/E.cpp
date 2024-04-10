#include"bits/stdc++.h"
using namespace std;
int n;
int save;
int num1[100005];
int num2[100005];
int num3[100005];
vector<pair<int,int> >v[100005];
void solve2(int input[][3])
{
    for(int i=0;i<100005;i++)num1[i]=num2[i]=num3[i]=0;
    for(int i=0;i<n;i++)
    {
        if(input[i][2]==1)
        {
            num1[input[i][0]]++;
            v[input[i][0]].push_back(make_pair(input[i][1],1));
        }
        if(input[i][2]==2)
        {
            num2[input[i][0]]++;
            v[input[i][0]].push_back(make_pair(input[i][1],2));
        }
        if(input[i][2]==3)num3[input[i][0]]++;
    }
    int n1=0,n2=n/3,n3=0;
    for(int l=1,r=100000;l<=r;)
    {
        if(n1<=n3)
        {
            n1+=num1[l];
            n2-=num2[l++];
        }
        else
        {
            n3+=num3[r];
            n2-=num2[r--];
        }
        save=max(min(min(n1,n2),n3),save);
    }
    n1=0,n2=n/3,n3=0;
    for(int l=1,r=100000;l<=r;)
    {
        if(n1<=n3)
        {
            n1+=num2[l];
            n2-=num1[l++];
        }
        else
        {
            n3+=num3[r];
            n2-=num1[r--];
        }
        save=max(min(min(n1,n2),n3),save);
    }
    for(int i=0;i<100005;i++)num1[i]=num2[i]=0;
    for(int i=0;i<n;i++)
    {
        if(input[i][2]==1)num1[input[i][1]]++;
        if(input[i][2]==2)num2[input[i][1]]++;
    }
    n1=0,n2=0,n3=0;
    for(int l=1,r=100000,now=100000;;)
    {
        n3+=num3[now];
        for(auto &pr:v[now])
        {
            if(pr.second==1)
            {
                if(pr.first<l)
                {
                    n1--;
                }
                else
                {
                    num1[pr.first]--;
                }
            }
            else
            {
                if(pr.first>r)
                {
                    n2--;
                }
                else
                {
                    num2[pr.first]--;
                }
            }
        }
        now--;
        while(n1<n3&&l<=r)
        {
            n1+=num1[l++];
        }
        if(n1<n3&&l>r)break;
        while(n2<n3&&l<=r)
        {
            n2+=num2[r--];
        }
        if(n2<n3&&l>r)break;
        save=max(n3,save);
    }
    for(int i=0;i<100005;i++)num1[i]=num2[i]=0;
    for(int i=0;i<n;i++)
    {
        if(input[i][2]==1)num1[input[i][1]]++;
        if(input[i][2]==2)num2[input[i][1]]++;
    }
    n1=0,n2=0,n3=0;
    for(int l=1,r=100000,now=100000;;)
    {
        n3+=num3[now];
        for(auto &pr:v[now])
        {
            if(pr.second==2)
            {
                if(pr.first<l)
                {
                    n2--;
                }
                else
                {
                    num2[pr.first]--;
                }
            }
            else
            {
                if(pr.first>r)
                {
                    n1--;
                }
                else
                {
                    num1[pr.first]--;
                }
            }
        }
        now--;
        while(n2<n3&&l<=r)
        {
            n2+=num2[l++];
        }
        if(n2<n3&&l>r)break;
        while(n1<n3&&l<=r)
        {
            n1+=num1[r--];
        }
        if(n1<n3&&l>r)break;
        save=max(n3,save);
    }
    for(int i=0;i<100005;i++)v[i].clear();
}
void solve(int input[][3])
{
    solve2(input);
    for(int i=0;i<n;i++)
    {
        input[i][2]++;
        if(input[i][2]==4)input[i][2]=1;
    }
    solve2(input);
    for(int i=0;i<n;i++)
    {
        input[i][2]++;
        if(input[i][2]==4)input[i][2]=1;
    }
    solve2(input);
}
int input[100005][3];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&input[i][0],&input[i][1],&input[i][2]);
    }
    map<int,int>mp;
    int cnt=0;
    for(int i=0;i<n;i++)mp[input[i][0]]=1;
    for(auto &pr:mp)pr.second=++cnt;
    for(int i=0;i<n;i++)input[i][0]=mp[input[i][0]];
    cnt=0;mp.clear();
    for(int i=0;i<n;i++)mp[input[i][1]]=1;
    for(auto &pr:mp)pr.second=++cnt;
    for(int i=0;i<n;i++)input[i][1]=mp[input[i][1]];
    solve(input);
    for(int i=0;i<n;i++)input[i][0]=100000-input[i][0];
    solve(input);
    for(int i=0;i<n;i++)swap(input[i][0],input[i][1]);
    solve(input);
    for(int i=0;i<n;i++)input[i][0]=100000-input[i][0];
    solve(input);
    cout<<save*3<<endl;
    return 0;
}