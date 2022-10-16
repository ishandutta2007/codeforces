#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) (int(x.size()))
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

int main(){
    int T=read();
    while(T--){
        int c=read(),d=read();
        if((c+d)&1)puts("-1");
        else if(c==0&&d==0)puts("0");
        else if(c==d||c+d==0)puts("1");
        else puts("2");
    }
}