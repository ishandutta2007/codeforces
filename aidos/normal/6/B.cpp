#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {   
char s[110][110];                                          
char c;
int minx=101, maxx=0, miny=101, maxy=0, n, m, t[30], z=0;
for(int i=0; i<28; i++) t[i]=0;
cin >> n >> m >> c;
for(int i=0; i<n; i++){
	for(int j=0; j<m; j++){
		cin >> s[i][j];
		if(s[i][j]==c){
			if(i>0 && s[i-1][j]!='.'){
				t[s[i-1][j]-'A']++;									
			}
			if(j>0 && s[i][j-1]!='.'){
				t[s[i][j-1]-'A']++;
			}
			minx = min(i, minx);
			maxx = max(i, maxx);
			miny = min(j, miny);
			maxy = max(j, maxy);
		}	
	}
}
maxy++;
maxx++;          
if(maxy<m){
	for(int i=minx; i<maxx; i++){
		if(s[i][maxy]!='.'){
			t[s[i][maxy]-'A']++;
		}
	}	
}
if(maxx<n){
	for(int i=miny; i<maxy; i++){
		if(s[maxx][i]!='.'){
			t[s[maxx][i]-'A']++;
		}
	}
}
t[c-'A'] = 0;
for(int i=0; i<26; i++) if(t[i]) z++;
cout << z;
return 0;
}