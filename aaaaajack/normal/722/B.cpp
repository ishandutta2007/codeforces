#include<bits/stdc++.h>
char s[1000];
int a[1000];
char v[10]="aeiouy";
using namespace std;
int main(){
	int n;
	bool flag=true;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	gets(s);
	for(int i=0;i<n;i++){
		gets(s);
		for(int j=0;s[j];j++){
			for(int k=0;k<6;k++){
				if(s[j]==v[k]) a[i]--;
			}
		}
		if(a[i]) flag=false;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}