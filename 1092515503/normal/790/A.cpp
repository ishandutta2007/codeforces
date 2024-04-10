/*
Criteria:
1.read the problem carefully; WRITE DOWN SPECIAL CONSTRAINTS when the problem is long;
2.consider special situations/constraints to get observations;
3.think of everything throughout before coding;
4.return to the initial list of notifications after coding.

CONSTRAINTS:

OBSERVATIONS:

OTHER NOTIFICATIONS:

THINK CAREFULLY AND CODE DETERMINEDLY!
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,c;
string s[60],r[60],t;
int main(){
	cin>>n>>m;
	for(int i=0;i<26;i++)s[i]='A',s[i]+='a'+i;
	for(int i=0;i<26;i++)s[i+26]='B',s[i+26]+='a'+i;
	for(int i=0;i+1<m;i++)r[i]=s[c++];
	for(int i=m-1;i<n;i++){
		cin>>t;
		if(t=="YES")r[i]=s[c++];
		else r[i]=r[i-m+1];
	}
	for(int i=0;i<n;i++)cout<<r[i]<<' ';
	return 0;
}