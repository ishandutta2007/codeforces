#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6;
struct re{
  string s;
  int id;
}s[N];
bool cmp(re x,re y)
{
	return x.s<y.s;
}
int main()
{
	int n,m;
	cin>>n>>m;
	rep(i,1,n)
	{ 
	  cin>>s[i].s;
	  rep(j,0,m-1)
	    if (j%2==1) s[i].s[j]='Z'-s[i].s[j];
	  s[i].id=i;
    }
    sort(s+1,s+n+1,cmp);
    rep(i,1,n) cout<<s[i].id<<" ";
}

/*%4=0
0110
1001 */ 
//0110 1001 1001