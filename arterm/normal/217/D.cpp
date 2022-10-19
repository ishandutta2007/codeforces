#include <iostream>

#define M 77
#define p 1000000007
#define long unsigned long long
#define K 31

using namespace std;

long m, a[M], c=1,pow[M],UM,UR,SM,SR;

void pre(void){
    pow[0]=1;
    SM=m/2;
    SR=m-SM;
    for (int i=1; i<M; ++i)
    pow[i]=pow[i-1]<<1;
    UM=pow[SM]-1;
    UR=pow[SR]-1;
}

void dfs(long d, long l, long ans, long ma, long ra){
	for (long i=l; i<=m/2; ++i)
	if ((ma&pow[i-1])==0){
		c=(c+a[i]*ans)%p;
		if (d<6){
			long ma1=ma|(ma>>i)|(ra<<(SR-i))|(ma<<i)|(ra>>(SR-i));
			long ra1=ra|(ma<<(SM-i))|(ra>>i)|(ma>>(SM-i))|(ra<<i);
			ma1&=UM;
			ra1&=UR;
			dfs(d+1,i+1,(ans*a[i])%p,ma1,ra1);
		}
	}
}

void read(void){
    long k,t;
    cin>>k>>m>>k;
    for (long i=0; i<k; ++i){
        cin>>t;
        t%=m;
        ++a[min(t,(m-t))];
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    read();
    pre();
    dfs(1,1,1,0,pow[SR-1]);
    cout<<c<<"\n";
    return 0;
}