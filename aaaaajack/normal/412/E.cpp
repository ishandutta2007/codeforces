#include<cstdio>
#include<cctype>
using namespace std;
char s[1001000];
int main(){
	int i,pre=0,post=0,step=0,temp=0,temp2=0;
	long long ans=0;
	scanf("%s",s);
	for(i=0;s[i];i++){
		if(isalpha(s[i])){
			if(step==0) pre++;
			else temp++;
			if(step==2) post++;
			if(step==1) temp2++;
		}
		else if(isdigit(s[i])){
			if(step==2){
				step=0;
				ans+=1LL*pre*post;
				pre=temp;
			}
			if(step==1) temp2++;
		}
		else if(s[i]=='_'){
			if(step==2){
				ans+=1LL*pre*post;
				pre=temp;
			}
			else if(step==1){
				pre=temp;
			}
			step=0;
		}
		else if(s[i]=='@'){
			if(step==2){
				ans+=1LL*pre*post;
				pre=temp;
			}
			else if(step==1) pre=temp;
			step=1;
			temp=0;
			temp2=0;
		}
		else if(s[i]=='.'){
			if(step==2){
				ans+=1LL*pre*post;
				step=0;
				pre=0;
			}
			else if(step==1){
				if(temp2>0){
					step=2;
					post=0;
					temp=0;
				}
				else{
					step=0;
					pre=0;
				}
			}
			else{
				pre=0;
			}
		}
	}
	if(step==2) ans+=1LL*pre*post;
	printf("%I64d\n",ans);
	return 0;
}