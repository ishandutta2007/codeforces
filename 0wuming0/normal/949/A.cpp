#include"bits/stdc++.h"
using namespace std;
char s[200005];
vector<int>v[200005];
int nn;
int now;
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1')
        {
            if(now==nn)
            {
                cout<<-1<<endl;
                return 0;
            }
            else
            {
                v[now].push_back(i);
                now++;
            }
        }
        else
        {
            if(now)
            {
                v[now-1].push_back(i);
                now--;
            }
            else
            {
                v[nn].push_back(i);
                nn++;
            }
        }
    }
    if(now)cout<<-1<<endl;
    else
    {
        cout<<nn<<endl;
        for(int i=0;i<nn;i++)
        {
            printf("%d",v[i].size());
            for(vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
            {
                printf(" %d",*it);
            }
            putchar(10);
        }
    }
    return 0;
}