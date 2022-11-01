#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	scanf("%d",&q);
	char s[101],t[101];
	while(q--)
    {
        scanf("%s%s",s,t);
        vector<bool> a(26,0);
        bool res=0;
        for(int i=0;s[i];i++) a[s[i]-'a']=1;
        for(int i=0;t[i];i++) if(a[t[i]-'a']) res=1;
        if(res) printf("YES\n");
        else printf("NO\n");
    }
	return 0;
}