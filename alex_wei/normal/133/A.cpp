#include<bits/stdc++.h>
using namespace std;
char s;
int main()
{
	while((s=getchar())&&s!=EOF)if(s=='H'||s=='Q'||s=='9')cout<<"YES",exit(0);
	cout<<"NO";
	return 0;
}