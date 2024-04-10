#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+5;
string s;
int ans[MAXN];
int l,r,cnt;
int main(){
	cin>>s;
	r=s.size()-1;
	while(l<r){
		if(s[l]==s[r]){
			ans[l]=1,ans[r]=1;
			l++,r--;
		}
		else{
			if(s[l+1]==s[r])l++;
			else if(s[l]==s[r-1])r--;
			else if(s[l+1]==s[r-1])l++,r--;
			else if(s[l+2]==s[r]&&r-l>=2)l+=2;
			else if(s[l]==s[r-2]&&r-l>=2)r-=2;
		}
	}
	if(l==r)ans[l]=1;
	for(int i=0;i<s.size();i++)cnt+=ans[i];
	if(cnt>=s.size()/2)
		for(int i=0;i<s.size();i++)
			if(ans[i])
				cout<<s[i];
	return 0;
}