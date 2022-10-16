#include <bits/stdc++.h>

using namespace std;

char sir[100010];
int n;

int solve(int time)
{
    int last=1;
    for(int i=1;i<=n;i++)
        if(sir[i]=='P')
        {
            for(;last<=n && sir[last]!='*';last++);
            if(last>n) return 1;
            if(last<i)
            {
                if(i-last>time) return 0;
                int a=i-last;
                last=max(i+(time-a)/2,i+time-2*a)+1;
            }
            else last=max(last,i+time+1);
        }
    for(;last<=n && sir[last]!='*';last++);
    return last>n;
}

int main()
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    scanf("%d\n%s",&n,sir+1);
    int st=1,dr=2*n+10;
    while(st<=dr)
    {
        int mid=(st+dr)/2;
        if(solve(mid)) dr=mid-1;
        else st=mid+1;
    }
    printf("%d",st);
    return 0;
}