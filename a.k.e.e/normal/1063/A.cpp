#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;char s[MAXN];
int c[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%s",&n,s+1);
    sort(s+1,s+n+1);
    printf("%s\n",s+1);
    return 0;
}