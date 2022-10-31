// I'm back ^_^
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((1010))

string s;
ll q,f[N],fr[N],maxi[191*1000],n,ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    
   	cin>>s>>q;
   	n=s.size();
   	while(q--)
   	{
   		string t,tr;
   		bool flg=0;
   		ll m;
   		cin>>t;
   		m=t.size();
   		if(m==1)continue;
   		tr=t;
   		reverse(tr.begin(),tr.end());
   		for(int i=1,j=0;i<m;i++)
   		{
   			while(t[i]!=t[j] && j)j=f[j];
   			if(t[i]==t[j])j++;
   			f[i+1]=j;
		}
		for(int i=1,j=0;i<m;i++)
   		{
   			while(tr[i]!=tr[j] && j)j=fr[j];
   			if(tr[i]==tr[j])j++;
   			fr[i+1]=j;
		}
		for(int i=0,j=0;i<n;i++)
		{
			while(t[j]!=s[i] && j)j=f[j];
			if(t[j]==s[i])j++;
			maxi[i]=max(i?maxi[i-1]:0,j);
			if(j==m)j=f[j],flg=1;
		}
		for(int i=n-1,j=0;i>=0;i--)
		{
			while(tr[j]!=s[i] && j)j=fr[j];
			if(tr[j]==s[i])j++;
			if(j==m)j=f[j],flg=1;
			if(j+maxi[i-1]>=m)flg=1;
		}
		ans+=flg;
	}
	cout<<ans;
	return 0;
}