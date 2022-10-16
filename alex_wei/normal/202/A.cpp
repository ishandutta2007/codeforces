#include<bits/stdc++.h>
using namespace std;
string s,a[1025];
int cnt,n;
int main()
{
	cin>>s;
	n=s.size();
	for(int i=1;i<(1<<n);i++){
		string t;
		for(int j=0;j<n;j++)
			if((i>>j)&1)
				t+=s[j];
		string p=t;
		reverse(p.begin(),p.end());
		if(t==p)a[++cnt]=t;
	}
	sort(a+1,a+cnt+1);
	cout<<a[cnt];
	return 0;
}