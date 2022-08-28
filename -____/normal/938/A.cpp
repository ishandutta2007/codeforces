//CF 938A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
bool isv(char c){
	return c=='a'||c=='e'||c=='y'||c=='i'||c=='o'||c=='u';
}
int main()
{
	int n,i;
	char ch[111];
	cin>>n>>ch;
	for(i=0;i<n;i=i+1){
		if(!isv(ch[i]))
			cout<<ch[i];
		else{
			if(!i)
				cout<<ch[i];
			else
				if(!isv(ch[i-1]))
					cout<<ch[i];
		}
	}
	return 0;
}