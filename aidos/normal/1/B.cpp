#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
string s;
int ss;
char b[30];
bool f(){             
for(int i=ss-1; i>1; i--)
	if(s[i]=='C') return 1;
return false;
}
void out(int n){
char c;
string tt="";
while(n>0){
int m=n%26; 
tt=b[m]+tt;
n/=26;
if(m==0) n--;
}
cout << tt;
}                   
int main () {                      
int n, i, l, t, j, k;
cin >> n;    
b[0] = 'Z';
for(int i=0; i<25; i++) b[i+1] = 'A' + i;
for(i=0; i<n; i++)
{
	cin >> s;
	ss=s.size();
	if(s[0]=='R' && s[1]>='1' && s[1] <='9' && f()){
		l=0;
		t=0;
		j=1;
        while(s[j]!='C') {
        	l = l*10 + s[j]-'0';
        	j++;
        }
        j++;
        while(j<ss) {
        	t = t*10+s[j]-'0';
        	j++;
        }
        out(t);
        cout << l << "\n";
	}
	else
	{
		j=0;
		l=0;
		t=0;
		while(s[j]>='A' && s[j]<='Z'){ 
			l=l*26+s[j]-'A'+1;
			j++;
		}
		cout << 'R';
		for( ;j<ss; j++)
			cout << s[j];
		cout << 'C' << l << "\n";
	}
}                                                  
return 0;
}