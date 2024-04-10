#include<bits/stdc++.h>
#define N 100100
using namespace std;
char s[N];
void print_small(int c[]){
	for(int i=0;i<26;i++){
		while((c[i]--)>0){
			putchar('a'+i);
		}
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int c[26]={};
		scanf("%s",s);
		int n=strlen(s);
		for(int i=0;s[i];i++) c[s[i]-'a']++;
		deque<int> cl;
		char sing=0;
		for(int i=0;i<26;i++){
			if(c[i]){
				cl.push_back(i);
				if(!sing && c[i]==1){
					sing='a'+i;
				}
			}
		}
		int fst=cl.front();
		cl.pop_front();
		//same
		if(cl.empty()){
			print_small(c);
		}
		//sing_start
		else if(sing){
			putchar(sing);
			c[sing-'a']--;
			print_small(c);
		}
		else if(c[fst]-2<=n-c[fst]){
			putchar('a'+fst);
			c[fst]--;
			while(!cl.empty()&&(c[fst]--)>0){
				putchar('a'+fst);
				putchar('a'+cl.front());
				c[cl.front()]--;
				if(c[cl.front()]==0) cl.pop_front();
			}
			print_small(c);
		}
		else{
			//ab
			int scd=cl.front();
			cl.pop_front();
			putchar('a'+fst);
			c[fst]--;
			putchar('a'+scd);
			c[scd]--;
			//aba*c+else
			if(!cl.empty()){
				while((c[fst]--)>0) putchar('a'+fst);
				putchar('a'+cl.front());
				c[cl.front()]--;
				print_small(c);
			}
			//ab*a*
			else{
				while((c[scd]--)>0) putchar('a'+scd);
				print_small(c);
			}
		}
	}
	return 0;
}