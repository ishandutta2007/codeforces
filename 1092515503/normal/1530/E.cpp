#include<bits/stdc++.h>
using namespace std;
int T,n,c[26],mn;
char s[100100];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),n=strlen(s);
		for(int i=0;i<26;i++)c[i]=0;
		for(int i=0;i<n;i++)c[s[i]-'a']++,s[i]=0;
		mn=n;
		for(int i=0;i<26;i++)if(c[i])mn=min(mn,c[i]);
		if(mn==1){
			for(int i=0;i<26;i++)if(c[i]==1){putchar('a'+i),c[i]--;break;}
			for(int i=0;i<26;i++)while(c[i])putchar('a'+i),c[i]--;
		}else{
			mn=0;
			while(!c[mn])mn++;
			s[0]='a'+mn,c[mn]--;
			if(c[mn]*2>n){
				if(c[mn]==n-1)for(int i=1;i<n;i++,c[mn]--)s[i]='a'+mn;
				else{
					int nm=mn+1;
					while(!c[nm])nm++;
					s[1]='a'+nm,c[nm]--;
					if(c[nm]+c[mn]==n-2){
						for(int i=2;c[nm];i++,c[nm]--)s[i]='a'+nm;
						for(int i=n-1;c[mn];i--,c[mn]--)s[i]='a'+mn;
					}else{
						int i=2;
						for(;c[mn];i++,c[mn]--)s[i]='a'+mn;
						nm++;while(!c[nm])nm++;
						s[i]='a'+nm,c[nm]--;
						for(int j=0;j<26;j++)while(c[j])s[++i]='a'+j,c[j]--;
					}
				}
			}else{
				for(int i=1;c[mn];i+=2,c[mn]--)s[i]='a'+mn;
				for(int i=0,j=0;i<26;i++)while(c[i]){
					while(s[j])j++;
					s[j]='a'+i;
					c[i]--;
				}
			}
			printf("%s",s);
		}
		putchar('\n');
		continue;
	}
	return 0;
}
/*
1
vvdddddddzz
*/