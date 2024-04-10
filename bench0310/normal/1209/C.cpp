#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        scanf("%d",&n);
        char d[n+1];
        scanf("%s",d);
        vector<int> v(n);
        for(int i=0;i<n;i++) v[i]=(d[i]-'0');
        bool found=0;
        for(int o=0;o<=9;o++)
        {
            char s[n+1];
            bool b=0;
            for(int i=0;i<n;i++)
            {
                if(v[i]<o) s[i]='1';
                else if(v[i]>o)
                {
                    s[i]='2';
                    b=1;
                }
                else
                {
                    if(b) s[i]='1';
                    else s[i]='2';
                }
            }
            s[n]='\0';
            bool ok=1;
            int last=0;
            for(char o='1';o<='2';o++)
            {
                for(int i=0;i<n;i++)
                {
                    if(s[i]==o)
                    {
                        if(last>v[i]) ok=0;
                        last=v[i];
                    }
                }
            }
            if(ok)
            {
                printf("%s\n",s);
                found=1;
                break;
            }
        }
        if(found==0) printf("-\n");
    }
	return 0;
}