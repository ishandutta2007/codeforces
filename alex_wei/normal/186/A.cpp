#include<bits/stdc++.h>
using namespace std;
string a,b;
int c[26],d[26],t; 
int main()
{
	cin>>a>>b;
	if(a.size()!=b.size())cout<<"NO",exit(0);
	for(int i=0;i<a.size();i++){
		c[a[i]-'a']++;
		d[b[i]-'a']++;
		if(a[i]!=b[i])t++;
	}
	if(t!=0&&t!=2)cout<<"NO",exit(0);
	if(t==0){
		for(int i=0;i<26;i++)
			if(c[i]>1)cout<<"YES",exit(0);
		cout<<"NO";
	}
	else{
		int x=-1,y;
		for(int i=0;i<a.size();i++)
			if(a[i]!=b[i]){
				if(x==-1)x=i;
				else y=i;
			}
		if(a[x]!=b[y]||a[y]!=b[x])cout<<"NO";
		else cout<<"YES";
	}
    return 0;
}