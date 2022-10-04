#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005,MOD=998244353;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<min(a*3+3,min(b*3,c*3-3))<<endl;
	return 0;
}