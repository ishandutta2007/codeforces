#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n;
double ans;
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		ans+=1.0/i;
	}
	printf("%.5lf\n",ans);
	return 0;
}