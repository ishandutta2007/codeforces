#include<iostream>
#include<cstring>
using namespace std;
char S1[101],S2[101];
char S[1010];
int to[101];
int main()
{
	cin>>S1>>S2;
	cin>>S+1;
	
	for(int i=0;i<26;i++)
		to[S1[i]-'a']=i;
	int n=strlen(S+1);
	for(int i=1;i<=n;i++)
	{
		if('a'<=S[i]&&S[i]<='z')
			cout<<S2[to[S[i]-'a']];
		else if('A'<=S[i]&&S[i]<='Z')
			cout<<char(S2[to[S[i]-'A']]+'A'-'a');
		else
			cout<<S[i];
	}
	cout<<endl;
	return 0;
}