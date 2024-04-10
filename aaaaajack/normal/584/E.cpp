#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define N 2010
using namespace std;
int a[N],npos[N],fpos[N];
vector<int> l,r;
int main(){
	int n,x,tt=0,tl,ch;
	bool flag=true;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		npos[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		fpos[x]=i;
		tt+=abs(fpos[x]-npos[x]);
	}
	tt/=2;
	printf("%d\n",tt);
	while(1){
		for(tl=0;tl<n&&fpos[a[tl]]>=npos[a[tl]];tl++);
		if(tl==n) break;
		while(fpos[a[tl]]<npos[a[tl]]){
			for(ch=tl-1;fpos[a[ch]]==npos[a[ch]];ch--);
			l.push_back(ch);
			r.push_back(tl);
			swap(a[tl],a[ch]);
			swap(npos[a[tl]],npos[a[ch]]);
			tl=ch;
		}
	}
	printf("%d\n",(int)l.size());
	for(int i=0;i<l.size();i++){
		printf("%d %d\n",l[i]+1,r[i]+1);
	}
	return 0;
}