#include"bits/stdc++.h"
using namespace std;
int a[100005];
int b[100005];
int c[100005];
map<int,int>need[100005];
int ans[100005];
int app[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        for(int i=0;i<n;i++)scanf("%d",b+i);
        for(int i=0;i<m;i++)scanf("%d",c+i);
        for(int i=0;i<=n;i++)app[i]=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])need[b[i]][i+1]=1;
            app[b[i]]=i;
        }//cout<<"?"<<app[1]<<endl;
        int now=1;
        for(int i=0;i<m;i++)
        {
            //cout<<"!!"<<i<<"  "<<need[9].size()<<endl;
            //cout<<"^^"<<ans[0]<<endl;
            if(need[c[i]].size())
            {
                ans[i]=((need[c[i]].begin())->first);//cout<<"??"<<((need[c[i]].begin())->first)<<endl;
                need[c[i]].erase(need[c[i]].begin());//cout<<"ok"<<endl;
            }
            else
            {
                for(;now<=n;now++)
                {
                    if(need[now].size())break;
                }
                if(now<=n)
                {
                    ans[i]=(need[now].begin())->first;//cout<<"!!!"<<i<<"  "<<ans[i]<<endl;
                }
                else
                {//cout<<"ok"<<endl;
                    if(app[c[m-1]]==-1)
                    {
                        cout<<"NO"<<endl;
                        goto ne;
                    }
                    else
                    {
                        int kk=app[c[m-1]]+1;
                        for(;i<m;i++)ans[i]=kk;//cout<<"!!!"<<i<<"  "<<ans[i]<<endl;
                        goto ko;
                    }
                }
            }
        }
        for(int i=0;i<=n;i++)if(need[i].size())
        {
            cout<<"NO"<<endl;
            goto ne;
        }
        ko:;
        cout<<"YES"<<endl;//cout<<ans[0]<<endl;
        for(int i=0;i<m;i++)printf("%d%c",ans[i]," \n"[i==m-1]);
        ne:;
        for(int i=0;i<=n;i++)need[i].clear();
    }
    return 0;
}
/*
1
10 5
7 3 2 1 7 9 4 2 7 9
9 9 2 1 4 9 4 2 3 9
9 9 7 4 3

6
1 1
1
1
1
5 2
1 2 2 1 1
1 2 2 1 1
1 2
3 3
2 2 2
2 2 2
2 3 2
10 5
7 3 2 1 7 9 4 2 7 9
9 9 2 1 4 9 4 2 3 9
9 9 7 4 3
5 2
1 2 2 1 1
1 2 2 1 1
3 3
6 4
3 4 2 4 1 2
2 3 1 3 1 1
2 2 3 4
*/