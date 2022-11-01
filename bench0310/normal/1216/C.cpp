#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<pair<int,int>> x(6),y(6);
    for(int i=0;i<6;i++)
    {
        scanf("%d%d",&x[i].first,&y[i].first);
        x[i].second=y[i].second=i;
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int a[6],b[6];
    int idx=0;
    int idy=0;
    a[x[0].second]=idx;
    b[y[0].second]=idy;
    for(int i=1;i<6;i++)
    {
        if(x[i].first!=x[i-1].first) idx++;
        if(y[i].first!=y[i-1].first) idy++;
        a[x[i].second]=idx;
        b[y[i].second]=idy;
    }
    bool d[5][5];
    for(int o=0;o<5;o++) for(int i=0;i<5;i++) d[o][i]=0;
    for(int o=b[0];o<b[1];o++) for(int i=a[0];i<a[1];i++) d[o][i]=1;
    for(int o=b[2];o<b[3];o++) for(int i=a[2];i<a[3];i++) d[o][i]=0;
    for(int o=b[4];o<b[5];o++) for(int i=a[4];i<a[5];i++) d[o][i]=0;
    bool res=0;
    for(int o=0;o<5;o++) for(int i=0;i<5;i++) if(d[o][i]) res=1;
    if(res) printf("YES\n");
    else printf("NO\n");
	return 0;
}