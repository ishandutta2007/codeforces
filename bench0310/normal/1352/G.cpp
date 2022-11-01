#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n<=3) printf("-1\n");
        else if(n==4) printf("2 4 1 3\n");
        else
        {
            vector<int> v(n+1,0);
            int x=1;
            if((n%2)==0)
            {
                for(int i=1;i<n-5;i+=2) v[i]=x++;
                vector<int> z={5,1,3,0,2,4};
                for(int p:z) v[n-p]=x++;
                for(int i=n-6;i>=1;i-=2) v[i]=x++;
            }
            else
            {
                for(int i=1;i<n-4;i+=2) v[i]=x++;
                vector<int> z={4,1,3,0,2};
                for(int p:z) v[n-p]=x++;
                for(int i=n-5;i>=1;i-=2) v[i]=x++;
            }
            vector<int> res(n+1,0);
            for(int i=1;i<=n;i++) res[v[i]]=i;
            for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
        }
    }
    return 0;
}