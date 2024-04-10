#include <bits/stdc++.h>

using namespace std;

int main()
{
    int z;
    scanf("%d",&z);
    while(z--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        vector<int> v(7);
        for(int i=0;i<7;i++) v[i]=i+1;
        int res=0;
        for(int mask=0;mask<(1<<7);mask++)
        {
            vector<int> t(3,0);
            int cnt=0;
            for(int i=0;i<7;i++)
            {
                if((mask)&(1<<i))
                {
                    for(int j=0;j<3;j++)
                    {
                        if(v[i]&(1<<j))
                        {
                            t[j]++;
                        }
                    }
                    cnt++;
                }
            }
            if(t[0]<=a&&t[1]<=b&&t[2]<=c) res=max(res,cnt);
        }
        printf("%d\n",res);
    }
    return 0;
}