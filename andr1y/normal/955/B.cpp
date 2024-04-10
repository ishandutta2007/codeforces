#include <bits/stdc++.h>
using namespace std;
string a;
int b[999],A=0,B=0,i;
bool c(){
	cin>>a;
	for(auto k:a)b[k]++;
	for(i=0;i<='z';i++){
		if(b[i]==1)A++,B++;
		else if(b[i]>1)A+=2,B++;
	}
	return A>=4&&B<=4;
}

int main(){cout<<(c()?"Yes":"No");}