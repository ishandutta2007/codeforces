#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2000005;

int n,s[N],fail[N],ch[N][26],len[N],sz,last,id[N];
char str[N/2];

int find(int x)
{
	if (s[x]==x) return x;
	else return s[x]=find(s[x]);
}

void extend(int n,int c)
{
    int p=last;
    while (s[n-len[p]-1]!=s[n]) p=fail[p];
    if (!ch[p][c])
    {
        int now=++sz,k=fail[p];len[now]=len[p]+2;
        while (s[n-len[k]-1]!=s[n]) k=fail[k];
        fail[now]=ch[k][c];ch[p][c]=now;
    }
    last=ch[p][c];
}

int main()
{
	scanf("%d%s",&n,str+1);
	for (int i=1;i<=n;i++) str[n+i]=str[i];
	n*=2;
	for (int i=1;i<=n/2;i++) s[i*2-1]=str[i]-'a',s[i*2]=str[n/2-i+1]-'a';
	sz=1;fail[0]=1;len[1]=-1;
	reverse(s+1,s+n+1);
	s[0]=-1;
	for (int i=1;i<=n;i++)
		extend(i,s[i]),id[i]=last;
	for (int i=0;i<=sz;i++) s[i]=i;
	s[1]=0;
	for (int i=1;i<=(n/2+1)/2;i++)
	{
		int x=find(id[n-i*2+2]);
		while (x&&(len[x]>=(n/2-(i-1)*2)*2||x&&len[x]%4!=2)) s[x]=find(fail[x]),x=s[x];
		printf("%d ",len[x]%4!=2?-1:len[x]/2);
	}
	return 0;
}