#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
    {
        int n,m;
        cin >> n >> m;
        string s[n];
        for(int i=0;i<n;i++) cin >> s[i];
        vector<int> rmin(27,n),rmax(27,-1),cmin(27,m),cmax(27,-1);
        bool vis[n][m];
        int a=95;
        for(int o=0;o<n;o++)
        {
            for(int i=0;i<m;i++)
            {
                vis[o][i]=0;
                if(s[o][i]=='.') continue;
                a=max(a,(int)s[o][i]);
                int id=(s[o][i]-'a');
                rmin[id]=min(rmin[id],o);
                rmax[id]=max(rmax[id],o);
                cmin[id]=min(cmin[id],i);
                cmax[id]=max(cmax[id],i);
            }
        }
        if(a==95)
        {
            printf("YES\n0\n");
            continue;
        }
        a-=97;
        bool pos=1;
        int e,f;
        for(int id=a;id>=0;id--)
        {
            char now=(char)(id+'a');
            if(rmax[id]==-1)
            {
                rmin[id]=rmax[id]=e;
                cmin[id]=cmax[id]=f;
                continue;
            }
            if(rmin[id]==rmax[id]||cmin[id]==cmax[id])
            {
                for(int o=rmin[id];o<=rmax[id];o++)
                {
                    for(int i=cmin[id];i<=cmax[id];i++)
                    {
                        if(vis[o][i]==1) continue;
                        if(s[o][i]!=now) pos=0;
                        vis[o][i]=1;
                        e=o;
                        f=i;
                    }
                }
            }
            else pos=0;
            if(pos==0) break;
        }
        if(pos)
        {
            printf("YES\n");
            printf("%d\n",a+1);
            for(int i=0;i<=(int)(a);i++) printf("%d %d %d %d\n",rmin[i]+1,cmin[i]+1,rmax[i]+1,cmax[i]+1);
        }
        else printf("NO\n");
    }
	return 0;
}