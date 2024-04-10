#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    char s[100001];
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        vector<int> v(26,0);
        for(int i=0;i<n;i++) v[s[i]-'A']++;
        int x=n,y=n;
        for(char a:{'L','R'}) x=min(x,v[a-'A']);
        for(char a:{'D','U'}) y=min(y,v[a-'A']);
        if(x>0&&y>0)
        {
            printf("%d\n",2*(x+y));
            for(int i=0;i<x;i++) printf("R");
            for(int i=0;i<y;i++) printf("U");
            for(int i=0;i<x;i++) printf("L");
            for(int i=0;i<y;i++) printf("D");
            printf("\n");
        }
        else if(x>0) printf("2\nLR\n");
        else if(y>0) printf("2\nDU\n");
        else printf("0\n\n");
    }
    return 0;
}