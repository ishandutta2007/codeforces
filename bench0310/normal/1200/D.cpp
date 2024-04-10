#include <bits/stdc++.h>

using namespace std;

const int N=2005;
int d[N][N];

void add(int ra,int ca,int rb,int cb)
{
    ra=max(ra,0);
    ca=max(ca,0);
    for(int o=ra;o<=rb;o++)
    {
        d[o][ca]++;
        d[o][cb+1]--;
    }
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char s[n][n+1];
	for(int i=0;i<n;i++) scanf("%s",s[i]);
	int cnt=0;
	//rows
	for(int o=0;o<n;o++)
    {
        int l=-1;
        int r;
        for(int i=0;i<n;i++)
        {
            if(s[o][i]=='B')
            {
                if(l==-1) l=i;
                r=i;
            }
        }
        if(l==-1) cnt++;
        else if(r-k+1<=l) add(o-k+1,r-k+1,o,l);
    }
    //columns
    for(int i=0;i<n;i++)
    {
        int l=-1;
        int r;
        for(int o=0;o<n;o++)
        {
            if(s[o][i]=='B')
            {
                if(l==-1) l=o;
                r=o;
            }
        }
        if(l==-1) cnt++;
        else if(r-k+1<=l) add(r-k+1,i-k+1,l,i);
    }
    int now=0;
    int res=0;
    for(int o=0;o<=n;o++)
    {
        for(int i=0;i<=n;i++)
        {
            now+=d[o][i];
            res=max(res,now);
        }
    }
    printf("%d\n",res+cnt);
	return 0;
}