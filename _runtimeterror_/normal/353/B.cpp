#include<iostream>
#include<vector>

using namespace std;


vector<int> f[100];
int ans[201];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=2*n;++i)
    {
        int x;
        scanf("%d",&x);
        f[x].push_back(i);
    }
    vector<int> t;
    int cur = 0;
    int ax = 0 , bx = 0;
    for(int i=1;i<100;++i)
    {
        if(f[i].size()==1)
            t.push_back(f[i][0]);
        else if(!f[i].empty())
        {
            ++ax,++bx;
            for(int k:f[i])
                ans[k] = cur, cur ^= 1;
        }
    }
    for(int j:t)
    {
        (cur)?++bx:++ax;
        ans[j] = cur, cur^=1;
    }
    printf("%d\n",ax*bx);
    for(int i=1;i<=2*n;++i)
        printf("%d ",++ans[i]);

}