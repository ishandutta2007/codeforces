#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=n;i--)
const int N=5e5;
int a[N];
string s[N];
map<string,bool> M,M2;
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>s[i];
		bool tt=0;
		rep(i,1,n)
		{
			if (s[i].length()==1) tt=1;
			if (s[i].length()==2&&s[i][0]==s[i][1]) tt=1;
			if (s[i].length()==3&&s[i][0]==s[i][2]) tt=1;
	    }
	    M.clear();
	    rep(i,1,n)
	    {
	    	M[s[i]]=1;
	    	if (M[string(s[i].rbegin(),s[i].rend())]) tt=1;
	    }
	    M.clear(); M2.clear(); 
	    rep(i,1,n)
	    {
	    	if (s[i].length()==2)
	    	{
	    		if (M2[string(s[i].rbegin(),s[i].rend())]) tt=1;
	    		M[s[i]]=1;
	    	} else
	    	{
	    		if (M[string(s[i].rbegin(),prev(s[i].rend()))]) tt=1;
	    		M2[string(s[i].begin(),prev(s[i].end()))]=1;
	    	}
	    }
	    if (tt) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	return 0; 
}