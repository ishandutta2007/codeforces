#include<bits/stdc++.h>
using namespace std;
char s[200100];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		int cnt=0;
		vector<int> v,tv;
		for(int i=0;s[i];i++){
			if(s[i]=='o'){
				if(i>=2&&s[i-2]=='t'&&s[i-1]=='w') tv.push_back(i-1);
				if(s[i+1]&&s[i+2]&&s[i+1]=='n'&&s[i+2]=='e') tv.push_back(i+1);
			}
		}
		for(int i=0;i<tv.size();i++){
			//printf("%d ",tv[i]);
			if(i+1>=tv.size()||tv[i+1]>tv[i]+2) v.push_back(tv[i]); 
			else{
				v.push_back(tv[i]+1);
				i++;
			}
		}
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++){
			if(i) putchar(' ');
			printf("%d",v[i]+1);
		}
		puts("");
	}
	return 0;
}