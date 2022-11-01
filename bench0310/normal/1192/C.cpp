#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

const long long mod=998244353;
const int eps=62;
set<string> s;
long long num[11][eps][eps];
long long f[eps][eps][eps][eps];
long long g[eps][eps][eps];
string alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int sz;

int id(char a)
{
    if('a'<=a&&a<='z') return a-'a';
    else if('A'<=a&&a<='Z') return a-'A'+26;
    else return a-'0'+52;
}

void modify(long long &a)
{
    if(a>=mod) a%=mod;
}

long long part(int a,int b,int c,int d)
{
    vector<int> v={a,b,c,d};
    long long res=0;
    do {res++;}
    while(next_permutation(v.begin(),v.end()));
    return res;
}

void ini()
{
    for(int a=0;a<eps;a++)
    {
        for(int b=a;b<eps;b++)
        {
            for(int c=b;c<eps;c++)
            {
                for(int x=0;x<eps;x++)
                {
                    f[a][b][c][x]=1;
                    f[a][b][c][x]*=num[sz][a][x];
                    modify(f[a][b][c][x]);
                    f[a][b][c][x]*=num[sz][b][x];
                    modify(f[a][b][c][x]);
                    f[a][b][c][x]*=num[sz][c][x];
                    modify(f[a][b][c][x]);
                }
            }
        }
    }
    for(int a=0;a<eps;a++)
    {
        for(int b=a;b<eps;b++)
        {
            for(int c=b;c<eps;c++)
            {
                g[a][b][c]=0;
                for(int x=0;x<eps;x++)
                {
                    g[a][b][c]+=f[a][b][c][x];
                    modify(g[a][b][c]);
                }
            }
        }
    }
}

long long solve()
{
    long long res=0;
    for(int a=0;a<eps;a++)
    {
        for(int b=a;b<eps;b++)
        {
            for(int c=b;c<eps;c++)
            {
                for(int d=c;d<eps;d++)
                {
                    long long now=1;
                    now*=g[a][b][c];
                    modify(now);
                    now*=g[a][b][d];
                    modify(now);
                    now*=g[a][c][d];
                    modify(now);
                    now*=g[b][c][d];
                    modify(now);
                    now*=part(a,b,c,d);
                    modify(now);
                    res+=now;
                    modify(res);
                }
            }
        }
    }
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    set<int> pos;
    while(n--)
    {
        char temp[11];
        scanf("%s",temp);
        string t(temp);
        s.insert(t);
        reverse(t.begin(),t.end());
        s.insert(t);
        pos.insert(t.size());
    }
    for(string z:s) num[z.size()][id(z[0])][id(z.back())]++;
    long long res=0;
    for(int z:pos)
    {
        sz=z;
        ini();
        res+=solve();
        modify(res);
    }
    printf("%I64d\n",res);
    return 0;
}