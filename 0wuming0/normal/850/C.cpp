/*
#include"bits/stdc++.h"
using namespace std;
const int n=50;
int ans[n][n];
int solve(int i,int j)
{
    set<int>s;
    int m=max(i,j);
    for(int k=1;k<=m;k++)
    {
        int ii=i,jj=j;
        if(ii>=k)ii-=k;
        if(jj>=k)jj-=k;
        s.insert(ans[ii][jj]);
    }
    for(int k=0;;k++)
    {
        if(s.find(k)==s.end())return k;
    }
}
int ans2[n][n][n];
int solve(int i,int j,int k)
{
    set<int>s;
    int m=max(max(i,j),k);
    for(int c=1;c<m;c++)
    {
        int ii=i,jj=j,kk=k;
        if(ii>=c)ii-=c;
        if(jj>=c)jj-=c;
        if(kk>=c)jj-=c;
        s.insert(ans2[ii][jj][kk]);
    }
    for(int i=0;;i++)
    {
        if(s.find(i)==s.end())return i;
    }
}
int pr(int i,int j)
{
    return ans[i][j];
    if((min(i,j)^(max(i,j)-min(i,j)))==ans[i][j])return -1;
    else return ans[i][j];
}
int main()
{
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)
    {
        ans[i][j]=ans[j][i]=solve(i,j);
        ans2[i][j][0]=ans2[i][0][j]=ans2[0][i][j]=ans2[j][i][0]=ans2[j][0][i]=ans2[0][j][i]=ans[i][j];
    }
    for(int i=1;i<n;i++)for(int j=1;j<n;j++)for(int k=1;k<n;k++)
    {
        ans2[i][j][k]=ans2[i][k][j]=ans2[k][i][j]=ans2[j][i][k]=ans2[j][k][i]=ans2[k][j][i]=solve(i,j,k);
    }
    int k=14;
    for(int i=0;i<n;i++)for(int j=0;j<=k;j++)printf("%d%c",pr(i,j),"\t\n"[j==k]);
    cout<<"-----------------------------------"<<endl<<endl<<endl<<endl;
    int n=5;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)for(int k=0;k<n;k++)
    {
        int ii=min(min(i,j),k);
        int kk=max(max(i,j),k);
        int jj=i+j+k-ii-kk;//cout<<ii<<" "<<jj<<" "<<kk<<endl;
        kk-=jj;
        jj-=ii;
        if(ans2[i][j][k]!=(ii^jj^kk))printf("<<%d\t%d\t%d\t<<%d\t%d\n",i,j,k,ans2[i][j][k],(ii^jj^kk));
    }
    return 0;
}
1       0       0       2       2       3       3       4       4
0       2       3       1       1       1       4       4       5
0       3       3       2       4       4       5       1       1
2       1       2       4       5       3       0       0       0
2       1       4       5       5       4       6       6       3
3       1       4       3       4       6       7       5       5
3       4       5       0       6       7       7       6       8
4       4       1       0       6       5       6       8       9
4       5       1       0       3       5       8       9       9
5       5       1       0       6       7       8       7       8
5       6       1       0       7       2       6       7       10
6       6       7       6       3       2       8       9       10
6       7       7       8       0       2       8       7       8
7       7       8       8       0       2       8       5       10
7       8       8       9       0       2       9       9       10
8       8       6       9       0       2       1       3       6
8       9       6       9       0       2       1       3       7
9       9       6       9       0       10      1       3       10
9       10      6       7       10      10      1       3       11
*/
#include"bits/stdc++.h"
using namespace std;
int ans[1048576];
int solve(int n)
{
    if(n<1048576&&ans[n]!=-1)return ans[n];
    bool save[40]={0};
    for(int i=0;(1u<<i)<=n;i++)
    {
        save[solve((n>>(i+1))|(n%(1u<<i)))]=1;
    }
    for(int i=0;;i++)if(!save[i])
    {
        if(n<1048576)ans[n]=i;
        return i;
    }
}

int main()
{
    for(int i=1;i<1048576;i++)ans[i]=-1;
    for(int i=1;i<1048576;i++)solve(i);
    //for(int i=1;i<1000;i++)cout<<i<<" "<<ans[i]<<endl;
    /*
    for(int i=1;i<20;i++)for(int j=1;j<10;j++)
    {
        printf("%d%c",ans[(1<<(i-1))|(1<<(j-1))],"\t\n"[j==9]);
    }
    */
    map<int,int>mp;
    int n;
    cin>>n;
    for(int j=0;j<n;j++)
    {
        int a;
        cin>>a;
        for(int i=2;i*i<=a;i++)
        {
            if(a%i==0)
            {
                int s=0;
                if(mp.find(i)==mp.end())mp[i]=0;
                while(a%i==0)
                {
                    a/=i;
                    s++;
                }
                mp[i]|=(1<<(s-1));
            }
        }
        if(a>1)
        {
            if(mp.find(a)==mp.end())mp[a]=0;
            mp[a]|=1;
        }
    }
    int t=0;
    for(auto a:mp)
    {
        t^=solve(a.second);
    }
    if(t)cout<<"Mojtaba"<<endl;
    else cout<<"Arpa"<<endl;
    //cout<<solve(152754856)<<endl;
    return 0;
}
//*/