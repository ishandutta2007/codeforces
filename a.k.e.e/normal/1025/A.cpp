#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
const int MAXN=100005;

int n;
char s[MAXN];
int cnt[MAXN];

int main()
{
    cin>>n>>s+1;
    int flag=0;
    if(n==1)flag=1;
    for(int i=1;i<=n;i++)
    {
    	cnt[s[i]-'a']++;
    	if(cnt[s[i]-'a']>=2)flag=1;
    }
    if(flag)printf("Yes\n");
    else printf("No\n");
    return 0;
}