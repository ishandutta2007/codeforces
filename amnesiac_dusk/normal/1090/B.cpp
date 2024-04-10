/*
 * 	Roses are red
 * 		Violets are blue
 * 			I cried
 * 				And so did you
*/
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#ifndef rd
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define double long double
#define pii pair<int,int>
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define all(con) con.begin(),con.end()
#define deb cout<<"Line: "<<__LINE__<<" plz "
typedef long long ll;
const ll inf=1e18;
const ll mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll powm(ll a, ll b, ll m);

map<string,int> hola;
vector<string> tola;
vector<string> lol;
string lolp[100001];
bool cmp(string &a,string &b)
{
	return hola[a]>hola[b];
}
void solve()
{
	string str;
	int refer=0,ct=0;
	while(getline(cin,str))
	{
		if(str[0]==92&&str[1]=='b'&&str[2]=='i')
		{
			tola.pb(str);
		}
		else if(str[0]!=92||(str[1]!='e'&&str[1]!='b'))
		{
			lol.pb(str);
			for(int i=0; i<str.length(); i++)
			{
				if(str[i]==92)
				{
					int j=i+6;
					for(j=i+6; j<str.length(); j++)
						if(str[j]=='}')
							break;
					hola[str.substr(i+6, j-i-6)]=refer;
					refer++;
				}
			}
		}
	}
	for(int i=0; i<tola.size(); i++)
	{
		int k=9,j;
		for(j=0; j<tola[i].length(); j++)
			if(tola[i][j]=='}')
				break;
//		cout<<hola[tola[i].substr(k,j-k)]<<endl;
		if((hola[tola[i].substr(k,j-k)]!=i))
		{
			cout<<"Incorrect"<<endl;
//			sort(all(tola),cmp);
			cout<<"\\begin{thebibliography}{99}"<<endl;
			for(auto &te:tola)
			{
				int kk=9,jj;
				for(jj=0; jj<te.length(); jj++)
				{
					if(te[jj]=='}')
						break;
				}
				lolp[hola[te.substr(kk, jj-kk)]]=te;
//				cout<<te<<endl;
			}
			for(int i=0; i<refer; i++)
				if(lolp[i].size())
					cout<<lolp[i]<<endl;
			cout<<"\\end{thebibliography}"<<endl;
			return;
		}
	}
	cout<<"Correct"<<endl;
}
signed main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::steady_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=1;
//	auto clk=clock();
//	cin>>t;
	while(t--)
		solve();
//#ifdef rd
//	clk=clock()-clk;
//	cout<<endl<<endl<< "Time Elapsed: " << ((double)clk)/CLOCKS_PER_SEC <<endl;
//#endif
	return 0;
}
ll powm(ll a,ll b, ll m) {
	ll te=1;
	while(b) {
		if(b&1) te=(te*a)%m;
		a=(a*a)%m;
		b>>=1;
	}
	return te;
}