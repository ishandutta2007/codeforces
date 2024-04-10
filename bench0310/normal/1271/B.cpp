#include <bits/stdc++.h>

using namespace std;

char sw(char a)
{
    if(a=='B') return 'W';
    else return 'B';
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int w=0;
    int b=0;
    for(int i=0;i<n;i++) w+=(s[i]=='W');
    b=n-w;
    if((b&1)&&(w&1))
    {
        printf("-1\n");
        return 0;
    }
    char t='W';
    if(w&1) t='B';
    vector<int> res;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==t)
        {
            res.push_back(i);
            s[i]=sw(s[i]);
            s[i+1]=sw(s[i+1]);
        }
    }
    printf("%d\n",(int)res.size());
    for(int a:res) printf("%d ",a+1);
    printf("\n");
    return 0;
}