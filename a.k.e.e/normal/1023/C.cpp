#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
const int MAXN=200005;

int n,k;
char s[MAXN];
bool vis[MAXN];
int cnt[MAXN],las[MAXN];

int main()
{
    cin>>n>>k;
    scanf("%s",s+1);
    for(int i=1;i<=n && k<n;i++)
    {
    	if(s[i]=='(')
		{
			cnt[i]=cnt[i-1]+1;
			las[cnt[i]]=i;
		}
    	else
		{
			cnt[i]=cnt[i-1];
			k+=2;
			vis[las[cnt[i]]]=vis[i]=1;
			las[cnt[i]]=0;
			if(k==n)break;
			cnt[i]--;
		}
    }
    for(int i=1;i<=n;i++)
    	if(!vis[i])printf("%c",s[i]);
    printf("\n");
    return 0;
}