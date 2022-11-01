#include <bits/stdc++.h>

using namespace std;

int a[200000];
string s;
string res;

void solve(int l,int r,int low)
{
    if(s.size()>res.size()) res=s;
    if(l>r) return;
    if(max(a[l],a[r])<=low) return;
    if(min(a[l],a[r])<=low)
    {
        if(a[l]>low)
        {
            s+='L';
            solve(l+1,r,a[l]);
        }
        else
        {
            s+='R';
            solve(l,r-1,a[r]);
        }
    }
    else
    {
        if(a[l]<a[r])
        {
            s+='L';
            solve(l+1,r,a[l]);
        }
        else if(a[l]>a[r])
        {
            s+='R';
            solve(l,r-1,a[r]);
        }
        else
        {
            string temp=s;
            s+='L';
            solve(l+1,r,a[l]);
            s=temp;
            s+='R';
            solve(l,r-1,a[r]);
        }
    }
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	solve(0,n-1,0);
	printf("%d\n%s\n",res.size(),res.c_str());
	return 0;
}