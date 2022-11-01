#include <bits/stdc++.h>

using namespace std;

const int inf=1000000000;
const int N=105;
const int M=1000005;
int n;
int m;
int d[N][N];
int p[M];
vector<int> best(M,inf);
vector<int> res(M);

void solve(int idx,int cnt,int last)
{
    //cout << "in " << idx << endl;
    if(cnt>=best[idx]) return;
    best[idx]=cnt;
    res[idx]=last;
    for(int j=min(n,m-idx);j>=1;j--)
    {
        //cout << "j=" << j << " || d=" << d[p[idx]][p[idx+j]] << endl;
        if(p[idx]!=p[idx+j]&&j==d[p[idx]][p[idx+j]]) solve(idx+j,cnt+1,idx);
    }
}

int main()
{
	scanf("%d",&n);
	for(int o=1;o<=n;o++) for(int i=1;i<=n;i++) d[o][i]=inf;
	for(int o=1;o<=n;o++)
    {
        char s[n+5];
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) if(s[i]=='1') d[o][i]=1;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d",&p[i]);
    solve(1,1,-1);
    printf("%d\n",best[m]);
    vector<int> v;
    int now=m;
    while(now!=-1)
    {
        v.push_back(p[now]);
        now=res[now];
    }
    reverse(v.begin(),v.end());
    for(int t:v) printf("%d ",t);
    printf("\n");
	return 0;
}