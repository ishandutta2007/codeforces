#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
typedef long long lli;

int n,t;
char s1[100001],s2[100001];

int main() {
	scanf("%d%d",&n,&t);
	scanf("%s%s",s1,s2);

	int cnt=0;
	for(int i=0;i<n;i++) if(s1[i]!=s2[i]) cnt++;
	//if(cnt&1 || cnt/2>t) { puts("-1"); return 0;}

	int sa,sd,da,dd;
	int al=n-cnt,be=cnt,nn=t-cnt/2;
	if(n-t <= al) {
		sa=n-t, sd=al-sa, da=0, dd=cnt;
	} else if((n-t-al)*2 > cnt) {
		puts("-1"); return 0;
	}else {
		sa=al, sd=0, da=(n-t-al)*2, dd=t;
	}
	for(int i=0;i<n;i++) {
		if(s1[i]==s2[i]) {
			if(sa) printf("%c",s1[i]),sa--;
			else printf("%c",s1[i]=='a' ? 'b' : 'a');
		} else {
			if(da) {
				if(da&1) printf("%c",s1[i]);
				else printf("%c",s2[i]);
				da--;
			} else {
				for(int j=0;j<26;j++) if(s1[i]-'a'!=j && s2[i]-'a'!=j){
					printf("%c",j+'a'); break;
				}
			}
		}
	}
	
	return 0;
}