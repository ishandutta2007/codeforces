#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll n,m,a,b;

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>n>>m>>a>>b;
    if(!(n%m))
	{
		printf("0\n");
    	return 0;
    }
    ll L=(n/m)*m,R=(n/m+1)*m;
    cout<<min((n-L)*b,(R-n)*a)<<endl;
    return 0;
}