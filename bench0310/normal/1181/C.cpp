#include <bits/stdc++.h>

using namespace std;

int r[1002][1002],d[1002][1002];
int tree[1002][5000];

void build(int idx,int tl,int tr,int col)
{
    if(tl==tr) tree[col][idx]=r[tl][col];
    else
    {
        int tm=(tl+tr)/2;
        build(2*idx,tl,tm,col);
        build(2*idx+1,tm+1,tr,col);
        tree[col][idx]=min(tree[col][2*idx],tree[col][2*idx+1]);
    }
}

int query(int idx,int tl,int tr,int ql,int qr,int col)
{
    if(ql>qr) return 1000000000;
    if(tl==ql&&tr==qr) return tree[col][idx];
    int tm=(tl+tr)/2;
    return min(query(2*idx,tl,tm,ql,min(qr,tm),col),query(2*idx+1,tm+1,tr,max(ql,tm+1),qr,col));
}

int main()
{
	int n,m;
	cin >> n >> m;
	string s[n+2];
	for(int i=0;i<m+2;i++) s[0]+='.';
	for(int i=0;i<m+2;i++) s[n+1]+='.';
	for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i]=('.'+s[i]+'.');
    }
    for(int o=0;o<n+2;o++) for(int i=0;i<m+2;i++) r[o][i]=d[o][i]=0;
    for(int o=1;o<=n;o++) for(int i=m;i>=1;i--) r[o][i]=((s[o][i]==s[o][i+1])?r[o][i+1]+1:1);
    for(int o=n;o>=1;o--) for(int i=1;i<=m;i++) d[o][i]=((s[o][i]==s[o+1][i])?d[o+1][i]+1:1);
    for(int i=1;i<=m;i++) build(1,1,n,i);
    long long res=0;
    for(int o=1;o<=n;o++)
    {
        for(int i=1;i<=m;i++)
        {
            int sz=d[o][i];
            if(d[o+sz][i]!=sz) continue;
            if(d[o+2*sz][i]<sz) continue;
            res+=(long long)query(1,1,n,o,o+3*sz-1,i);
        }
    }
    cout << res << endl;
	return 0;
}