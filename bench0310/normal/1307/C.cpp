#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[100001];
    scanf("%s",s);
    int n=strlen(s);
    vector<long long> cnt(26,0);
    for(int i=0;i<n;i++) cnt[s[i]-'a']++;
    long long res=0;
    for(int i=0;i<26;i++) res=max(res,cnt[i]);
    vector<vector<long long>> two(26,vector<long long>(26,0));
    for(int i=0;i<n;i++)
    {
        cnt[s[i]-'a']--;
        for(int j=0;j<26;j++) two[s[i]-'a'][j]+=cnt[j];
    }
    for(int i=0;i<26;i++) for(int j=0;j<26;j++) res=max(res,two[i][j]);
    printf("%I64d\n",res);
    return 0;
}