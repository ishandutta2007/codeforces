#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[1010];
	scanf("%s",s);
	int n=strlen(s);
	int l=0,r=n-1;
	vector<int> now;
	while(l<r&&l<n&&r>=0){
		while(r>=0&&s[r]!=')') r--;
		while(l<n&&s[l]!='(') l++;
		if(l<r&&l<n&&r>=0){
			now.push_back(l+1);
			now.push_back(r+1);
			l++;
			r--;
		}
		//printf("%d %d\n",l,r);
	}
	if(now.empty()) puts("0");
	else{
		puts("1");
		sort(now.begin(),now.end());
		printf("%d\n",now.size());
		for(int i=0;i<now.size();i++){
			printf("%d%c",now[i],i+1==now.size()?'\n':' ');
		}
	}
	return 0;
}