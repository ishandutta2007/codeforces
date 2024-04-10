#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k,n,cnt;
string s,t;
int main()
{
	cin>>k;
	while(k--){
		cin>>n>>s>>t;
		cnt=0;
		vector <int> a1,a2;
		int ppd=0;
		for(int i=0;i<s.size();i++)
			if(s[i]!=t[i]){
				int pd=-1;
				for(int j=i+1;j<s.size();j++)
					if(s[i]==t[j])
						pd=j;
				if(pd!=-1){
					a1.push_back(pd),a1.push_back(pd);
					swap(s[pd],t[pd]);
					a2.push_back(pd),a2.push_back(i);
					swap(s[pd],t[i]);
					continue;
				}
				for(int j=i+1;j<s.size();j++)
					if(s[i]==s[j])
						pd=j;
				if(pd!=-1){
					a1.push_back(pd);
					a2.push_back(i);
					swap(t[i],s[pd]);
					continue;
				}
				else{ppd=1;break;}
			}
		if(ppd)cout<<"No\n";
		else{
			cout<<"Yes\n";
			cout<<a1.size()<<endl;
			for(int i=0;i<a1.size();i++)
				cout<<a1[i]+1<<" "<<a2[i]+1<<endl;
		}
	}
    return 0;
}