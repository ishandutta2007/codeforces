#include<bits/stdc++.h>
using namespace std;
char s[2010];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		k--;
		scanf("%s",s);
		vector<int> al,ar;
		for(int i=0;i<k;i++){
			if(s[i<<1]!='('){
				for(int j=(i<<1)+1;j<n;j++){
					if(s[j]=='('){
						al.push_back(i<<1);
						ar.push_back(j);
						reverse(s+(i<<1),s+j+1);
						break;
					}
				}
			}
			if(s[i<<1|1]!=')'){
				for(int j=(i+1)<<1;j<n;j++){
					if(s[j]==')'){
						al.push_back(i<<1|1);
						ar.push_back(j);
						reverse(s+(i<<1|1),s+j+1);
						break;
					}
				}
			}
		}
		for(int i=k*2;i<k+(n/2);i++){
			if(s[i]!='('){
				for(int j=i+1;j<n;j++){
					if(s[j]=='('){
						al.push_back(i);
						ar.push_back(j);
						reverse(s+i,s+j+1);
						break;
					}
				}
			}
		}
		printf("%d\n",al.size());
		for(int i=0;i<al.size();i++){
			printf("%d %d\n",al[i]+1,ar[i]+1);
		}
	}
	return 0;
}