#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll work(int x)
{
	if(x&1)return -x+x/2;
	return x/2;
}

int main()
{
	int Q,l,r;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		cout<<work(r)-work(l-1)<<endl;
	}
    return 0;
}