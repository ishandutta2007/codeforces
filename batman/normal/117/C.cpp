#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N (5005)
#define INF ((ll)1e9)

ll n;
char s[N][N];
pair <ll,ll> num[N];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",&s[i]);
        num[i].second=i;
        for(int j=0;j<n;j++)
           num[i].first+=(s[i][j]-'0');
    }   
    sort(num,num+n);
    if(num[0].first==0)
    {
        ll p=1;
        for(int i=1;i<n;i++)
            if(num[i].first!=num[i-1].first+1)
            {
                p=0;
                break;
            }
        if(p){printf("-1");return 0;}       
    }
    for(int i=n-1;i>=0;i--)
    {
        if(num[i].first==i)continue;
        cout<<num[i].second+1<<" ";
        for(int j=0;j<n;j++)
            if(s[num[i].second][j]=='1')
                for(int q=0;q<n;q++)
                    if(s[j][q]=='1' && s[q][num[i].second]=='1')
                    {
                        printf("%d %d",j+1,q+1);
                        return 0;
                    }
    }
    
    return 0;
}