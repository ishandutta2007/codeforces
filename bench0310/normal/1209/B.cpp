#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char s[n+1];
	scanf("%s",s);
	int now=0;
	for(int i=0;i<n;i++) now+=(s[i]=='1');
	int a[n],b[n];
	for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]);
	int res=now;
	for(int o=1;o<=10000;o++)
    {
        for(int i=0;i<n;i++)
        {
            if(o>=b[i]&&((o-b[i])%a[i])==0)
            {
                now+=(s[i]=='0'?1:(-1));
                s[i]='0'+'1'-s[i];
            }
        }
        res=max(res,now);
    }
    printf("%d\n",res);
	return 0;
}