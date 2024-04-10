#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;

bool good(char a,char b,char c,char d)
{
    if(a==b&&b==c&&c==d) return 1;
    if(a==b&&c==d) return 1;
    if(a==c&&b==d) return 1;
    if(a==d&&b==c) return 1;
    return 0;
}

int main()
{
	int n;
	scanf("%d",&n);
	char a[n+5],b[n+5];
	scanf("%s%s",a+1,b+1);
	int res=0;
	for(int i=1;i<=n-i+1;i++)
    {
        if(i==n-i+1) res+=(a[i]!=b[i]);
        else
        {
            if(good(a[i],a[n-i+1],b[i],b[n-i+1])) continue;
            bool ok=0;
            for(char c='a';c<='z';c++)
            {
                if(good(c,a[n-i+1],b[i],b[n-i+1])||good(a[i],c,b[i],b[n-i+1])) ok=1;
            }
            if(ok) res++;
            else res+=2;
        }
    }
    printf("%d\n",res);
	return 0;
}