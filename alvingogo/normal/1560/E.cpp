#include <iostream>
#include <cmath>
#include <cstring>
#define fastio cin.tie(0);ios_base::sync_with_stdio(0);
using namespace std;

int main(){
	fastio;
	int t;
	cin >> t;
	while(t--){
		string s,a="$";
		int x[26]={0},b[26]={0};
		
		cin >> s;
		int l=s.length();
		for(int i=l-1;i>=0;i--){
			if(x[s[i]-'a']==0){
				a+=s[i];
			}
			x[s[i]-'a']++;
		}
		int l2=a.length(),ans=0,flag=0;
		for(int i=1;i<l2;i++){
			if(x[a[i]-'a']%(l2-i)!=0){
				flag=1;
			}
			x[a[i]-'a']/=(l2-i);
			ans+=x[a[i]-'a'];
		}
		int d=0;
		//cout << ans << endl;
		
		for(int i=l2-1;i>0;i--){
			
			for(int j=0;j<ans;j++){
				//cout << j << d << endl;
				if(b[s[j]-'a']==1){
					continue;
				}
				if(s[j]!=s[d]){
					
					flag=1;
					break;
				}
				d++;
			}
			if(flag==1){
				break;
			}
			b[a[i]-'a']=1;	
		}
		if(flag==1){
			cout << -1 << "\n";
			continue;
		}
		for(int i=0;i<ans;i++){
			cout << s[i];
		}
		cout << " ";
		for(int i=l2-1;i>0;i--){
			cout << a[i];
		}
		cout << "\n";
	}
	return 0;
}