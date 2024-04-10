#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,ans=0,ai=0,aj=0;
	scanf("%d",&n);
	char s[1010];
	scanf("%s",s);
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			swap(s[i],s[j]);
			int t=0,c=0,mn=0;
			for(int k=0;k<n;k++){
				if(s[k]=='(') t++;
				else t--;
				if(t<mn) mn=t;
			}
			if(t!=0) continue;
			for(int k=0;k<n;k++){
				if(s[k]=='(') t++;
					else t--;
					if(t==mn) c++;
				}
			if(c>ans){
				ans=c;
				ai=i;
				aj=j;
			}
			swap(s[i],s[j]);
		}
	}
	printf("%d\n",ans);
	printf("%d %d\n",ai+1,aj+1);
	return 0;
}