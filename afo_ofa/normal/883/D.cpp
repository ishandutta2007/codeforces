#include<bits/stdc++.h>
using namespace std;

char s[1001000];
int n,l,r,now,ans,las,cnt,pos,p[3],t,fl,f[1001000],g[1001000];
int nex[1001000];

bool check(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	f[0]=1;
	for (int i=1;i<=n;i++){
		g[i]+=g[i-1]; f[i]|=g[i];
		if (s[i]=='.'){
			f[i]|=f[i-1];
			continue;
		}
		if (s[i]=='P'){
			if (f[i-1]){
				f[i]=1;
				g[i]++;
				g[min(n,i+now)+1]--;
			}
			continue;
		}
		if (f[i]||!f[i-1]) continue;
		pos=min(n,i+now);
		cnt=0;
		for (t=nex[i];t<=pos&&cnt<2;t=nex[t+1])
			p[++cnt]=t;
		if (!f[i]&&!cnt) return 0;
		if (cnt>=1){
			f[p[1]]=1;
		}
		if (cnt>=2){
			g[p[2]]++;
			g[min(p[1]+now,n)+1]--;
		}
	}
	return f[n];
}

void f__k(){
	int p=1,an1=0,dis1=0,an2=0,dis2=0;
	for (;s[p]!='P';p++);
	for (int i=1;i<=n;i++){
		if (s[i]!='*') continue;
		if (i<p){
			an1++;
			dis1=max(dis1,p-i);
		}else{
			an2++;
			dis2=max(dis2,i-p);
		}
	}
	if (an1<an2||an1==an2&&dis1>dis2){
		swap(an1,an2);
		swap(dis1,dis2);
	}
	cout<<an1<<' '<<dis1;
	exit(0);
}

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int t=0,food=0;
	for (int i=1;i<=n;i++){
		t+=s[i]=='P';
		food+=s[i]=='*';
	}
	if (t==1) f__k();
	nex[n+1]=n+1;
	for (int i=n;i>0;i--){
		if (s[i]=='P') nex[i]=i;
		else nex[i]=nex[i+1];
	}
	for (l=1,r=1e6;l<=r;){
		now=l+r>>1;
		if (check()){
			r=(ans=now)-1;
		}else{
			l=now+1;
		}
	}
	cout<<food<<' '<<ans;
}