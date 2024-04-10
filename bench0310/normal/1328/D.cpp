#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> a(n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        bool eq=1;
        bool seq=0;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=a[(i+1)%n]) eq=0;
            if(a[i]==a[(i+1)%n])
            {
                seq=1;
                idx=i;
            }
        }
        int c=0;
        vector<int> res(n,1);
        if(eq) c=1;
        else if((n%2)==0)
        {
            c=2;
            for(int i=1;i<n;i+=2) res[i]=2;
        }
        else if(seq==0)
        {
            c=3;
            for(int i=1;i<n;i+=2) res[i]=2;
            res[n-1]=3;
        }
        else
        {
            c=2;
            for(int i=idx-1;i>=0;i-=2) res[i]=2;
            for(int i=idx+2;i<n;i+=2) res[i]=2;
        }
        printf("%d\n",c);
        for(int i=0;i<n;i++) printf("%d%c",res[i]," \n"[i==n-1]);
    }
    return 0;
}