#include <stdio.h>
#include <stdlib.h>

int n,k,b[233333],r[233333],o[233333],w[233333],rn,on,wn;
char s[233333];

int comp(const void* a,const void* b) {
	int arg1=*(int*)(a);
	int arg2=*(int*)(b);
	if(arg1 < arg2) return -1;
	if(arg1 > arg2) return 1;
    return 0;
}

void wqsb() {
	puts("-1");
	exit(0);
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) {
		scanf("%d",&b[i]);
	}
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) {
		if(s[i]=='R') r[++rn]=b[i];
		else if(s[i]=='O') o[++on]=b[i];
		else if(s[i]=='W') w[++wn]=b[i];
	}
	if(on==0||k==1||rn+wn==0) wqsb();
	if((rn+on<k)&&(wn+on<k)) wqsb();
	qsort(r+1,rn,sizeof(int),comp);
	qsort(o+1,on,sizeof(int),comp);
	qsort(w+1,wn,sizeof(int),comp);
	int ans=0,tmp=0,oo=on,ww=wn,rr=rn;
	if(rn+oo>=k) {
		for(int cnt=1;cnt<k;++cnt) {
			if((r[rn]>o[on]&&rn)||!on) ans+=r[rn--];
			else ans+=o[on--];
		}
		if(rn==rr) ans+=r[rn--]; else if(on==oo) ans+=o[on--];
		else {
			if((r[rn]>o[on]&&rn)||!on) ans+=r[rn--];
			else ans+=o[on--];
		}
	}
	if(wn+oo>=k) {
		on=oo;
		for(int cnt=1;cnt<k;++cnt) {
			if((w[wn]>o[on]&&wn)||!on) tmp+=w[wn--];
			else tmp+=o[on--];
		}
		if(wn==ww) tmp+=w[wn--]; else if(on==oo) tmp+=o[on--];
		else {
			if((w[wn]>o[on]&&wn)||!on) tmp+=w[wn--];
			else tmp+=o[on--];
		}
	}
	if(tmp>ans) ans=tmp;
	printf("%d\n",ans);
	return 0;
}