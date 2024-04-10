#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll int64_t
#define pb push_back
#define MEM(i,j) memset(i,j,sizeof i)
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define DB(a,s,e) {for(int i=s;i<e;++i) cout << a[i] << " ";ET;}
using namespace std;

map<string,string> M;

int main()
{
	string s;
	M["great!"]="normal";
	M["great"]="normal";
	M["don't think so"]="normal";
	M["not bad"]="normal";
	M["don't touch me!"]="normal";
	M["don't touch me"]="normal";
	M["cool"]="normal";
	M["don't even"]="grumpy";
	M["are you serious?"]="grumpy";
	M["are you serious"]="grumpy";
	M["worse"]="grumpy";
	M["go die in a hole"]="grumpy";
	M["no way"]="grumpy";
	M["terrible"]="grumpy"; 
	for(int i=0;i<10;++i)
	{
		cout << i << "\n",cout << flush,getline(cin,s);
		if(M[s]!="")
			return cout << M[s] << "\n",0;
	}
	cout << "normal\n"; 
}