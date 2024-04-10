#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < int(b); ++i)
const int mx = 1e5+3;
int main(){
	int n,t;
	scanf("%d%d",&n,&t);
	char s1[mx], s2[mx], s3[mx];
	scanf(" %s %s ",s1,s2);
	int d1 = n, d2 = n;
	rep(i,0,n)
		s3[i] = (s1[i] != 'a' && s2[i] != 'a') ? 'a' : (s1[i] != 'b' && s2[i] != 'b') ? 'b' : 'c';
	rep(i,0,n){
		if(d1 == t) break;
		if(s1[i] == s2[i]){
			s3[i] = s1[i];
			--d1;
			--d2;
		}
	}
	rep(i,0,n){
		if(s1[i] != s2[i]){
			if(d1 > t){
				--d1;
				s3[i] = s1[i];
			} else if(d2 > t){
				--d2;
				s3[i] = s2[i];
			}
		}
	}
	if(d1 != t || d2 != t){
		puts("-1");
		return 0;
	}

	rep(i,0,n) printf("%c", s3[i]);
	puts("");
}