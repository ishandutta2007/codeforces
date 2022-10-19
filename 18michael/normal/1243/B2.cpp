#include<bits/stdc++.h>
using namespace std;
int n,Test_num,ok,ok1;
int cnt[26];
char s1[52],s2[52];
typedef pair<int,int> P;
vector<P> ans;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),scanf("%s%s",s1+1,s2+1),memset(cnt,0,sizeof(cnt)),ok=1;
		for(int i=1;i<=n;++i)++cnt[s1[i]-'a'],++cnt[s2[i]-'a'];
		for(int i=0;i<26;++i)if(cnt[i]&1){ok=0;break;}
		if(!ok)
		{
			puts("No");
			continue;
		}
		puts("Yes"),ans.clear();
		for(int i=1;i<n;++i)
		{
			ok1=0;
			for(int j=i+1;j<=n;++j)
				if(s1[j]==s1[i])
				{
					swap(s2[i],s1[j]),ans.push_back(P(j,i)),ok1=1;
					break;
				}
			if(ok1)continue;
			for(int j=i+1;j<=n;++j)
				if(s2[j]==s1[i])
				{
					swap(s2[j],s1[j]),swap(s2[i],s1[j]),ans.push_back(P(j,j)),ans.push_back(P(j,i));
					break;
				}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();++i)printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}