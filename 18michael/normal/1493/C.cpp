#include<cstdio>
int Test_num,n,k,t,ok;
int cnt[26];
char s[100002];
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d%s",&n,&k,s+1),t=0;
		if(n%k){puts("-1");continue;}
		for(int i=0;i<26;++i)cnt[i]=0;
		for(int i=1;i<=n;++i)cnt[s[i]-'a']=(cnt[s[i]-'a']+k-1)%k;
		for(int i=0;i<26;++i)t+=cnt[i];
		if(!t){printf("%s\n",s+1);continue;}
		for(int i=n;~i;--i)
		{
			t-=cnt[s[i]-'a'],t+=((++cnt[s[i]-'a'])%=k),ok=26;
			if(s[i]=='z')continue;
			for(int k=s[i]-'a'+1;k<26;++k)if(cnt[k]){ok=k;break;}
			if(i-1+(ok==26)*k+t<=n)
			{
				if(ok<26 && !cnt[s[i]-'a'+1] && i-1+k+t<=n)ok=26;
				if(ok==26)cnt[s[i]-'a'+1]=k;cnt[0]+=n-(i-1+(ok==26)*k+t);
				for(int j=1;j<i;++j)printf("%c",s[j]);
				if(cnt[s[i]-'a'+1])printf("%c",s[i]+1),--cnt[s[i]-'a'+1];
				else printf("%c",ok+'a'),--cnt[ok];
				for(int j=0;j<26;++j)while(cnt[j])printf("%c",j+'a'),--cnt[j];
				puts("");break;
			}
		}
	}
	return 0;
}