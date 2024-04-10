#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
char s[N],t[N];
vector<char> s1,s2;
char st1[N],st2[N];
int top1=0,top2=0;
int main()
{
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    while (T--)
    {
        cin>>s>>t;
        int n=strlen(s),m=strlen(t);
        int c[4]={0,0,0,0};
        for (int i=0;i<n;i++)
          c[s[i]-'A']++;
        for (int i=0;i<m;i++)
          c[t[i]-'A']--;
        if (c[0]%2==0&&c[1]%2==0&&c[2]%2==0)
        {
        	top1=top2=0;
        	int now=0,cnt=0; char cc;
        	for (int i=0;i<n;i++)
        	  if (s[i]!='B')
        	  {
        	  	st1[++top1]=s[i];
        	  	while(top1>1&&st1[top1]==st1[top1-1])top1-=2;
        	  	
        	  }
			for (int i=0;i<m;i++)
        	  if (t[i]!='B')
        	  {
        	  	st2[++top2]=t[i];
        	  	while(top2>1&&st2[top2]==st2[top2-1])top2-=2;
        	  }
        	int tag=0;
        	if(top1!=top2)tag=1;
        	for(int i=1;i<=top1;++i)if(st1[i]!=st2[i])tag=1;
            if (!tag) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        } 
		else cout<<"NO"<<endl;
    }
	return 0;
}