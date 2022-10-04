#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define enum(i,x,y) for(int i=(x);i<=(y);++i)
#define try(i,x,y) for(int i=(x);i>=(y);--i)
inline void chkmax(int &x,int y){x<y?x=y:0;}
inline void chkmin(int &x,int y){x>y?x=y:0;}
int readint()
{
    int x=0;char c;
    for(c=getchar();!isdigit(c);c=getchar());
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    return x;
}
const int MAXN=305;

int b,g,n;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
	#endif
	cin>>b>>g>>n;
	chkmin(b,n);
	chkmin(g,n);
	cout<<b+g-n+1<<endl;
    return 0;
}