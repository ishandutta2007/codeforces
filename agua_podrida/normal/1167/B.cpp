#include<bits/stdc++.h>

using namespace std;

#define F1(i,n) for(int i = 1; i <= n; i++)
#define F0(i,n) for(long long i = 0; i < n; i++)
#define F first
#define S second
#define INF 1000000000
#define mod 1000000007
#define mp make_pair

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;

int main(){
	vi special = {4,8,15,16,23,42};
	vvi m(6,vi(6));
	F0(i,6) F0(j,6) m[i][j] = special[i]*special[j];
	F0(i,6) m[i][i] = -1;
	map<int,pi> mapa;
	F0(i,6) F0(j,6) mapa[m[i][j]] = mp(i,j);
	int aux;
	vi res(6);
	cout<<"? 1 2\n";
	cin>>aux;
	pi posibles = mapa[aux];
	cout<<"? 2 3\n";
	cin>>aux;
	pi posibles2 = mapa[aux];
	vi rara(6);
	rara[posibles.F]++; rara[posibles.S]++;
	rara[posibles2.F]+=2; rara[posibles2.S]+=2;
	F0(i,6) {
		if(rara[i] == 1) res[0] = i;
		if(rara[i] == 2) res[2] = i;
		if(rara[i] == 3) res[1] = i;
	}

	cout<<"? 4 5\n";
	cin>>aux;
	posibles = mapa[aux];
	cout<<"? 5 6\n";
	cin>>aux;
	posibles2 = mapa[aux];
	vi rara2(6);
	rara2[posibles.F]++; rara2[posibles.S]++;
	rara2[posibles2.F]+=2; rara2[posibles2.S]+=2;
	F0(i,6) {
		if(rara2[i] == 1) res[3] = i;
		if(rara2[i] == 2) res[5] = i;
		if(rara2[i] == 3) res[4] = i;
	}

	cout<<"! ";
	F0(i,6) cout<<special[res[i]]<<' ';
	cout<<'\n';
}