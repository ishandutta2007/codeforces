#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
string p[10];
map <string,int> mp;
int main()
{
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		mp.clear();
		for(int i=0;i<n;i++)
			cin>>p[i],mp[p[i]]++;
		for(int i=0;i<n;i++)
			if(mp[p[i]]>1){
				mp[p[i]]--;
				ans++;
				for(int pos=0;pos<4;pos++){
					char ori=p[i][pos];
					int pd=0;
					for(int k=0;k<10;k++){
						p[i][pos]=k+48;
						if(!mp[p[i]]){
							pd=1;
							mp[p[i]]++;
							break;
						}
					}
					if(!pd)p[i][pos]=ori;
					else break;
				}
			}
		
		cout<<ans<<endl;
		for(int i=0;i<n;i++)
			cout<<p[i]<<endl;
	}
    return 0;
}