#include<bits/stdc++.h>
const int MAXN = 5010;
const int MAXM = 1010;
using namespace std;
int N, M;
string varname[MAXN];
string a1[MAXN];
int p1[MAXN];
string op[MAXN];
string a2[MAXN];
int p2[MAXN];
int val[MAXN];
map<string, int> M_;
int bit, no;
int calc(int _bit, int _no)
{
	int ans=0;
	bit = _bit, no = _no;
	for(int i=0; i<N; ++i)
	{
		if( op[i] =="")
			val[i] = a1[i][bit];
		else
		{
			int v1, v2;
			if(a1[i][0]=='0' || a1[i][0] =='1') v1 = a1[i][bit];
			else if (a1[i][0]=='?') v1 = no;
			else v1 = val[p1[i]];
			
			if(a2[i][0] == '0' || a2[i][0] == '1') v2 = a2[i][bit];
			else if(a2[i][0]=='?') v2 = no;
			else v2 = val[p2[i]];

			if(op[i][0] == 'A')
			{
				val[i] = v1&v2;	
			}
			else if (op[i][0] == 'O')
			{
				val[i] = v1|v2;
			}
			else if (op[i][0] == 'X')
			{
				val[i] = v1^v2;
			}
		}
		ans += val[i];
	}
	return ans;
}
int main()
{
	memset(p1, -1, sizeof(p1));
	memset(p2, -1, sizeof(p2));
	string x;
	getline(cin,x);
	stringstream a(x);
	a >> N >> M;
	for(int i=0; i<N; ++i)
	{
		string x;
		getline(cin, x);
		stringstream a(x);
		a >> varname[i] >> x >> a1[i];
		M_[varname[i]] = i;
		a >> op[i];
		if(a1[i][0]!='?' || a1[i][0] != '0' || a1[i][0] != '1')
			p1[i] = M_[a1[i]];
		if(op[i] == "") continue;
		a >> a2[i];
		if(a2[i][0] != '?' || a2[i][0] != '0' || a2[i][0] !='1')
			p2[i] = M_[a2[i]];
	}
	string ans1;
	string ans2;
	for(int i=0; i<M; ++i)
	{
		int x = calc(i,0);
		int y = calc(i,1);
		if(x==y)
		{
			ans1 += "0";
			ans2 += "0";
		}
		else if(x<y)
		{
			ans1 += "0";
			ans2 += "1";
		}
		else
		{
			ans1 += "1";
			ans2 += "0";
		}
	}
	cout << ans1 << endl << ans2;
}