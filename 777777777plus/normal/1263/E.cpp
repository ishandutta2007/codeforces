#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n;
int a[N],b[N],mna[N],mnb[N],mxa[N],mxb[N];
int ca=1,cb=1e6;
char s[N];

int main(){
	scanf("%d%s",&n,s);
	int p=0;
	mna[0]=mnb[cb]=1e9;
	for(int i=0;i<n;++i){
		if(s[i]=='L'){
			if(ca!=1){
				int det=a[ca]-a[ca-1];
				a[ca]=0;
				b[cb+1]=det+b[cb];
				--ca;
				++cb;
				mxb[cb]=max(mxb[cb-1],b[cb]);
				mnb[cb]=min(mnb[cb-1],b[cb]);
			}
		}
		else if(s[i]=='R'){
			int det=b[cb]-b[cb-1];
			b[cb]=0;
			a[ca+1]=det+a[ca];
			--cb;
			++ca;
			mxa[ca]=max(mxa[ca-1],a[ca]);
			mna[ca]=min(mna[ca-1],a[ca]);
		}
		else{
			if(s[i]=='('){
				a[ca]=a[ca-1]+1;
			}
			else if(s[i]==')'){
				a[ca]=a[ca-1]-1;
			}
			else{
				a[ca]=a[ca-1];
			}
			mxa[ca]=max(mxa[ca-1],a[ca]);
			mna[ca]=min(mna[ca-1],a[ca]);
		}
		if(a[ca]+b[cb]||mna[ca]<0||mxb[cb]>0)printf("-1 ");
		else printf("%d ",max(mxa[ca],-mnb[cb]));
	}
}
/*
11
(RaRbR)L)L(
5
R)L(L
0 -1 -1 1
*/