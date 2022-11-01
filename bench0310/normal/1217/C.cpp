#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	char s[200005];
	while(t--)
    {
        scanf("%s",s);
        int n=strlen(s);
        vector<int> v(n,(s[0]=='1'?0:-1));
        int res=0;
        for(int o=0;o<n;o++)
        {
            if(o>0) v[o]=(s[o]=='1'?o:v[o-1]);
            int a=0;
            for(int i=0;o-i>=0&&i<18;i++)
            {
                if(s[o-i]=='1') a+=(1<<i);
                res+=(a==i+1);
            }
            if(o<18) continue;
            if(a>18&&o-v[o-18]>=a) res++;
        }
        printf("%d\n",res);
    }
	return 0;
}