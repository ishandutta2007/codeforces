#include <bits/stdc++.h>

using namespace std;

vector<int> bit(int a)
{
    vector<int> v(32,0);
    int idx=0;
    while(a)
    {
        if(a&1) v[idx]++;
        a/=2;
        idx++;
    }
    return v;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	vector<int> v(32,0);
	for(int o=0;o<n;o++)
    {
        int t;
        scanf("%d",&t);
        vector<int> d=bit(t);
        for(int i=0;i<32;i++) v[i]+=d[i];
    }
    while(q--)
    {
        vector<int> b=v;
        int t;
        scanf("%d",&t);
        vector<int> d=bit(t);
        int idx=31;
        bool ok=1;
        int res=0;
        for(int i=31;i>=0;i--)
        {
            if(d[i]==0) continue;
            idx=min(idx,i);
            int cnt=(1<<i);
            while(idx>=0&&cnt>0)
            {
                int a=min(b[idx],cnt/(1<<idx));
                cnt-=a*(1<<idx);
                res+=a;
                b[idx]-=a;
                if(a==0) idx--;
            }
            if(cnt!=0)
            {
                ok=0;
                break;
            }
        }
        if(ok) printf("%d\n",res);
        else printf("-1\n");
    }
	return 0;
}