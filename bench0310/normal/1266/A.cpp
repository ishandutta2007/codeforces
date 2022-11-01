#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[101];
        scanf("%s",s);
        int n=strlen(s);
        vector<int> v(10,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            v[s[i]-'0']++;
            cnt+=(s[i]-'0');
        }
        int even=0;
        for(int i=0;i<10;i+=2) even+=v[i];
        even--;
        if((cnt%3)==0&&v[0]>0&&even>0) printf("red\n");
        else printf("cyan\n");
    }
    return 0;
}