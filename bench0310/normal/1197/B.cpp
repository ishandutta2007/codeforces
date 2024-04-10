#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	vector<int> v(n);
	int pos;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
        if(v[i]==n) pos=i;
    }
    bool res=1;
    int l=pos-1,r=pos+1;
    for(int i=n-1;i>=1;i--)
    {
        bool b=0;
        if(l>=0&&v[l]==i)
        {
            l--;
            b=1;
        }
        if(r<n&&v[r]==i)
        {
            r++;
            b=1;
        }
        if(b==0)
        {
            res=0;
            break;
        }
    }
    if(res) printf("YES\n");
    else printf("NO\n");
	return 0;
}