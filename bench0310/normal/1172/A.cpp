#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a,vector<int> b,int n)
{
    int one=-1;
    for(int i=0;i<n;i++) if(b[i]==1) one=i;
    if(one==-1) return -1;
    for(int i=one+1;i<n;i++)
    {
        if(b[i]!=(i-one+1)) return -1;
    }
    int next=n-one+1;
    vector<bool> v(n+1,0);
    for(int i=0;i<n;i++) v[a[i]]=1;
    int idx=0;
    for(int i=next;i<=n;i++)
    {
        if(v[i]==0) return -1;
        v[b[idx++]]=1;
    }
    return n-next+1;
}

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int one=-1;
    for(int i=0;i<n;i++) if(b[i]==1) one=i;
    int idx;
    if(one!=-1) idx=one+1;
    else idx=0;
    int wait=0;
    for(int i=idx;i<n;i++) if(b[i]>0) wait=max(wait,i-idx-b[i]+2);
    int res=0;
    if(one!=-1) res+=(one+1);
    res+=max(0,wait);
    res+=n;
    int temp=solve(a,b,n);
    if(temp!=-1) res=min(res,temp);
    printf("%d\n",res);
	return 0;
}