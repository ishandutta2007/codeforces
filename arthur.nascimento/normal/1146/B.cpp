#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300300
#define bs bitset<maxn>
#define debug
#define pb push_back
#define pii pair<int,int>
char str[maxn];
char s2[maxn];
int main(){
	
	scanf(" %s",str);
	int n = strlen(str);
	
	int t = 0;
	
	for(int i=0;i<n;i++)
		if(str[i] != 'a') t++;
		
	int bad = 0;
	if(t%2){
	bad = 1;
		printf(":(\n");return 0;
	}
	
	int c = 0;
	for(int i=0;i<n-t/2;i++)
		if(str[i] != 'a') s2[c++] = str[i];
		
	if(c != t/2) bad = 1;
		
	for(int i=n-t/2;i<n;i++)
		if(str[i] == 'a') bad = 1;
		
	for(int i=0;i<t/2;i++)
		if(s2[i] != str[n-t/2+i]) bad = 1;
		
	if(bad){
		printf(":(\n");return 0;
	}
	
	for(int i=0;i<n-t/2;i++)
		printf("%c",str[i]);
}