#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

string s[10],t;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>t;
    for(int i=1;i<=5;i++)
	{
		cin>>s[i];
		if(s[i][0]==t[0] || s[i][1]==t[1])
			return 0*printf("YES\n");
	}
	printf("NO\n");
    return 0;
}