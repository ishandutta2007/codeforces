#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char s[n+5];
	scanf("%s",s);
	int cnt=0;
	int pos=-1;
	for(int i=0;i<n;i++)
    {
        cnt+=((s[i]=='(')?1:-1);
        if(cnt<0)
        {
            pos=i;
            break;
        }
    }
    bool res=1;
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i==pos) continue;
        cnt+=((s[i]=='(')?1:-1);
        if(cnt<0) res=0;
    }
    if(pos!=-1) cnt--;
    if(cnt!=0) res=0;
    if(res) printf("Yes\n");
    else printf("No\n");
	return 0;
}