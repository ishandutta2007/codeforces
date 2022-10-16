#include<bits/stdc++.h>
using namespace std;
map <char,int> k;
int a,b;
char c; 
int main()
{
	k['q']=9,k['r']=5,k['b']=3,k['n']=3,k['p']=1;
	for(int i=1;i<9;i++)
		for(int j=1;j<9;j++)
			cin>>c,c<'a'?a+=k[c+32]:b+=k[c];
	if(a>b)cout<<"White";
	else if(a==b)cout<<"Draw";
	else cout<<"Black";
    return 0;
}