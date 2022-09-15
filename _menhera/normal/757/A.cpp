#include<cstdio>
#include<algorithm>
using namespace std;
char a[101010];
int cnt[101010];
int main()
{
    scanf("%s",a);
    for(int i=0; a[i]; i++)
        cnt[a[i]]++;
    int ans = 101010;
    ans = min(cnt['B'],ans);
    ans = min(cnt['u']/2,ans);
    ans = min(cnt['l'],ans);
    ans = min(cnt['b'],ans);
    ans = min(cnt['a']/2,ans);
    ans = min(cnt['s'],ans);
    ans = min(cnt['r'],ans);
    printf("%d",ans);
    return 0;
}