#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
int q,a,b,f[30];
int main() {
	//freopen("1.txt","r",stdin);
	read(q);
	f[1]=0;
	f[2]=1;
	f[3]=1;
	f[4]=5;
	f[5]=1;
	f[6]=21;
	f[7]=1;
	f[8]=85;
	f[9]=73;
	f[10]=341;
	f[11]=89;
	f[12]=1365;
	f[13]=1;
	f[14]=5461;
	f[15]=4681;
	f[16]=21845;
	f[17]=1;
	f[18]=87381;
	f[19]=1;
	f[20]=349525;
	f[21]=299593;
	f[22]=1398101;
	f[23]=178481;
	f[24]=5592405;
	f[25]=1082401;
	while (q--) {
		read(a);
		for (int i=1;i<=25;i++) {
			b=(1<<i)-1;
			if (a==b) { printf("%d\n",f[i]); break; }
			if (a<b) { printf("%d\n",b); break; }
		}
	}
	return 0;
}