#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define x first
#define y second
void chkmax(int &x,int y){x<y?x=y:0;}
void chkmin(int &x,int y){x>y?x=y:0;}
const int MAXN=31;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int T;
    cin>>T;
    while(T--)
    {
    	int n,a,b;
    	cin>>a>>b>>n;
    	if(n%3==0)cout<<a<<endl;
    	else if(n%3==1)cout<<b<<endl;
    	else cout<<(a^b)<<endl;
    }
    return 0;
}