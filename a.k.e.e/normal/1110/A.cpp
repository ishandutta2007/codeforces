#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int b,k,x[MAXN];

int main()
{
    int s=0;
    cin>>b>>k;
    for(int i=1;i<=k;i++)
	{
		cin>>x[i];
		s^=x[i];
	}
    if(b&1)printf((s&1)?"odd":"even");
    else printf((x[k]&1)?"odd":"even");
    return 0;
}