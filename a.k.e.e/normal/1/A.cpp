#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	#endif
    int n,m,a;
    cin>>n>>m>>a;
    cout<<(ll)((n-1)/a+1)*((m-1)/a+1)<<endl;
    return 0;
}