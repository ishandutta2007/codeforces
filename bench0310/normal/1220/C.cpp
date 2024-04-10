#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[500005];
    scanf("%s",s);
    int n=strlen(s);
    vector<bool> losing(26,0);
    for(int i=0;i<n;i++)
    {
        bool winning=0;
        for(int j=0;j<(s[i]-'a');j++) if(losing[j]) winning=1;
        if(winning==0) losing[s[i]-'a']=1;
        if(winning) printf("Ann\n");
        else printf("Mike\n");
    }
	return 0;
}