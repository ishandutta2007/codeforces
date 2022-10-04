#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

ll a,b,c;

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    cin>>a>>b>>c;
    if(a==b)cout<<a+b+c*2<<endl;
    else if(a<b)cout<<2*a+c*2+1<<endl;
    else cout<<2*b+c*2+1<<endl;
    return 0;
}