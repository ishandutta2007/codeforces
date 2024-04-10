#include<cmath>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;
int main()
{
 	string s;
 	cin>>s;
 	set<char> st;
 	int i;
 	for(i=0;i<s.size();i++)st.insert(s[i]);
 	if(st.size()%2)cout<<"IGNORE HIM!"<<endl;
 	else cout<<"CHAT WITH HER!"<<endl;
	//system("pause");
	//return 0;
}