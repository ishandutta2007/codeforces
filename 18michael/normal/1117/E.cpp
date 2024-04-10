#include<cstdio>
#include<cstring>
int n;
int num[10002]={},to[10002];
char s[5][10002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	scanf("%s",s[0]),n=strlen(s[0]);
	for(int i=0;i<n;++i)s[1][i]='a'+(i%26),s[2][i]='a'+((i/26)%26),s[3][i]='a'+((i/26/26)%26);
	printf("? %s\n",s[1]),fflush(stdout),scanf("%s",s[4]);for(int i=0;i<n;++i)num[i]+=s[4][i]-'a';
	printf("? %s\n",s[2]),fflush(stdout),scanf("%s",s[4]);for(int i=0;i<n;++i)num[i]+=(s[4][i]-'a')*26;
	printf("? %s\n",s[3]),fflush(stdout),scanf("%s",s[4]);for(int i=0;i<n;++i)num[i]+=(s[4][i]-'a')*26*26;
	for(int i=0;i<n;++i)to[num[i]]=i;printf("! ");for(int i=0;i<n;++i)printf("%c",s[0][to[i]]);fflush(stdout);
	return 0;
}