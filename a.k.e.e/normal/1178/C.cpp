#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int w,h;
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=(ll)x*x%MOD)
		if(y&1)ans=(ll)ans*x%MOD;
	return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>w>>h;
    cout<<qmi(2,w+h)<<endl;
    return 0;
}