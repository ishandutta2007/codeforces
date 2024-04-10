#include<cstdio>
#include<cstring>
#define N 101000
using namespace std;
char sa[N],sb[N],sc[N];
int a[26],b[26],c[26],la,lb,lc;
void build(int *x,char *s,int &l){
	scanf("%s",s);
	l=strlen(s);
	for(int i=0;s[i];i++){
		x[s[i]-'a']++;
	}
}
inline void pc(int x,char c){
	for(int i=0;i<x;i++) putchar(c);
}
int main(){
	build(a,sa,la);
	build(b,sb,lb);
	build(c,sc,lc);
	int bc=0,cc=0;
	bool wrong=false;
	for(int i=0;i<=la/lb;i++){
		int mc=1023456789,tmp[26];
		for(int j=0;j<26;j++){
			tmp[j]=a[j];
		}
		for(int j=0;j<26;j++){
			if(b[j]==0||a[j]/b[j]>=i){
				tmp[j]-=b[j]*i;
			}
			else{
				wrong=true;
				break;
			}
		}
		if(wrong) break;
		for(int j=0;j<26;j++){
			if(c[j]!=0&&tmp[j]/c[j]<mc) mc=tmp[j]/c[j];
		}
		if(i+mc>bc+cc){
			bc=i;
			cc=mc;
		}
	}
	for(int i=0;i<bc;i++) printf("%s",sb);
	for(int i=0;i<cc;i++) printf("%s",sc);
	for(int i=0;i<26;i++){
		pc(a[i]-b[i]*bc-c[i]*cc,'a'+i);
	}
	return 0;
}