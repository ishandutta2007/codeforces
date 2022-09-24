

#include <iostream>
#include <string>
using namespace std;
int main(){

string s;
cin >> s;
int a=0;
int b;
b=s.size();
for (int i=0;i<b-2;i++){
	if ((s[i]=='A') and (s[i+1]=='n') and (s[i+2]=='n')){
		a++;
	}
}
for (int i=0;i<b-3;i++){
	if ((s[i]=='O') and (s[i+1]=='l') and (s[i+2]=='y') and (s[i+3]=='a')){
		a++;
	}
}
for (int i=0;i<b-4;i++){
	if ((s[i]=='D') and (s[i+1]=='a') and (s[i+2]=='n') and (s[i+3]=='i') and (s[i+4]=='l')){
		a++;
	}
	if ((s[i]=='S') and (s[i+1]=='l') and (s[i+2]=='a') and (s[i+3]=='v') and (s[i+4]=='a')){
		a++;
	}
}
for (int i=0;i<b-5;i++){
	if ((s[i]=='N') and (s[i+1]=='i') and (s[i+2]=='k') and (s[i+3]=='i') and (s[i+4]=='t') and (s[i+5]=='a')){
		a++;
	}
}
if (a==1){
	cout << "YES";
}
else
{
	cout << "NO";
}
}