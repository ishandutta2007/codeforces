#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int T;
int n,len;
char s[N];
int f[N<<1];
char s1[N<<1];

void Manacher(){
	int R=0;
    int p=0;
    s1[0]='?';
    s1[++R]='#';
    for(int i=1;i<=n;++i){
        s1[++R]=s[i];
        s1[++R]='#';
    }
    s1[++R]='!';
    for(int i=1;i<=R;++i){
        if(f[p]+p>i)f[i]=min(f[p]+p-i,f[p*2-i]);
        else f[i]=1;
        while(s1[i-f[i]]==s1[i+f[i]])f[i]++;
        if(i+f[i]>p+f[p])p=i;
    }
}

bool check(int m,bool flag){
	for(int i=0;i<=m;++i){
		int R=m-i;
		if(min(i,R)>len)continue;
		int l,r;
		if(i>R)l=R+1,r=i;
		else l=n-R+1,r=n-i;
		if(f[l+r]*2-1>=2*r-2*l+3){
			if(flag){
				for(int j=1;j<=i;++j)printf("%c",s[j]);
				for(int j=n-R+1;j<=n;++j)printf("%c",s[j]);
				printf("\n");
			}
			return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		Manacher();
		len=0;
		while(len<n/2&&s[len+1]==s[n-len])len++;
		int ans=len*2;
		for(int i=len*2+2;i<=n*2-len*2;++i){
			int Len=min(i-len*2-1,n*2-len*2-i+1);
			if(f[i]>=Len){
				if(i%2==0)ans=max(ans,len*2+Len);
				else ans=max(ans,len*2+Len);
			}
		}
		check(ans,1);
	}
}