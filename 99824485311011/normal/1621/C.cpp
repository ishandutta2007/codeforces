#include<bits/stdc++.h>
using namespace std;
inline int ask(int x)
{
    printf("? %d\n",x);
    fflush(stdout);
    int v;
    scanf("%d",&v);
    if(v==0)exit(0);
    return v;
}
int T,n,p[10010];
bool flg[10010];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        fill(flg+1,flg+n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(flg[i])continue;
            vector<int> vec;vec.clear();
            int st=ask(i);vec.push_back(st);
            do
            {
                vec.push_back(ask(i));
            }while(vec.back()!=st);
            for(int j=vec.size()-1;j>=1;j--)p[vec[j-1]]=vec[j],flg[vec[j]]=1;
        }
        printf("! ");
        for(int i=1;i<=n;i++)printf("%d ",p[i]);
        putchar('\n');
        fflush(stdout);
    }
    return 0;
}