#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int n, a[30], x=1;
int main () {   
for(int i=0; i<28; i++)
	a[i] = 0;
string s;
cin >> s;
for(int i=s.size()-1; i>=0; i--)
	a[s[i]-'a']++;
n = s.size();
    while(n>0){
		int z=0, k=0;
		for(int i=0; i<26; i++){
			if(a[i]!=0){
			if(a[i]%2==0) z++;
			else k++;
			}
		}		
		if(k<=1){ 
			if(x)cout << "First" ; 
			else cout << "Second" ;
			return 0;
		}
		if(z!=0){
			for(int i=0; i<26; i++)
				if(a[i]!=0 && a[i]%2==0){
					a[i]--;
					i=30;
				}						
		}
		else{
			for(int i=0; i<26; i++){
				if(a[i]!=0){
					a[i]--;
					i = 30;	
				}
			}			
		}    	
	
	x = 1-x;
	n--;              
}

return 0;
}