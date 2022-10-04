#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;
string s;

int main()
{
    int cnt=0;
    cin>>n>>s;
    for(int i=0;i<n;i++)
    	if(s[i]=='8')cnt++;
    cout<<min(cnt,n/11)<<endl;
    return 0;
}