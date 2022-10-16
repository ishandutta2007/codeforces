#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
const int inf=1e9;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}

int n,k;

//#define froggy
int b[N],a[N];

int ask(int opt,int x,int y){
    if(!opt)printf("and %lld %lld\n",x,y),fflush(stdout);
    else printf("or %lld %lld\n",x,y),fflush(stdout);
    #ifdef froggy
    if(!opt)return b[x]&b[y];
    else return b[x]|b[y];
    #else
    int z;scanf("%lld",&z);return z;
    #endif
}

signed main(){
    scanf("%lld%lld",&n,&k);
    #ifdef froggy
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    #endif
    int s1=ask(0,1,2)+ask(1,1,2);
    int s2=ask(0,2,3)+ask(1,2,3);
    int s3=ask(0,1,3)+ask(1,1,3);
    a[1]=(s1+s3-s2)/2;
    a[2]=(s1+s2-s3)/2;
    a[3]=(s2+s3-s1)/2;
    for(int i=4;i<=n;i++){
        int s=ask(0,1,i)+ask(1,1,i);
        a[i]=s-a[1];
    }
//    for(int i=1;i<=n;i++){
//        printf("a[%d]=%d\n",i,a[i]);
//    }
    sort(a+1,a+n+1);
    printf("finish %lld\n",a[k]),fflush(stdout);
    return 0;
}