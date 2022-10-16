#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s,t;
int main()
{
	cin>>n>>s>>t;
	for(char i='a';i<'d';i++)
		for(char j='a';j<'d';j++)
			for(char k='a';k<'d';k++)
				if(i!=j&&j!=k&&i!=k&&(s[0]!=i||s[1]!=j)&&(s[0]!=j||s[1]!=k)&&(s[0]!=k||s[1]!=i)&&
									 (t[0]!=i||t[1]!=j)&&(t[0]!=j||t[1]!=k)&&(t[0]!=k||t[1]!=i)){
									 	cout<<"YES\n";
									 	for(int l=1;l<=n;l++)
									 		cout<<i<<j<<k; 
									 	exit(0);
									 }
	for(char i='a';i<'d';i++)
		for(char j='a';j<'d';j++)
			for(char k='a';k<'d';k++)
				if(i!=j&&j!=k&&i!=k&&(s[0]!=i||s[1]!=j)&&(s[0]!=j||s[1]!=k)&&
									 (t[0]!=i||t[1]!=j)&&(t[0]!=j||t[1]!=k)){
									 	cout<<"YES\n";
									 	for(int l=1;l<=n;l++)
										 	cout<<i;
									 	for(int l=1;l<=n;l++)
										 	cout<<j;
									 	for(int l=1;l<=n;l++)
										 	cout<<k;
									 	exit(0);
									 }
	cout<<"NO";
    return 0;
}